#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.rbegin(), arr.rend());

    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt += t/arr[i];
        t%=arr[i];
    }
    cout << cnt <<"\n";

    return 0;
}