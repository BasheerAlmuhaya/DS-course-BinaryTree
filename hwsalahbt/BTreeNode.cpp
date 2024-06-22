#include "BTreeNode.h"
BTreeNode::BTreeNode()
{
	this->data = "";
	this->makeNull();
}
BTreeNode::BTreeNode(string data)
{
	this->data = data;
	this->makeNull();
}
void BTreeNode::makeNull()
{
	this->Left = NULL;
	this->Right = NULL;
}

void BTreeNode::setData(string data) { this->data = data; }
void BTreeNode::setLeft(BTreeNode *v) { this->Left = v; }
void BTreeNode::setRight(BTreeNode *v) { this->Right = v; }
string BTreeNode::getData() { return data; }
BTreeNode *BTreeNode::getLeft() { return this->Left; }
BTreeNode *BTreeNode::getRight() { return this->Right; } // error NULL; }
bool BTreeNode::isFree() { return (this->Left == NULL && this->Right == NULL); }
bool BTreeNode::hasRight() { return (this->Right != NULL); }
bool BTreeNode::hasLeft() { return (this->Left != NULL); }
BTreeNode::~BTreeNode()
{
	// define your destructor here
	cout << "destructor" << this->data;
	delete this;
}
