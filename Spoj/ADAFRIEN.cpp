#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int q,k;
    string n; ll v;
    cin >> q >>k;
    unordered_map <string, ll> g;int i=1;
    vector <ll> gg;
    while(q--){
        cin >> n >> v;
        g[n]+=v;
    }
    for(auto b:g){
        gg.push_back(b.second);
    }
    ll ans=0;
    sort(gg.begin(), gg.end(), greater<ll>());
    while(!gg.empty() && k--){
        ans+=gg[0];
        gg.erase(gg.begin(), gg.begin()+1);
    }
    cout << ans << endl;

}
