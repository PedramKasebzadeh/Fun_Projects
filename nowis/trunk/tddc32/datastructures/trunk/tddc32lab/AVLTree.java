//AVL_Tree.java
//by Calin Curescu
//2006-01-3

package tddc32lab;
import java.io.*;

public class AVLTree {

	private AVLTreeNode rootNode = null;

	class AVLTreeNode {
		double value;
		private  AVLTreeNode parent = null;
		private  AVLTreeNode left = null;
		private  AVLTreeNode right = null;
		int height = 0;

		AVLTreeNode(double val) {
			value = val;
		}
		
		public String toString() {
			return "[" + value + " ; " + height +"]";
		}
	}

	@SuppressWarnings("serial")
	public class AVLTreeException extends Exception{
		AVLTreeException(String msg) {
			super (msg);
		}
	}

	//Private functions for AVLTree management:

	/**
	 * Returns true if the node is the left child of it's parent. Throws
	 * a AVLTreeException if the node is null or a rootNode.
	 */
	boolean isLeftChild(AVLTreeNode node) throws AVLTreeException {
		if(node == null) 
			throw new AVLTreeException("Error, in isLeftChild(), the node is null!");
		if(node.parent == null)
			throw new AVLTreeException("Error, the node does not have a parent");
		return (node == node.parent.left);
	}

	/**
	 * Returns a node's height. Note: works also on null (empty trees)
	 * and retuns -1 on them.
	 */
	static int getHeight(AVLTreeNode node) {
		if(node != null)
			return node.height;
		return -1;
	}

	/**
	 * Adjust the height for a node. Needs the height of the left and
	 * right subtrees to be accurate. If node = null it just
	 * returns. Returns the updated height of the node
	 */
	static void adjustHeight(AVLTreeNode node) {
		if(node == null)
			return;
		node.height = 1 + (getHeight(node.left) >  getHeight(node.right) ?
				getHeight(node.left) :  getHeight(node.right));
	}

	static AVLTreeNode tallerChild(AVLTreeNode node) {
		return (getHeight(node.left) > getHeight(node.right) ?
				node.left : node.right);
	}

	static boolean isBalanced(AVLTreeNode node) {
		if(node == null)
			return true;
		if(Math.abs(getHeight(node.left) - getHeight(node.right)) > 1)
			return false;
		return true;
	}

	/**
	 * Rebalance the tree starting from a node, and searching upwards
	 * for the imbalanced node (the z node in the lecture). Throws
	 * a AVLTreeException if node is null.
	 */
	void rebalance(AVLTreeNode node)  throws AVLTreeException {
		if (node == null) {
			throw new AVLTreeException("Error, should not  rebalance a null node");
		}
		int prevHeight = node.height;
		adjustHeight(node);

		if (!isBalanced(node))
			node = restructure(node);
		else
			if (prevHeight != node.height && node != rootNode) {
				if(node.parent == null)
					throw new AVLTreeException("Error, a non-root node does not have a parent");
				rebalance(node.parent);
			}
	}

