#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int l, int h){
    if(l<h){ 
        int i = l;
        int j = h;
        int pivot = arr[l];

        while(i<j){
            while(i<h && arr[i] <= pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[l], arr[j]);

        quick_sort(arr, l, j-1);
        quick_sort(arr, j+1, h);
    }
}

int main(){
    int n;
    cin >> n; // array size input nilam

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i]; // array input nilam


    quick_sort(arr, 0, n-1);  //quick sort k call korlam.....



    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}