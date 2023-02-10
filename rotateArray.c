//
//  rotateArray.c
//  
//
//  Created by Manisha savale on 6/28/21.
//

#include <stdio.h>

void leftRotatbebyOne(int arr[],int n){
    int i, temp=arr[0];
    for (i=0;i<n-1;i++)
        arr[i] = arr[i+1];
    arr[n-1] = temp;
 }
void rotateArray(int arr[],int d,int n){
    
    int i;
    for (i=0;i<d;i++)
        leftRotatbebyOne(arr,n);
    
}

void printArray(int arr[],int n){
    int i;
    for (i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

//driver function to rotate array by d
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    
    int d=2, n =sizeof(arr/sizeof(arr[0]));
    printf("\nInput Array:")
    printArray(arr,n);
    rotateArray(arr,d,n);
    //print array after rotation
    printf("\nArray after %d rotations:",d);
    printArray(arr,n);
    
    return 0;
}
