#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubblesorting(int A[],int n){
    for(int i=0;i<n-i-1;i++){
        for(int j=0;j<n-1;j++){
            if(A[j]>A[j+1])
                swap(&A[j],&A[j+1]);
        }
    }
}
int main(){
    int A[]={2,4,9,8,5,7,6};
    int n=sizeof(A)/sizeof(A[0]);
    Bubblesorting(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";

    }
    return 0;
}
