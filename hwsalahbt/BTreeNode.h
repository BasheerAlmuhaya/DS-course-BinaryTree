#pragma once
#include <string>
#include <iostream>
using namespace std;
class BTreeNode
{
	BTreeNode *Left;
	string data;
	BTreeNode *Right;
	void makeNull();

public:
	BTreeNode();
	BTreeNode(string);
	void setData(string data);
	string getData();
	void setRight(BTreeNode *);
	BTreeNode *getRight();
	void setLeft(BTreeNode *);
	BTreeNode *getLeft();
	bool hasRight();
	bool hasLeft();
	bool isFree();
	~BTreeNode();
};
