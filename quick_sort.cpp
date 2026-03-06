#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int l, int h){
    if(l<h){
        int i = l;
        int j = h;
        int pivot = arr[l];

        while(i < j){
            while(i<h && arr[i] <= pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if(i<j){
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
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >>arr[i];

    quick_sort(arr, 0, n-1);

    for(int x : arr)
        cout << x <<" ";
    cout << endl;

    return 0;
}