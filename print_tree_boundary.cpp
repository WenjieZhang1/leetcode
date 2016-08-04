/* program for boundary traversal of a binary tree */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
};
 
void printleaves(struct node* root)
{
	if(root){
		printleaves(root->right);
		if((!root->right) && (!root->left)){
			cout<<root->data<<" ";
		}
		printleaves(root->left);
	}
}

void printright(struct node* root)
{
	if(root){
		if(root->right){
			cout<<root->data<<" ";
			printright(root->right);
		}else if(root->left){
			cout<<root->data;
			printright(root->left);
		}
	}
}


void printleft(struct node* root)
{
	if(root){
		if(root->left){
			printright(root->left);
			cout<<root->data<<" ";
		}else if(root->right){
			printright(root->right);
			cout<<root->data<<" ";
		}
	}
}


struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

void printBoundary (struct node* root)
{
    if (root)
    {
        cout<<root->data<<" ";
 
        // Print the left boundary in top-down manner.
        printright(root->right);
 
        // Print all leaf nodes
        printleaves(root->right);
        printleaves(root->left);
 
        // Print the right boundary in bottom-up manner
        printleft(root->left);
    }
}

int main()
{
    // Let us construct the tree given in the above diagram
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}