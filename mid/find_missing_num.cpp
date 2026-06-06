#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int arr_sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr_sum += arr[i];
    }
    n = n+1;
    //cout << arr_sum << "\n";
    int n_num = (n*(n+1))/2;

    int ans = n_num - arr_sum;
    cout << ans <<"\n";

    return 0;
}