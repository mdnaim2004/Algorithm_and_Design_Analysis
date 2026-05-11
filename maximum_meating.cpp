#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    vector<pair<int, pair<int, int>>> v;

    for(int i=0; i<n; i++){
        int s, f;
        cin >> s >> f;
        
        v.push_back({f,{s, i+1}});
    }
    sort(v.begin(), v.end());

    // vector<int> ans;

    int last = -1;

    vector<int> ans;
    // for(auto x: v){
    //     int finish = x.first;
    //     int start = x.second.first;
    //     int idx = x.second.second;
    //     if(start >= last){
    //         ans.push_back(idx);
    //         last = finish;
    //     }
    // }

    for(auto x : v){
        if(x.second.first >= last){
            ans.push_back(x.second.second);
            last = x.first;
        }
    }


    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x << " ";
    }
    return 0;
}