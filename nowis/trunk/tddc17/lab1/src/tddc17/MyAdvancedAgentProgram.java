package tddc17;

import java.util.List;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import tddc17.Cell.Status;

import aima.core.agent.Action;
import aima.core.agent.AgentProgram;
import aima.core.agent.Percept;
import aima.core.agent.impl.DynamicPercept;
import aima.core.agent.impl.NoOpAction;
import aima.core.environment.liuvacuum.LIUVacuumEnvironment;

public class MyAdvancedAgentProgram implements AgentProgram {
	// Directions :  North, East, South, West
	private static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	// World
	private List<List<Cell>> world;
	private Cell home;
	private int borderNorth = 0;
	private int borderWest = 0;
	private int borderSouth = 2;
	private int borderEast = 2;

	// Agent
	private Stack<Cell> path;
	private int agentPosX = 1;
	private int agentPosY = 1;
	private int direction = 1; // note : the first direction doesn't really matter. I choose EAST for debugging purpose
;
	private boolean previouslyMovedForward = false;
	private boolean onWayHome = false;
	
	/**
	 * Initialize Vacuum Agent
	 * Particulary, create a world an unknown world of 3x3 cells with home in the center 
	 */
	public MyAdvancedAgentProgram() {
		world = new LinkedList<List<Cell>>();
		for(int i=0 ; i<3 ; i++) {
			List<Cell> line = new LinkedList<Cell>();
			line.add(new Cell(i, 0));
			line.add(new Cell(i, 1));
			line.add(new Cell(i, 2));
			world.add(line);
		}
		world.get(agentPosX).get(agentPosY).setStatus(Status.HOME);
		home = getCell(agentPosX, agentPosY);
		
		path = new Stack<Cell>();
	}
	
	/**
	 * Main agent function :
	 * 
	 * - update known world
	 * - check dirt
	 * - check if an action is in progress (moving to another unknown cell)
	 * - generate a path if no action is in progress
	 */
	public Action execute(Percept percept) {
		boolean bump, dirt, home;
		DynamicPercept p;
		Cell closestUnknownCell;
		
		p = (DynamicPercept) percept;
		bump = ((Boolean)p.getAttribute("bump")).booleanValue();
		dirt = ((Boolean)p.getAttribute("dirt")).booleanValue();
		home = ((Boolean)p.getAttribute("home")).booleanValue();

		// update world
		updateVacuumAgentCoord(bump, home);
		closestUnknownCell = updateWorld();

		System.out.println(this);
		
		// on way home ?
		if(onWayHome && home)
			return NoOpAction.NO_OP;
		
		// cleaning world
		if(dirt) {
			getCell(agentPosX, agentPosY).setStatus(Status.EMPTY);
			previouslyMovedForward = false;
			return LIUVacuumEnvironment.ACTION_SUCK;
		}

		// execute next planned action
		if(!path.isEmpty()) {
			return updateDirection(path.pop());
		}
		
		// generate a new path
		dijkstra(closestUnknownCell);
		
		// if path is empty here that mans that last unknown reachable cell was close to home 
		if(path.empty())
			return NoOpAction.NO_OP;
		
		// first action of the new path
		return updateDirection(path.pop());
	}

	/**
	 * Add the shortest path to goal to the stack "path"
	 * The stack next must be empty.
	 * if param goal is null, then the shortest path to home will be generated
	 * 
	 * This function only marks distance from start position, the function retrievePath
	 * is used to properly generate the path.
	 */
	private void dijkstra(Cell goal) {
		Queue<Cell> nexts = new LinkedList<Cell>();
		Cell start = getCell(agentPosX, agentPosY);
		
		if(goal == null) {
			onWayHome = true;
			goal = home;
		}
		
		resetExploration();
		start.setDistanceFromHome(0);
		nexts.add(start);
		while(!nexts.isEmpty()) {
			Cell c = nexts.poll();
			
			if(c.isMarked())
				continue;
			c.setMarked(true);

			if(c.equals(goal))
				break;
			
			// For each successors (North, East, South, West)
			for(int i=0 ; i<4 ; i++) {
				try {
					Cell nextCell = getCell(c.getX()+directions[i][0], c.getY()+directions[i][1]);
					if(!nextCell.isWall() && !nextCell.isMarked()) {
						nextCell.setDistanceFromHome(c.getDistanceFromHome()+1);
						nexts.add(nextCell);
					}
				} catch(IndexOutOfBoundsException e) {
				}
			}		
		}
		
		retrievePath(start, goal);
	}

	/**
	 * After the function Dijkstra marks the distance from the start position,
	 * this function will generate the path from start to goal cell.
	 */
	private void retrievePath(Cell start, Cell goal) {
		Cell current = goal;

		path.push(goal);
		while(!current.equals(start)) {
			for(int i=0 ; i<directions.length ; i++) {
				try {
					Cell nextCell = getCell(current.getX()+directions[i][0], current.getY()+directions[i][1]);
					if(nextCell.getDistanceFromHome() == (current.getDistanceFromHome() - 1)) {
						current = nextCell;
						path.push(current);
						break;
					}
				} catch(IndexOutOfBoundsException e) {
				}
			}
		}
		
		// remove start position from the path
		path.pop();
	}

