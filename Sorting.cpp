// Sorting using Bubble
#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubblesorting(int A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
        }
    }
}
//sorting using insertionsort
void insertionsort(int A[],int n){
    int x;
    for(int i=1;i<n;i++){
        x=A[i];
        int j=i-1;
        while(j>=0&&A[j]>x){
            A[j+1]=A[j];
            j--;

        }
        A[j+1]=x;
    }
}
//Sorting using Selection Sort
void selectionsort(int A[],int n){
    int i,k,j;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
            swap(&A[i],&A[k]);
        }
    }
}
//Sorting using Quick Sort
int partion(int A[],int l,int h){
    int pivot=A[l];
    int i=l,j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[i]>pivot);
        if(i<j){
            swap(A[l],A[j]);
        }

    }while(i<j);
    swap(A[l],A[j]);
    return j;
}
void Quicksort(int A[],int l,int h){
    int j;
    if(l<h){
        j=partion(A,l,h);
        Quicksort(A,l,j);
        Quicksort(A,j+1,h);

    }
}
int main(){
    int A[]={2,4,9,8,5,7,6,INT32_MAX};
    int n=sizeof(A)/sizeof(A[0]);
    // Bubblesorting(A,n);
    // insertionsort(A,n);
    // selectionsort(A,n);
    Quicksort(A,2,7);
    
    
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";

    }
    return 0;
}
