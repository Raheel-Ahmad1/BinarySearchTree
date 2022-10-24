#include "BTree.h"
/////////////////////////////////////////////////////////////////////////////////////////
BST::BST()
{
	_root = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::insert(Node *treeNode, string name, string num)
{
	Node *temp = treeNode;
	if (!treeNode)
	{
		treeNode = new Node(name, num);
		_root = treeNode;
	}
	else
	{
		if (name < treeNode->Name)
		{
			if (!treeNode->left)
			{
				Node *treeTemp = new Node(name, num);
				treeNode->left = treeTemp;
			}
			else
				insert(treeNode->left, name, num);
		}
		else
		{
			if (!treeNode->right)
			{
				Node *treeTemp = new Node(name, num);
				treeNode->right = treeTemp;
			}
			else
				insert(treeNode->right, name, num);
		}
	}
	treeNode = temp;
}

/////////////////////////////////////////////////////////////////////////////////////////
int BST::getHeight(Node *treeNode)
{
	if (!treeNode)
		return 0;
	return 1 + max(getHeight(treeNode->left), getHeight(treeNode->right));
}

/////////////////////////////////////////////////////////////////////////////////////////
bool BST::isBalanced(Node *treeNode)
{
	if (!treeNode)
		return false;
	int leftHeight = getHeight(treeNode->left);
	int rightHeight = getHeight(treeNode->right);

	if (abs(leftHeight - rightHeight) > 1)
		return false;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMaxNode()
{
	if (!_root)
	{
		cout << " the BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->right)
		treeNode = treeNode->right;
	return treeNode;
}

/////////////////////////////////////////////////////////////////////////////////////////
Node * BST::getMinNode()
{
	if (!_root)
	{
		cout << " the BST is empty!" << endl;
		return NULL;
	}
	Node * treeNode = _root;
	while (treeNode->left)
		treeNode = treeNode->left;
	return treeNode;
}
Node *BST::getMinValudeNode(Node *cur)
{
	if (!cur) return cur;
	Node *temp = cur;
	while (temp)
		temp = temp->left;
	return temp;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::deleteBST(Node *treeNode)
{
	if (!treeNode)
		return;

	Node * curTreeNode = treeNode;
	Node * leftTreeNode = treeNode->left;
	Node * rightTreeNode = treeNode->right;
	delete(curTreeNode);
	deleteBST(leftTreeNode);
	deleteBST(rightTreeNode);
}
Node *BST::DeleteNode(Node *root, string key)
{
	
	if (root == NULL) return NULL;

	
	if (key < root->Name)
		root->left = DeleteNode(root->left, key);

	 
	else if (key > root->Name)
		root->right = DeleteNode(root->right, key);

	// if key is same as root's key, then This is the node 
	// to be deleted 
	else
	{
		cout << "Deleting Node ";
		// node with only one child or no child 
		if (root->left == NULL)
		{
			Node *temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node *temp = root->left;
			delete(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest 
		// in the right subtree) 
		Node* temp = getMinValudeNode(root->right);

		// Copy the inorder successor's content to this node 
		root->Name = temp->Name;
		root->PhoneNum = temp->PhoneNum;
		// Delete the inorder successor 
		root->right = DeleteNode(root->right, temp->Name);
	}
	return root;
}
Node* BST::Find_Recursive(Node *treeNode, string key)
{
	Node *temp = treeNode;
	Node *res = RecursiveSearch(treeNode, key);
	treeNode = temp;
	return res;
}
Node *BST::RecursiveSearch(Node *r, string key)
{
	if (!r) return NULL;
	if (key == r->Name) return r;
	if (key < r->Name) return RecursiveSearch(r->left, key);
	else return RecursiveSearch(r->right, key);

}
Node *BST::Find_Iterative(string key)
{
	Node *temp = _root;
	//Node **temp = _root;
	while (_root)
	{
		if (key > _root->Name)
			_root = _root->right;

		// pass left subtree as new tree 
		else if (key <_root->Name)
			_root = _root->left;
		else
		{
			Node *res = _root;
			_root = temp;
			return res;// if the key is found return 1 
		}
	}
	_root = temp;
	return NULL;
}
void BST::InOrder_Iterative()
{
	stack<Node *> st; 
	Node *temp_root = _root;
    Node **curr = &_root; 
  
    while ((*curr)  || st.empty() == false) 
    { 
        while ((*curr) !=  NULL) 
        { 
            st.push((*curr)); 
            (*curr) = (*curr)->left; 
        } 
        (*curr) = st.top(); 
        st.pop(); 
        cout << "( "<<(*curr)->Name << ",  "<<(*curr)->PhoneNum<<") "; 
        (*curr) = (*curr)->right; 
  
    } /* end of while */
	_root = temp_root;
}
/////////////////////////////////////////////////////////////////////////////////////////
BST::~BST()
{
	deleteBST();
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::inOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	inOrder(treeNode->left);
	cout << "(" << treeNode->Name << ", " << treeNode->PhoneNum << ") ";
	inOrder(treeNode->right);
}
void BST::InOrderCustomized(string key)
{
	Node *res = Find_Iterative(key);
	if (!res) return;
	inOrder(res);
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::preOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	cout << "(" << treeNode->Name << ", " << treeNode->PhoneNum << ") ";
	preOrder(treeNode->left);
	preOrder(treeNode->right);
}
void BST::PostOrder_Iterative()
{
	if (!_root)
		return;
	Node *temp = _root;
	Node *Cur = _root;
	stack<Node*> myst;
	
	do
	{
		// Move to leftmost node 
		while ((Cur))
		{
			// Push root's right child and then root to stack. 
			if ((Cur)->right)
				myst.push(Cur->right);
			myst.push(Cur);

			// Set root as root's left child   
			(Cur) = (Cur)->left;
		}

		// Pop an item from stack and set it as root     
		Cur = myst.top();
		myst.pop();
		// If the popped item has a right child and the right child is not 
		// processed yet, then make sure right child is processed before root 
		
		if (!myst.empty() && (Cur)->right && myst.top() == (Cur)->right)
		{
			myst.pop();  // remove right child from stack 
			myst.push(Cur);  // push root back to stack 
			(Cur) = (Cur)->right; // change root so that the right  
								// child is processed next 
		}
		else  // Else print root's data and set root as NULL 
		{
			cout << "(" << (Cur)->Name << ", " << (Cur)->PhoneNum << ") ";
			Cur = NULL;
		}
	} while (!myst.empty());
	_root = temp;
}

/////////////////////////////////////////////////////////////////////////////////////////
void BST::postOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	postOrder(treeNode->left);
	postOrder(treeNode->right);
	cout << "(" << treeNode->Name << ", " << treeNode->PhoneNum << ") ";
}

void BST::ReverseInOrder(Node * treeNode)
{
	if (!treeNode)
		return;
	inOrder(treeNode->right);
	cout << "(" << treeNode->Name << ", " << treeNode->PhoneNum << ") ";
	inOrder(treeNode->left);
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////