	/**
	 * This function return the action the agent have to take to reach the "next" cell.
	 * next must be adjacent to the current agent position.
	 */
	private Action updateDirection(Cell next) {
		// search the new direction
		int newDirection = 0;
		for(int i=0 ; i<4 ; i++) {
			try {
				Cell nextCell = getCell(agentPosX+directions[i][0], agentPosY+directions[i][1]);

				if(nextCell.equals(next)) {
					newDirection = i;
					break;
				}
			} catch(IndexOutOfBoundsException e) {
			}
		}
		
		// compare if the agent is in the right direction
		if(direction == newDirection) {
			previouslyMovedForward = true;
			return LIUVacuumEnvironment.ACTION_MOVE_FORWARD;
		}
		
		// We have to turn first
		previouslyMovedForward = false;
		path.push(next);
		
		if(turnRight(newDirection)) {
			direction = (direction + 1) % 4; 
			return LIUVacuumEnvironment.ACTION_TURN_RIGHT;
		}
		
		direction = (--direction) < 0 ? 3 : direction;
		return LIUVacuumEnvironment.ACTION_TURN_LEFT;
	}

	/**
	 * Check if we have to turn right (return true) or left (return false)
	 */
	private boolean turnRight(int newDirection) {
		return (newDirection - direction) > 0;
	}

	/**
	 * update vacuum agent coordinates
	 */
	private void updateVacuumAgentCoord(boolean bump, boolean home) {	
		int x = agentPosX + directions[direction][0];
		int y = agentPosY + directions[direction][1];
		
		if(previouslyMovedForward) {
			if(bump) {
				getCell(x, y).setStatus(Status.WALL);
			}else {
				if(!home)
					getCell(x, y).setStatus(Status.EMPTY);
				agentPosX = x;
				agentPosY = y;
				enlargeWorld();
			}
		}
	}

	/**
	 * Enlarge the world if the border of known world have been reached
	 */
	private void enlargeWorld() {
		if(agentPosY == borderWest) {
			borderWest--;
			for(int i=0 ; i<world.size() ; i++) {
				List<Cell> line = world.get(i);
				line.add(0, new Cell(i, borderWest));
			}
		}
		
		if(agentPosY == borderEast) {
			borderEast++;
			for(int i=0 ; i<world.size() ; i++) {
				List<Cell> line = world.get(i);
				line.add(new Cell(i, borderEast));
			}
		}
		
		if(agentPosX == borderNorth) {
			borderNorth--;
			List<Cell> newLine = new LinkedList<Cell>();
			for(int i=0 ; i<world.get(0).size() ; i++)
				newLine.add(new Cell(borderNorth, i));
			world.add(0, newLine);
		}
		
		if(agentPosX == borderSouth) {
			borderSouth++;
			List<Cell> newLine = new LinkedList<Cell>();
			for(int i=0 ; i<world.get(0).size() ; i++)
				newLine.add(new Cell(borderSouth, i));
			world.add(newLine);
		}
	}

	/**
	 * return the Cell at coordinate (x,y)
	 */
	private Cell getCell(int x, int y) throws IndexOutOfBoundsException {
		return world.get(x-borderWest).get(y-borderNorth);
	}
	
	/**
	 * Search the strongly connected component an replace unreachable cells by walls
	 * Starting algorithm at vacuum agent position
	 */
	private Cell updateWorld() {
		Cell closestUnknownCell = null;
		Queue<Cell> next = new LinkedList<Cell>();
		
		resetExploration();
		next.add(getCell(agentPosX, agentPosY));
		while(!next.isEmpty()) {
			Cell c = next.poll();
			if(c.isMarked())
				continue;
			c.setMarked(true);

			if(closestUnknownCell == null && c.isUnknown()) {
				closestUnknownCell = c;
			}
			
			// For each successors (North, East, South, West)
			for(int i=0 ; i<directions.length ; i++) {
				try {
					Cell nextCell = getCell(c.getX()+directions[i][0], c.getY()+directions[i][1]);
					if(!nextCell.isWall() && !nextCell.isMarked())
						next.add(nextCell);
				} catch(IndexOutOfBoundsException e) {
				}
			}
		}
		
		// replace unreachable cells by walls
		for(List<Cell> line : world) {
			for(Cell c : line) {
				if(!c.isMarked())
					c.setStatus(Status.WALL);
			}
		}		
	
		return closestUnknownCell;
	}

	/**
	 * Reset marking of all cells
	 */
	private void resetExploration() {
		for(List<Cell> line : world) {
			for(Cell c : line) {
				c.setDistanceFromHome(-1);
				c.setMarked(false);
			}
		}
	}
	
	/**
	 * Print how the vacuum agent currently see the world
	 */
	public String toString() {
		String result = "";
		for(List<Cell> line : world) {
			for(Cell c : line)
				result += " [" + c + "]";
			result += "\n";
		}
		return result;
	}
}
