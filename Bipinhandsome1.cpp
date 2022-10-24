

#include <iostream>
#include<algorithm>
#include<string>

#include "BTree.h"
using namespace std;

int PrintMenu()
{
	cout << "Please Select your Choice \n";
	cout << "1: Insert a New Node \n";
	cout << "2: Search for a Node (Recursive Implementation) \n";
	cout << "3: Search for a Node (Iterative Implementation) \n";
	cout << "4: In-Order Traversal (Recursive Implementation) \n";
	cout << "5: In-Order Traversal(Iterative Implementation) \n";
	cout << "6: Reverse In-Order Traversal \n";
	cout << "7: Post-Order Traversal (Recursive Implementation)\n";
	cout << "8: Post-Order Traversal (Iterative Implementation)\n";
	cout << "9: Deleting a Node \n";
	cout << "10: Show Min Node \n";
	cout << "11: Show Max Node \n";
	cout << "12: Customized In Order\n";
	cout << "13: Pre: Order \n";
	cout << "\n 0: Exit \n";
	int choice;
	cin >> choice;
	return choice;
}

int main(int argc, char** argv)
{
	BST myBST;
	int c = PrintMenu();
	string n, m;
	Node * temp;
	while (c!= 0)
	{
		switch (c)
		{
		case 1:
			cout << "Inserting a new Node \n";
			while(true)
			{
			cout << "Enter Name : ";
			cin >> n;
			cout << "Enter Telephone Number \n";
			cin >> m;
		
			while (n.length() > 16 || m.length() > 10)
			{
				cout << "Limit Exceeds, Name must be less than 16 character, and telehpone # must be less than 10 Character \n";
				cout << "Enter Name : ";
				cin >> n;
				cout << "Enter Telephone Number \n";
				cin >> m;
			}
			myBST.insert(n, m); //Insert New Node
			char ch;
			cout<<"Press y or Y to enter a new record. \n Press n or N to return to main Menu ";
			cin>>ch;
			if(ch=='Y' || ch=='y')  continue;
			else break;
			}
			
			break;
		case 2:
			cout << "Searching a Node using Recursive Search \n";
			cout << "Enter name to be searched \n";
			cin >> n;
			
			temp = myBST.Find_Recursive( myBST._root,n);
			if (!temp)
				cout << "Name with input value = " << n << " not found \n";
			else
			{
				cout << "Name found " << temp->Name << ", Telephone #: " << temp->PhoneNum << "\n";
			}
			break;
		case 3:
			cout << "Searching a Node using Iterative Search \n";
			cout << "Enter a Name to search : \n";
			cin >> n;
			temp=myBST.Find_Iterative(n);
			if (!temp)
				cout << "Name with input value = " << n << " not found \n";
			else
			{
				cout << "Name found " << temp->Name << ", Telephone #: " << temp->PhoneNum << "\n";
			}
			break;
		case 4:
			cout << "In-order Traversal (Recursive Implementation) \n";
			myBST.inOrder(); cout << endl;
			break;
		case 5:
			cout << "In-Order Traversal (Iterative Implementation) \n";
			myBST.InOrder_Iterative();
			break;
		case 6:
			cout << "Reverse In-Order Traversal \n";
			myBST.ReverseInOrder(myBST.get_Root());
			cout<<"\nReverse Order Traversal Listed Aboved\n";
			break;
		case 7:
			cout << "Post-Order Traversal (Recursive Impelementation) \n";
			myBST.postOrder(); cout << endl;
			break;
		case 8:
			cout << "Post-Order Traversal (Iterative Impelementation) \n";
			myBST.PostOrder_Iterative();
			cout << "\nPost Order Listed Above \n";
			break;
		case 9:
			temp = myBST._root;
			cout << "Deleting a Node \n";
			cout << "Enter a name to delete :";
			cin >> n;
			
			
			myBST._root=myBST.DeleteNode(myBST._root, n);
			cout << "Deletion Operation Completed \n";
		case 0:
			cout << "Exiting \n";
			break;
		case 10:
			cout << "Displaying Minimum Node \n";
			temp= myBST.getMinNode();
			cout << "Min value with Name=: " << temp->Name << endl;
			break;
		case 11:
			cout << "Displaying Maximum Node \n";
			temp = myBST.getMaxNode();
			cout << "max value with Name=: " << temp->Name << endl;
			break;
		case 12:
			cout << "Enter a Name to start from ";
			cin >> n;
			myBST.InOrderCustomized(n);
			break;
		case 13:
			cout << "Pre-Order \n ";
			myBST.preOrder();
		default:
			cout << "please Make a Valid Selection \n";
			break;
		}
		cout << "\n\n";
		cout << "****************************************************************************\n";
		cout<<"Press r or R to repeat the menu \n";
	
		char ch;
		cin>>ch;
		if(ch=='r' || ch=='R') 
		c = PrintMenu();
		else break;
	}
	/*
	myBST.insert("Imran", "897");
	myBST.insert("Nazia", "3333146214");
	myBST.insert("Eshaal", "333918054");

	myBST.insert("ImranKhan", "1000");



	int h = myBST.getHeight();
	cout << "the height of this BSt is : " << h << endl;

	Node * mx = myBST.getMaxNode();
	cout << "max value with Name=: " << mx->Name << endl;

	Node * mi = myBST.getMinNode();
	cout << "min value wit Name =: " << mi->Name << endl;

	bool isbal = myBST.isBalanced();
	if (isbal)
		cout << "BST is balanced! " << endl;
	else
		cout << "BST is not balanced! " << endl;

	cout << " in-order traverse is : " << endl;
	myBST.inOrder(); cout << endl;
	cout << " pre-order traverse is : " << endl;
	myBST.preOrder(); cout << endl;
	cout << " post-order traverse is : " << endl;
	myBST.postOrder(); cout << endl;
	*/
	getchar();
}
