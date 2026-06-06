#include <stdio.h>

void quick(int a[], int l, int h){
    int i=l, j=h, p=a[l], t;
    if(l<h){
        while(i<j){
            while(a[i]<=p && i<h) i++;
            while(a[j]>p) j--;
            if(i<j){ t=a[i]; a[i]=a[j]; a[j]=t; }
        }
        a[l]=a[j]; a[j]=p;
        quick(a,l,j-1);
        quick(a,j+1,h);
    }
}

int main(){
    int a[]={5,3,8,4,2}, i;
    quick(a,0,4);
    for(i=0;i<5;i++) 
        printf("%d ",a[i]);
}