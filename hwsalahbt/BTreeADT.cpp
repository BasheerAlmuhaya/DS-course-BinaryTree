// class implementation
#include "BTreeADT.h"
void BTreeADT::resetTree(BTreeNode *v)
{ // error in the return condation?
	// MOVE ACROSS THE TREE AND DELETE EACH NODE
	if ( // isEmpty()
		v == NULL)
		return;
	resetTree(v->getLeft()); // or you can do delete here
	resetTree(v->getRight());
	delete v;
}
bool BTreeADT::isEmpty()
{
	return (this->root == NULL);
}
void BTreeADT::preOrder(BTreeNode *v)
{
	if (v == NULL)
		return;
	cout << v->getData() << "  "; // printing first
	preOrder(v->getLeft());
	preOrder(v->getRight());
}
void BTreeADT::postOrder(BTreeNode *v)
{
	if (v == NULL)
		return; // error preOrder(v->getLeft());  preOrder(v->getRight());
	postOrder(v->getLeft());
	postOrder(v->getRight());
	cout << v->getData() << "  "; // printing at the end
}
void BTreeADT::inOrder(BTreeNode *v)
{
	if (v == NULL)
		return;
	inOrder(v->getLeft());		  // error preOrder(v->getLeft());
	cout << v->getData() << "  "; // this is the condition inorder
	inOrder(v->getRight());
} // error preOrder(v->getRight()); }
void BTreeADT::levelOrder(BTreeNode *v)
{ // error
	string *a = new string[SizeIs(v)];
	insertl(v, *&a, 0);
	for (int i = 0; i < SizeIs(v); i++)
		cout << a[i] << "\t";
}
void BTreeADT::insertl(BTreeNode *v, string a[], int i)
{
	if (v == NULL)
		return;
	a[i] = v->getData();
	insertl(v->getLeft(), *&a, 2 * i + 1);
	insertl(v->getRight(), *&a, 2 * i + 2);
	return;
}
bool BTreeADT:: // adding with me to class
	isParent(BTreeNode *v)
{
	return (!v->isFree());
}

