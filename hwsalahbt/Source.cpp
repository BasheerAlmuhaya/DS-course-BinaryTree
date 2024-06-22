// BinaryTree.cpp : main project file.
/*    - DATA STRUCTURE II
 *    - USING VISUAL STUDIO 2012          16-4-2018
 *    - GENERAL TREE NODE CLASS THAT REPRESENT THE NODE  *
 *    - DEPARTMENT OF SOFTWARE AND IT   _  SECOND_LEVEL  *
 *    - LAB_THREE                BY ENG_SALAH_ALSSAYANI
 *    -  Header file for Node implementation and the whole operation
 *       it may contain and you are free to define what ever.
 *    -  Binary Tree Node Class with full encapsulation strategy means that
 *       dealing only with public getters and setters  *
 *    -  BTreeNode.h  */
/*  *    BTreeNode.cpp : The class implementation  */

// BinaryTreeLab3.cpp : Defines the entry point for the console application. //
#include <iostream>
#include "BTreeNode.h"
#include "BTreeADT.h"
#include <math.h>
using namespace std;

int		  //_t
	main( // int argc, _TCHAR* argv[]
	)
{

	// cout<<"\n the location of the program is \t"<<argv[0]<<endl;
	BTreeADT *binaryTree = new BTreeADT();
	binaryTree->addNode(new BTreeNode("computer"));
	BTreeNode *t = binaryTree->searchNode(binaryTree->getRoot(), "computer");
	cout << t->getData() << endl;
	binaryTree->addNode(new BTreeNode("computer1"));
	binaryTree->addNode(new BTreeNode("computer2"));
	binaryTree->addNode(new BTreeNode("computer3"));
	binaryTree->addNode(new BTreeNode("computer4"));
	binaryTree->addNode(new BTreeNode("computer5"));
	binaryTree->addNode(new BTreeNode("computer6"));
	BTreeNode *s = binaryTree->searchNode(binaryTree->getRoot(), "computer7");
	cout << s->getData() << endl;
	cout << "\nno of subtree\t\t" << binaryTree->NumberOfSubTree(binaryTree->getRoot()) << endl;
	cout << "\nno of leaf\t\t" << binaryTree->numberOfLeafs(binaryTree->getRoot()) << endl;
	cout << "\nsize of tree is \t" << binaryTree->SizeIs(binaryTree->getRoot()) << endl;
	cout << "\nno of levels\t\t" << binaryTree->levels(binaryTree->getRoot()) << endl;
	cout << "\nheight of tree is\t" << binaryTree->height(binaryTree->getRoot()) << endl;
	if (binaryTree->isFullTree(binaryTree->getRoot()))
		cout << "\nbinarytree is fulltree\n";
	binaryTree->print(binaryTree->getRoot(), 3);
	BTreeADT *binaryTree1 = new BTreeADT();
	binaryTree1->addNode(new BTreeNode("desk"));
	binaryTree1->addNode(new BTreeNode("desk1"));
	binaryTree1->addNode(new BTreeNode("desk2"));
	if (binaryTree1->isFullTree(binaryTree1->getRoot()))
		cout << "\nbinarytree 1 is fulltree\n";
	binaryTree1->print(binaryTree1->getRoot(), 3);
	binaryTree->combine(binaryTree->getRoot(), binaryTree1->getRoot());
	cout << endl;
	system("pause");
	return 0;
}