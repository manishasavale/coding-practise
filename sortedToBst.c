//
//  main.c
//  sortedToBst
//
//  Created by Manisha savale on 5/25/22.
//

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* sortedArrToBST(int arr[], int start, int end)
{
    if(start > end)
        return NULL;
    int mid = (start + end)/2;
    
    struct node* root = newNode(arr[mid]);
    //recursively construct the left subtree and make it the left child of root
    root->left = sortedArrToBST(arr,start, mid - 1);
    //recursively construct the right subtree and make it the right child of the root
    root->right= sortedArrToBST(arr, mid+1,end);
    
    return root;
}

void preorderTraversal(struct node* root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


int main() {
    // insert code here...
    
    int a[] = {1,2,3};
    int n = sizeof(a)/sizeof(a[0]);
    struct node* root = sortedArrToBST(a,0,n);
    preorderTraversal(root);
    return 0;
}
