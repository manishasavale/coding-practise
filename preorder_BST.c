//
//  main.c
//  preorder_constrctBST
//
//  Created by Manisha savale on 8/2/21.
//

#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right =NULL;
    return temp;
}
struct node* constructTree(int pre[],int* preIndex,int low,int high,int size){
    //base case
    if(*preIndex >= size || low > high)
        return NULL;
    
    //construct the root
    struct node* root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
    
    //if the subarray has only one element then no need to recurse
    if(low == high)
        return root;
    
    //find the first element greater than root
    //we can divide the pre array into left subtree and right subtree
    int i;
    for(i=low; i <= high; i++){
        if(pre[i] > root->data)
            break;
    }
    
    //left subtree
    root->left = constructTree(pre,preIndex,*preIndex,i-1,size);
    
    //right subtree
    root->right = constructTree(pre,preIndex,i,high,size);
    return root;
}

struct node* constructBST(int pre[],int size){
    int preIndex = 0;
    return constructTree(pre,&preIndex,0,size -1,size);
}

void printInorder(struct node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    printf(" %d ",root->data);
    printInorder(root->right);
}

int main() {
    // insert code here...
    int pre[] = {10,5,1,7,40,50};
    int size = sizeof(pre)/sizeof(pre[0]);
    struct node* root = constructBST(pre,size);
    printf("The constructevBST from preorer array is:\n");
    printInorder(root);
        
    return 0;
}
