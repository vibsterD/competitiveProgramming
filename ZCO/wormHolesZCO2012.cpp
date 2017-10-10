#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<limits.h>


#define endl '\n'

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long int n, x, y;
    cin >> n >> x >> y;
    vector <pair<int, int>> contest; vector <int> v; vector<int> w;
    int a1, a2;
    for(int i=0; i<n; i++){
        cin >> a1 >> a2;
        contest.push_back(make_pair(a1, a2));
    }
    for(int i=0;i<x;i++){
        cin >> a1;
        v.push_back(a1);
    }
    for(int i=0;i<y;i++){
        cin >> a1;
        w.push_back(a1);
    }
    sort(contest.begin(),contest.end());sort(v.begin(),v.end());sort(w.begin(),w.end());

    long ans = LONG_MAX,x1,y1,t1,t2;
    vector<int>::iterator low,hi;

    for(long int i=0; i<n; i++){
            x1=contest[i].first;
            y1=contest[i].second;
            low = upper_bound(v.begin(),v.end(), x1);
            if((low-v.begin()-1)<0)continue;
            t1 = v[low-v.begin()-1];

            hi = lower_bound(w.begin(), w.end(), y1);
            if(hi==w.end())continue;
            t2= w[hi-w.begin()];

            ans = min((t2-t1+1),ans);

    }

    cout << ans << endl;

}