	/**
	 * Do the trinode restructuring, imbalanced node as argument. Throws
	 * a AVLTreeException if isLeftChild() is used improperly in the
	 * node;
	 */
	AVLTreeNode restructure(AVLTreeNode zNode)  throws AVLTreeException {

		AVLTreeNode yNode = tallerChild(zNode);
		AVLTreeNode xNode = tallerChild(yNode);
		//identify a,b,c the inorder of x,y,z
		AVLTreeNode aNode = null;
		AVLTreeNode bNode = null;
		AVLTreeNode cNode = null;
		//identify subtrees T0, T1, T2, T3
		AVLTreeNode t0SubTree = null;
		AVLTreeNode t1SubTree = null;
		AVLTreeNode t2SubTree = null;
		AVLTreeNode t3SubTree = null;

		if(isLeftChild(yNode))
			if(isLeftChild(xNode)) {
				//single rotation right:
				aNode = xNode;
				bNode = yNode;
				cNode = zNode;
				t0SubTree = xNode.left;
				t1SubTree = xNode.right;
				t2SubTree = yNode.right;
				t3SubTree = zNode.right;
			}
			else {
				//double rotation left-right:
				aNode = yNode;
				bNode = xNode;
				cNode = zNode;
				t0SubTree = yNode.left;
				t1SubTree = xNode.left;
				t2SubTree = xNode.right;
				t3SubTree = zNode.right;
			}
		else
			if(isLeftChild(xNode)) {
				//double rotation right-left:
				aNode = zNode;
				bNode = xNode;
				cNode = yNode;
				t0SubTree = zNode.left;
				t1SubTree = xNode.left;
				t2SubTree = xNode.right;
				t3SubTree = yNode.right;
			}
			else {
				//single rotation left:
				aNode = zNode;
				bNode = yNode;
				cNode = xNode;
				t0SubTree = zNode.left;
				t1SubTree = yNode.left;
				t2SubTree = xNode.left;
				t3SubTree = xNode.right;
			}

		//replace zNode with bNode
		if(zNode.parent == null) {
			rootNode = bNode ;
		}
		else {
			if(isLeftChild(zNode))
				zNode.parent.left = bNode;
			else
				zNode.parent.right = bNode;
		}
		bNode.parent = zNode.parent;
		//set the other links:
		bNode.left  = aNode;
		aNode.parent = bNode;
		bNode.right = cNode;
		cNode.parent = bNode;
		aNode.left  = t0SubTree;
		if(t0SubTree != null)
			t0SubTree.parent = aNode;
		aNode.right = t1SubTree;
		if(t1SubTree != null)
			t1SubTree.parent = aNode;
		cNode.left  = t2SubTree;
		if(t2SubTree != null)
			t2SubTree.parent = cNode;
		cNode.right = t3SubTree;
		if(t3SubTree != null)
			t3SubTree.parent = cNode;
		//adjust heights:
			adjustHeight(aNode);
			adjustHeight(cNode);
			adjustHeight(bNode);

			return bNode;
	}

	/**
	 * Help function to be used by find, insert and delete. It searches
	 * for the value in the tree and returns the first occurence. If the
	 * value is not found it returns the last node in the tree, so it
	 * can be used in inserts. Returns null only when initial node is
	 * null.
	 */
	private AVLTreeNode findClosestNode(AVLTreeNode node, double val) {
		boolean found = (node == null);

		while (!found) {
			if(val < node.value) {
				if(node.left == null)
					found = true;
				else
					node = node.left;
			}
			else if(val > node.value) {
				if(node.right == null)
					found = true;
				else 
					node = node.right;
			}
			else 
				found = true;
		}
		return node;
	} 

	/**
	 * Set in value in subtree that has node as a root. Throws
	 * a AVLTreeException if there is a rebalance problem.
	 */
	void insert(AVLTreeNode node, double val)  throws AVLTreeException {
		AVLTreeNode foundNode = findClosestNode(node, val);

		if(foundNode == null) {
			rootNode = new AVLTreeNode(val);
			return;
		}

		if(foundNode.value == val) {
			System.out.println("Value already in tree");
			return;
		}

		AVLTreeNode newNode = new AVLTreeNode(val);
		newNode.parent = foundNode;

		if(val < foundNode.value)
			foundNode.left = newNode;
		else
			foundNode.right = newNode;

		rebalance(foundNode);
	}
	
	/**
	 * Delete value in subtree that has node as a root.
	 */
	void delete(AVLTreeNode node, double val)  throws AVLTreeException {
		AVLTreeNode foundNode = findClosestNode(node, val);

		if(foundNode == null || foundNode.value != val) {
			System.out.println("Value not found");
			return;
		}

		if(isLeaf(foundNode)) {
			deleteLeaf(foundNode);
		} else  {
			if(foundNode.left == null) {
				replaceNode(foundNode, foundNode.right);
			}else if(foundNode.right == null) {
				replaceNode(foundNode, foundNode.left);
			} else if(foundNode.left.height >= foundNode.right.height) {
				foundNode.value = deleteMaxLeftNode(foundNode.left);
			} else {
				foundNode.value = deleteMinRightNode(foundNode.right);
			}
		}
		
		/* if foundNode is not the root then rebalance */
		if(foundNode.parent != null)
			rebalance(foundNode.parent);
	}	

