/*A program program for different Tree Traversals*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct record
{
    struct record *left;    
    int value;
    struct record *right;
}TREENODE;

TREENODE *root=NULL;

void prompt()
{
    printf("\n----------------------------------------------------------------------");
    printf("\n|| Press <1> to insert a new node to the binary tree                ||");
    printf("\n|| Press <2> to display the preorder traversal of the binary tree   ||");
    printf("\n|| Press <3> to display the inorder traversal of the binary tree    ||");
    printf("\n|| Press <4> to display the postorder traversal of the binary tree  ||");
    printf("\n|| Press <5> to search for a value in the list                      ||");
    printf("\n|| Press <0> to exit                                                ||");
    printf("\n----------------------------------------------------------------------");
}

void insert(int data)
{
    TREENODE *temp,*curr,*parent;
    temp=(TREENODE*)malloc(sizeof(TREENODE));
    temp->left=NULL;
    temp->value=data;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(data>curr->value)
            curr=curr->right;
        else if(data<curr->value)
            curr=curr->left;
    }
    if(data>parent->value)
        parent->right=temp;
    else if(data<parent->value)
        parent->left=temp;
}

void printInOrder(TREENODE* node)
{
	if(node!=NULL)
	{
    	printInOrder(node->left);
    	printf("%d\n",node->value);
    	printInOrder(node->right);
	}
}

void printPreOrder(TREENODE* node)
{
	if(node!=NULL)
	{
    	printf("%d\n",node->value);
    	printPreOrder(node->left);
    	printPreOrder(node->right);
	}
}

void printPostOrder(TREENODE* node)
{
	if(node!=NULL)
	{
    	printPostOrder(node->left);
    	printPostOrder(node->right);
    	printf("%d\n",node->value);
	}
}

bool search(int target)
{
    if(root==NULL)
    {
        printf("!!! Empty tree !!!");
        return false;
    }
    TREENODE *curr=root;
    while(curr!=NULL)
    {
        if(curr->value==target)
            return true;
        else if(target<curr->value)
            curr=curr->left;
        else
            curr=curr->right;
    }

    return false;
}
    
int main()
{
    int choice,data;
    bool check;
    do
    {
        prompt();
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
            case 1: printf("\nEnter data: ");
                    scanf("%d",&data);
                    insert(data);
                    break;
            case 2: puts("\nPreorder traversal of Binary Tree...");
	                printPreOrder(root);
                    break;
            case 3: puts("\nInorder traversal of Binary Tree...");
	                printInOrder(root);
                    break;
            case 4: puts("\nPostorder traversal of Binary Tree...");
	                printPostOrder(root);
                    break;
            case 5: printf("\nEnter the value to search: ");
                    scanf("%d",&data);
                    check=search(data);
                    if(check)
                        printf("\n%d present in the tree...",data);
                    else
                        printf("\n%d not present in the tree...",data);
                    break;
            default: printf("\nEnter a valid choice...");
        }
    }
    while(choice!=0);
    
	return 0;
}
/*

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 1

Enter data: 23

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 2

Preorder traversal of Binary Tree...
23

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 12

Enter a valid choice...
----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 4

Postorder traversal of Binary Tree...
23

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 100

Enter a valid choice...
----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 1

Enter data: 144

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 3

Inorder traversal of Binary Tree...
23
144

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 1

Enter data: 5

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 3

Inorder traversal of Binary Tree...
5
23
144

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 4

Postorder traversal of Binary Tree...
5
144
23

----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 5

Enter the value to search: 144

144 present in the tree...
----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 5

Enter the value to search: 22

22 not present in the tree...
----------------------------------------------------------------------
|| Press <1> to insert a new node to the binary tree                ||
|| Press <2> to display the preorder traversal of the binary tree   ||
|| Press <3> to display the inorder traversal of the binary tree    ||
|| Press <4> to display the postorder traversal of the binary tree  ||
|| Press <5> to search for a value in the list                      ||
|| Press <0> to exit                                                ||
----------------------------------------------------------------------
Enter choice: 0
*/