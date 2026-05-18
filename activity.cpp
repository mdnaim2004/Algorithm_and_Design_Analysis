#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> v;
    
    for(int i=0; i<n; i++){
        int start, finish;
        cin >> start >> finish;

        v.push_back({finish, start});
    }
    sort(v.begin(), v.end());

    int lastfinish = v[0].first;
    int cnt = 1;

    for(int i=1; i<n; i++){
        int start = v[i].second;
        int finish = v[i].first;

        if(start >= lastfinish){
            cnt++;
            lastfinish = finish;
        }
    }
    cout << cnt << "\n";
    return 0;
}