	/**
	 * Delete min node in a right tree and return it's value
	 * @param node
	 * @return value of deleted node
	 */
	// 8 7 6 9 4
	private double deleteMinRightNode(AVLTreeNode node) {
		// if left node is null, only promote right tree
		if(node.left == null) {
			node.parent.right  = node.right;
			if(node.right != null)
				node.right.parent = node.parent;
		} else { // else look deep for min value
			while(node.left != null) {
				node = node.left;
			}
			// update parent by replacing is left child by his left right child
			node.parent.left  = node.right;
			if(node.right != null)
				node.right.parent = node.parent;
		}
		
		return node.value;
	}
	/**
	 * Delete max node in a left tree and return it's value
	 * @param node
	 * @return value of deleted node
	 */
	private double deleteMaxLeftNode(AVLTreeNode node) {
		// if right node is null, only promote left tree
		if(node.right == null) {
			node.parent.left  = node.left;
			if(node.left != null)
				node.left.parent = node.parent;
		} else { // else look deep for max value	
			while(node.right != null) {
				node = node.right;
			}
			// update parent by replacing is right child by his right left child
			node.parent.right  = node.left;
			if(node.left != null)
				node.left.parent = node.parent;
		}

		return node.value;
	}

	/**
	 * verify is the parameters is a leaf or not
	 */
	public boolean isLeaf(AVLTreeNode node) {
		return node.height == 0;
	}
	
	/**
	 * delete a leaf (toDelete MUST be a leaf)
	 * @param toDelete
	 * @throws AVLTreeException 
	 */
	private void deleteLeaf(AVLTreeNode toDelete) throws AVLTreeException {
		replaceNode(toDelete, null);
	}
	
	/**
	 * replace a node by another
	 * @param node
	 * @param newNode can be null
	 */
	private void replaceNode(AVLTreeNode node, AVLTreeNode newNode) {
		try {
			if(newNode != null) {
				newNode.parent = node.parent;
			}
			
			if(isLeftChild(node))  {
				node.parent.left = newNode;
			} else {
				node.parent.right = newNode;
			}
		} catch(AVLTreeException e) {
			this.rootNode = newNode;
		}
	}

	/**
	 * Prints elements in order.
	 */
	void inorderPrint(AVLTreeNode node) {
		if(node != null) {
			inorderPrint(node.left);
			System.out.println(node.value);
			inorderPrint(node.right);
		}
	}

	/**
	 * Prints tree in ASCII art.
	 */
	void printASCII(AVLTreeNode node, String indent) {
		String indentStep = "     ";
		String indentStep2 = "  ";
		if(node != null) {

			printASCII(node.right, indent + indentStep); 

			if (node.right != null)
				System.out.println(indent + indentStep2+"/");

			System.out.println(indent + node.value);

			if (node.left != null)
				System.out.println(indent + indentStep2+"\\");

			printASCII(node.left, indent + indentStep); 
		}
	}

	/*
	 * Constructs a new empty tree.
	 */
	AVLTree() {
	}

	/**
	 * Sets the subtree starting at node as the new tree.
	 */
	AVLTree(AVLTreeNode node) {
		rootNode = node;
	}


	/*
	 * Public functions for AVLTree
	 */

	/**
	 * Set value in the tree. If it's already there it will print an
	 * error message and do nothing. Throws a AVLTreeException if there
	 * is an insert problem.
	 */
	public void insert(double val)  throws AVLTreeException {
		insert(rootNode, val); 
	}

	/**
	 * Take away value from tree. If it does not exist it will print an
	 * error message and do nothing.
	 */
	public void delete(double val) throws AVLTreeException { 
		delete(rootNode, val); 
	}

	/**
	 * Returns true if value is found in the tree.
	 */
	public boolean find(double val) {
		if(rootNode == null)
			return false;
		if(findClosestNode(rootNode,val).value == val)
			return true;
		return false;
	}

