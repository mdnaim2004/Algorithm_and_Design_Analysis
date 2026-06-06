#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;   // n times task
    cin >> n;

    vector<pair<pair<int,int>,int>> v;  // store as a vector of pair form in the output...

    for(int i=0; i<n; i++){  // intput the 
        int start, finish;
        cin >> start >> finish;

        v.push_back({{finish, start}, i+1});
    }
    sort(v.begin(), v.end()); // sorted of the pair of vector....

    vector<int> ans;
    ans.push_back(v[0].second);

    int last_finish = v[0].first.first;   // pic the finish time of the 1st taks

    for(int i=1; i<n; i++){

        int finish = v[i].first.first;
        int start = v[i].first.second;

        if(start >= last_finish){
            ans.push_back(v[i].second);
            last_finish = finish;
        }
    }

    cout << ans.size() << "\n";

    for(int x : ans)
        cout << x << " ";
    
    cout << "\n";

    return 0;
}