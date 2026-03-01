#include<bits/stdc++.h>
using namespace std;

void quick_sort(vector<int>& arr, int l, int h){
    int i = l;
    int j = h;
    int pivot = arr[l];

    if(l<h){
        while(i<j){
            while(arr[i] <= pivot && i<h)
                i++;

            while(arr[j] > pivot)
                j--;
            
            if(i<j)
                swap(arr[l], arr[j]);
        }
        arr[l] = arr[i];
        arr[j] = pivot;

        quick_sort(arr, l, j-1);
        quick_sort(arr, j+1, h);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
        cin >> arr[i];

    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}