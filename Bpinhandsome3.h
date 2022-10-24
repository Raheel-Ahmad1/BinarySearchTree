#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std;
// tree node, including left and right pointers, data 
struct Node {
	Node(string n, string m) : Name(n), PhoneNum(m), left(NULL), right(NULL) {}
	string Name;
	string PhoneNum;
	Node *left;
	Node *right;
};

/////////////////////////////////////////////////////////////////////////////////////////
// BST class
class BST {
public:
	Node *_root;
	void insert(Node *treeNode, string name, string num);
	bool isBalanced(Node *treeNode);
	int  getHeight(Node *treeNode);
	void deleteBST(Node *treeNode);
	Node * DeleteNode(Node * root, string key);
	Node * Find_Recursive(Node * treeNode, string key);
	Node * DeleteNode(string key);
	Node * DeleteNode();
	void inOrder(Node * treeNode);
	void InOrderCustomized(string key);
	void preOrder(Node * treeNode);
	void PostOrder_Iterative();
	void postOrder(Node * treeNode);


	Node *get_Root() { return _root; }
	BST();  // constructor     
	~BST();     // destractor
	Node* Find_Recursive(Node **treeNode, string key);
	Node * RecursiveSearch(Node * r, string key);
	Node* Find_Iterative(string key);
	void insert(string n, string m) { insert(_root, n, m); }

	int getHeight() { return getHeight(_root); }
	Node * getMaxNode();
	Node * getMinNode();

	Node * getMinValudeNode(Node * cur);

	void deleteBST() { deleteBST(_root); }

	bool isBalanced() { return isBalanced(_root); }

	void inOrder() { inOrder(_root); }
	void preOrder() { preOrder(_root); }
	void postOrder() { postOrder(_root); }
	void ReverseInOrder(Node *treeNode);
	void InOrder_Iterative();
};