	/**
	 * Return a value from the tree. Throws
	 * a AVLTreeException if tree is empty.
	 */
	double get()  throws AVLTreeException {
		if(rootNode == null) {
			throw new AVLTreeException("The tree is empty!");
		}
		return rootNode.value;
	}

	/**
	 * Return the minimum value from the tree.  Throws a
	 * AVLTreeException if tree is empty.
	 */
	double  getMin()  throws AVLTreeException {
		if(rootNode == null) {
			throw new AVLTreeException("The tree is empty!");
		}
		return findClosestNode(rootNode,Double.NEGATIVE_INFINITY).value;
	}

	/**
	 * Return the maximum value from the tree.  Throws a
	 * AVLTreeException if tree is empty.
	 */
	double getMax()  throws AVLTreeException {
		if(rootNode == null) {
			throw new AVLTreeException("The tree is empty!");
		}
		return findClosestNode(rootNode,Double.POSITIVE_INFINITY).value;
	}

	/**
	 * Returns true if tree is empty, otherwise false.
	 */
	boolean isEmpty() {
		return rootNode == null;
	}

	/**
	 * Replaces the tree with the subtree starting at node as the new
	 * tree. 
	 */
	void setRoot(AVLTreeNode node) {
		rootNode = node;
	}

	/**
	 * Prints elements in order.
	 */
	void inorderPrint() {
		inorderPrint(rootNode);
	}

	/**
	 * Prints tree in ASCII art.
	 */
	void print() {
		System.out.println();
		printASCII(rootNode,"  ");
		System.out.println();
	}      

	/**
	 * Runs an interactive tree manipulation.
	 */
	public static void main(String[] args) {
		AVLTree tree = new AVLTree();
		BufferedReader inputReader = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 1; i <= 11; i++) {
			try {
				tree.insert(i);
			}
			catch (AVLTreeException e) {
				System.out.println("e.getMessage()");
				e.printStackTrace();
			}
		}

		System.out.println("The  print of the tree is:\n");
		tree.print();

		int  choice = -1;
		double  value;

		while (true)
		{
			System.out.println("1.  Insert");
			System.out.println("2.  Delete");
			System.out.println("3.  Search for value");
			System.out.println("4.  Search for smallest value");
			System.out.println("5.  Search for largest value");
			System.out.println("6.  Print tree inorder");
			System.out.println("7.  Print tree ");
			System.out.println("0.  Exit");

			try {
				choice = Integer.valueOf(inputReader.readLine()).intValue();

				switch (choice) {
				case 0:
					System.out.println("Exit");
					return;
				case 1:
					System.out.println("Input value: ");
					value = Double.valueOf(inputReader.readLine()).doubleValue();
					tree.insert(value);
					break;
				case 2:
					System.out.println("Value to remove: ");
					value = Double.valueOf(inputReader.readLine()).doubleValue();
					tree.delete(value);
					break;
				case 3:
					System.out.println("Value to find: ");
					value = Double.valueOf(inputReader.readLine()).doubleValue();
					if (tree.find(value))
						System.out.println("Value " + value + " found in the tree");
					else
						System.out.println("Value " + value + " not found in the tree");
					break;
				case 4:
					if (tree.isEmpty())
						System.out.println("Tree is empty!");
					else
						System.out.println("The smallest value in the tree is " + tree.getMin());
					break;
				case 5:
					if (tree.isEmpty())
						System.out.println("Tree is empty!");
					else
						System.out.println("The largest value in the tree is " + tree.getMax());
					break;
				case 6:
					if (tree.isEmpty()) 
						System.out.println("Tree is empty!");
					else {
						System.out.println("The inorder print of the tree is:");
						tree.inorderPrint();
						System.out.println();
					}
					break;
				case 7:
					if (tree.isEmpty()) 
						System.out.println("Tree is empty!");
					else { 
						System.out.println("The print of the tree is:");
						tree.print();
					}
					break;
				default:
					System.out.println("Incorrect choice");
				}
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			catch (NumberFormatException e) {
				System.out.println("Incorrect choice");
			}
			catch (AVLTreeException e) {
				System.out.println("e.getMessage()");
				e.printStackTrace();
			}
		}
	}
}
