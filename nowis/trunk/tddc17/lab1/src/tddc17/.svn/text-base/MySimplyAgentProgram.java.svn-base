package tddc17;

import java.util.LinkedList;
import java.util.Queue;

import aima.core.agent.Action;
import aima.core.agent.AgentProgram;
import aima.core.agent.Percept;
import aima.core.agent.impl.DynamicPercept;
import aima.core.agent.impl.NoOpAction;
import aima.core.environment.liuvacuum.LIUVacuumEnvironment;


public class MySimplyAgentProgram implements AgentProgram {
	private boolean nextTurnRight = true;
	private boolean leavedHome = false;
	private Queue<Action> turn = new LinkedList<Action>();

	public Action execute(Percept percept) {
		boolean bump, dirt, home;
		DynamicPercept p;

		p = (DynamicPercept) percept;
		bump = ((Boolean)p.getAttribute("bump")).booleanValue();
		dirt = ((Boolean)p.getAttribute("dirt")).booleanValue();
		home = ((Boolean)p.getAttribute("home")).booleanValue();

		if(home) {
			if(leavedHome)
				return NoOpAction.NO_OP;
			leavedHome = true;
		}

		if(dirt) {
			return LIUVacuumEnvironment.ACTION_SUCK;
		}

		if(!turn.isEmpty()) {
			if(bump) {
				turn.clear();

				turn.add(LIUVacuumEnvironment.ACTION_TURN_RIGHT);
				turn.add(LIUVacuumEnvironment.ACTION_MOVE_FORWARD);
				if(nextTurnRight) {
					nextTurnRight = false;
					turn.add(LIUVacuumEnvironment.ACTION_TURN_RIGHT);
				} else {
					nextTurnRight = true;
					turn.add(LIUVacuumEnvironment.ACTION_TURN_LEFT);
				}

				return LIUVacuumEnvironment.ACTION_TURN_RIGHT;
			}

			return turn.poll();
		} else

			if(bump) {
				turn.add(LIUVacuumEnvironment.ACTION_MOVE_FORWARD);

				if(nextTurnRight) {
					nextTurnRight = false;
					turn.add(LIUVacuumEnvironment.ACTION_TURN_RIGHT);
					turn.add(LIUVacuumEnvironment.ACTION_MOVE_FORWARD);
					return LIUVacuumEnvironment.ACTION_TURN_RIGHT;
				} else {
					nextTurnRight = true;
					turn.add(LIUVacuumEnvironment.ACTION_TURN_LEFT);
					turn.add(LIUVacuumEnvironment.ACTION_MOVE_FORWARD);
					return LIUVacuumEnvironment.ACTION_TURN_LEFT;
				}
			}

		return LIUVacuumEnvironment.ACTION_MOVE_FORWARD;
	}
}