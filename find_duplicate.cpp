#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool f = false;
    set<int> s;
    
    for(int i=0; i<n; i++){
        if(s.count(arr[i])){
            cout <<"Duplicate: "<<arr[i]<<endl;
        }
        s.insert(arr[i]);
    }
    // if(f == false){
    //     cout << 
    // }
    return 0;
}

