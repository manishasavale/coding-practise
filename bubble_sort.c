//
//  bubble_sort.c
//  
//
//  Created by Manisha savale on 5/12/21.
//

#include <stdio.h>
void print_array(int arr[],int n){
    int i;
    for(i=0; i<n ; i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

/*
void swap(int *xp,int *yp){
    int temp = *xp;
    *xp=*yp;
    *yp=temp;
}
*/
void bubble_sort(int arr[],int n){
    int i,j,temp=0;
    for(i=0; i<n-1; i++)
    //last i elements are already in place
        for(j=0; j<n-i-1 ;j++)
            if(arr[j]>arr[j+1]){
                    //swap(&arr[j],&arr[j+1]);
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1]=temp;
            }
}
int main(void){
    int arr[]={20,21,5,9,0,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("\nArray before sorting:\n");
    print_array(arr,n);
    bubble_sort(arr,n);
    printf("\nArray after sorting using bubble sort:\n");
    print_array(arr,n);
    
    return 0;
}