// public methodes
BTreeADT::BTreeADT()
{
	this->root = NULL;
}
BTreeNode *BTreeADT::getRoot()
{
	return (this->root);
}
BTreeNode *BTreeADT::getMin(BTreeNode *v)
{
	if (isEmpty())
	{ // error
	}
	return NULL;
}
BTreeNode *BTreeADT::getMax(BTreeNode *v)
{
	if (isEmpty())
	{ // error
	}
	return NULL;
}
BTreeNode *BTreeADT::searchNode(BTreeNode *v, string data)
{
	if (v == NULL)
	{
		BTreeNode *t4 = new BTreeNode;
		return t4;
	} // return NULL;
	if (v->getData() == data)
		return v; // error ?
	// if(v->isFree())return v;
	BTreeNode *t1 = searchNode(v->getLeft(), data);
	if (t1->getData() == data)
		return t1;
	BTreeNode *t2 = searchNode(v->getRight(), data);
	if (t2->getData() == data)
		return t2;
	BTreeNode *t3 = new BTreeNode;
	return t3;
	// return NULL;
	// return (v->getData()!=data ? searchNode(v->getLeft(),data) :searchNode(v->getRight(),data));
}
void BTreeADT::addNode(BTreeNode *parent, BTreeNode *chiled)
{
	if (parent == NULL // isEmpty()
	)
	{
		return;
	}
	if (parent->getLeft() == NULL)
	{
		parent->setLeft(chiled);
		return;
	}
	else if (parent->getRight() == NULL)
	{
		parent->setRight(chiled);
		return;
	}
	numberOfLeafs(parent->getLeft()) > numberOfLeafs(parent->getRight()) ? addNode(parent->getRight(), chiled) : addNode(parent->getLeft(), chiled);
	/*BTreeNode* temp=searchNode(root,parent->getData()); //error iteration
	if     (temp->getLeft()==NULL) {temp->setLeft(chiled); }
	else if(temp->getRight()==NULL){temp->setRight(chiled);}
	*/
	// else cout<<"\n\t error this parent have no empty place for new chiled\n";
	// if(parent->getLeft()->isFree()){addNode(parent->getLeft(),chiled);return;}
	// else if(parent->getRight()->isFree()){addNode(parent->getRight(),chiled);return;}
}
void BTreeADT::addNode(BTreeNode *n)
{
	if (isEmpty())
	{
		this->root = n;
		return;
	}						// now traverse the tree to put the node on the nearst
	BTreeNode *temp = root; // either left or right empty place
	addNode(temp, n);
	/*if     (temp->getLeft()==NULL){ addNode(temp,n); return; }
	else if(temp->getRight()==NULL){addNode(temp,n); return; }
	else if(!isParentf(temp->getLeft())){addNode(temp->getLeft(),n);return;}
	else if(isParent(temp->getLeft())){addNode(temp->getRight(),n);return;}*/
}
void BTreeADT::remove(BTreeNode *n, string data)
{ // error
	if (isEmpty())
	{
		cout << "\n\t error cannot add to the parent data" << data << " the tree is empty\n";
	}
	BTreeNode *temp = searchNode(n, data);
	if (temp->getData() == data && temp->isFree())
		delete temp;
}
void BTreeADT::print(BTreeNode *v, KIND kind)
{
	if (isEmpty())
	{
		cout << "\n\t Empty Tree ";
		return;
	}
	cout << endl;
	switch (kind)
	{
	case POSTORDER:
		this->postOrder(v);
		break;
	case PREORDER:
		this->preOrder(v);
		break;
	case INORDER:
		this->inOrder(v);
		break;
	case LEVELORDER:
		this->levelOrder(v);
		break;
	default:
		break;
	}
	cout << endl;
}
int BTreeADT::SizeIs(BTreeNode *v)
{ // true
	if (v == NULL)
	{
		return 0;
	}
	else
		return (1 + SizeIs(v->getLeft()) + SizeIs(v->getRight()));
}
int BTreeADT::levels(BTreeNode *v)
{
	if (v == NULL)
		return -1; // 0;
	return (	   // error 1-
		MAX((1 + levels(v->getLeft())), (1 + levels(v->getRight()))));
}
int BTreeADT::height(BTreeNode *v)
{
	if (v == NULL)
		return 0;
	return ( // error 1+
		MAX((1 + height(v->getLeft())), (1 + height(v->getRight()))));
}
int BTreeADT::numberOfLeafs(BTreeNode *v)
{
	if (v == NULL)
		return 0; // error if (isParent(v)){   return 0;  }
	if (v->isFree())
		return 1;
	return ( // error 1+
		numberOfLeafs(v->getLeft()) + numberOfLeafs(v->getRight()));
}
int BTreeADT:: // error at::
	NumberOfSubTree(BTreeNode *v)
{
	if ( // error !isParent(v)
		v == NULL || v->isFree())
	{
		return 0;
	}
	else
		return (1 + NumberOfSubTree(v->getLeft()) + NumberOfSubTree(v->getRight()));
}
// your homework number 5
void BTreeADT::combine(BTreeNode *firstTree, BTreeNode *secondTree)
{
	// do your homework here
	BTreeADT *v = new BTreeADT;
	v->addNode(new BTreeNode("0"));
	v->addNode(firstTree);
	v->addNode(secondTree);
	print(v->getRoot(), 3);
}
void BTreeADT::insert(BTreeNode *root, BTreeNode *v[])
{
	// do your work here
}

bool BTreeADT::isFullTree(BTreeNode *v)
{
	// do your work here
	if ((pow(2, height(v)) - 1) == SizeIs(v))
		return 1;
	return 0;
}
bool BTreeADT::isCompleteTree(BTreeNode *v)
{
	// do your work here
	return false;
}
