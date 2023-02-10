//
//  selection_sort.c
//  
//
//  Created by Manisha savale on 5/11/21.
//
#include <stdio.h>


void swap(int *ip, int *jp)
{
    int temp=*ip;
    *ip=*jp;
    *jp=temp;
}

void selection_sort(int arr[],int n){
    int min_index,i,j;
    
    for(i=0; i<n-1 ;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
            if(arr[j]< arr[min_index])
                min_index = j;
        swap(&arr[min_index],&arr[i]);
    }
}

int main(void){
    int arr[]={10,5,7,37,1};
    
    int n=sizeof(arr)/sizeof(arr[0]);
    int i;
    selection_sort(arr,n);
    
    printf("\nSorted array:\t");
    for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
    printf("\n");
    return 0;
}
