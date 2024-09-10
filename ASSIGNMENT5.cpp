/*ASSIGNMENT 5:
Name:SAHIL DHAS
Roll No. 23514
Sub :Data Structures and algorithms
*/
#include <iostream>  
  
using namespace std;  
  
class Node 
{  
	public:  
	  	int data;  
	  	Node *right;  
	  	Node *left;
  
  // Constructor to initialize a new node
		Node(int data) 
		{  
		    this->data = data;  
		    this->right = NULL;  
		    this->left = NULL;
  	    }  
};  

class binarytree{
	private:
		Node* root;
		// Recursive function to insert a new node with the given data
		Node* insert(Node* node , int data)
		{
			if(node == NULL)
			{
				return new Node(data);
			}
			if(data < node->data)
			{
				node->left = insert(node->left,data);
			}
			else
			{
				node->right = insert(node->right,data);
			}
			return node;
		}
		 // Recursive function to perform in-order traversal and print node values
		void shift(Node* node)
		{
			if(node!=NULL)
			{
				shift(node->left);
            	cout << node->data << " ";
            	shift(node->right);
			}
		}
		// Function to find the minimum value node in the right subtree
	Node* f(Node* node) 
    {
        while (node->left != NULL) 
        {
            node = node->left;
        }
        return node;
    }
    // Recursive function to delete a node with the given data
	Node* del(Node* node, int data) 
    {
        if (node == NULL) 
        {
            return NULL;
        }
        if (data < node->data) 
        {
            node->left = del(node->left, data);
        } 
        else if (data > node->data) 
        {
            node->right = del(node->right, data);
        } 
        else 
        {
        	 // Node with the data is found
            if (node->left == NULL) 
            {
                Node* temp = node->right;
                delete node;
                return temp;
            } 
            else if (node->right == NULL) 
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            Node* temp = f(node->right);

            node->data = temp->data;

            node->right = del(node->right, temp->data);
        }
        return node;
    }
public:
	// Constructor to initialize an empty binary tree
    binarytree() 
	{
        this->root = NULL;
    }
	
	// Public method to insert a new node with the given data
    void insert(int data) 
	{
        root = insert(root, data);
    }
	
	// Public method to display the tree elements in sorted order
    void display() 
	{
        shift(root);
        cout << endl;
    }
    // Public method to delete a node with the given data
    void Delete(int data) 
	{
        root = del(root, data);
    }
};

int main()
{
	binarytree tree;

Node* node;
	while(node!=NULL)
	{
		cout<<"ENTER WHAT YOU WANT : \n 1.INSERT \n 2.DELETE \n 3.DISPLAY"<<endl;
		int x; 
		cout<<": ";
		cin>>x;
		if(x==1)
		{
			int y ;
			cin>>y;
			tree.insert(y);
			continue;
		}
		if(x==2)
		{
			int z;
			cin>>z;
		tree.Delete(z);
			continue;
		}
		if(x==3)
		{
			tree.display();
		}
		else
		{
			cout<<"enter valid choice "<<endl;
		}
	}
}
