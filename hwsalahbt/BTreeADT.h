#pragma once
#include "BTreeNode.h"
#include <iostream>
typedef int KIND;
#define MAX(A, B) ((A > B) ? A : B)
class BTreeADT
{
private:
	BTreeNode *root;							   // tree root
	void resetTree(BTreeNode *);				   // will destroy the whole node
	bool isEmpty();								   // check the tree
	void preOrder(BTreeNode *);					   // preorder traversal
	void postOrder(BTreeNode *);				   // postorder traversal
	void inOrder(BTreeNode *);					   // inorder traversal
	void levelOrder(BTreeNode *);				   // level order traversal
	void insertl(BTreeNode *v, string a[], int i); // adding with me
	bool isParent(BTreeNode *v);				   //
	bool isParentf(BTreeNode *v) { return (v->getLeft() != NULL && v->getRight() != NULL); }

public:
	// Only as a choice for the user or we can define it as an enumeration
	const static int PREORDER = 0; // will be used as name for those types
	const static int POSTORDER = 1;
	const static int INORDER = 2;
	const static int LEVELORDER = 3;
	BTreeADT();									// parameterless constructor
	BTreeNode *getRoot();						// get the root of the tree
	BTreeNode *getMin(BTreeNode *);				// getting the minimum and maximum
	BTreeNode *getMax(BTreeNode *);				// of the tree
	BTreeNode *searchNode(BTreeNode *, string); // searching the node on tree
	void addNode(BTreeNode *, BTreeNode *);		// adding the node to the parent
	void addNode(BTreeNode *);					// adding node on the near empty place
	void remove(BTreeNode *, string);			// removing the node holding data
	void print(BTreeNode *, KIND);				// this will be used to print tree with type
	int SizeIs(BTreeNode *);					// will return the size of the nodes
	int levels(BTreeNode *);					// the levels of the tree
	int height(BTreeNode *);					// the height of the tree
	int numberOfLeafs(BTreeNode *);				// return the number of leafs on tree
	int NumberOfSubTree(BTreeNode *);			// counter for number of subtree
	// your homework number 5
	void combine(BTreeNode *firstTree, BTreeNode *); // combine two trees
	void insert(BTreeNode *root, BTreeNode *[]);	 // insert from array
	bool isFullTree(BTreeNode *);
	bool isCompleteTree(BTreeNode *);

	~BTreeADT(); // destructore that call the reset();
};