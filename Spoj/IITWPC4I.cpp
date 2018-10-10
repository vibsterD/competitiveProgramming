#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <pair<ll, pair<int,int>>> node;
pair<int,bool> id[100002];
int n, m;

pair<int,bool> root(int x){
    while(x!=id[x].first){
        id[x]=id[id[x].first];
        x=id[x].first;
    }
    return id[x];
}

void Union(int i, int j){
    int ii=id[i].first, jj=id[j].first;
    if(id[ii].second){
        id[jj]=id[ii];
    }else id[ii]=id[jj];
}

ll kruskal(){
    ll minCost=0;
    for(auto b:node){
        if(root(b.second.first)==root(b.second.second))continue;
        if(root(b.second.first).second && root(b.second.second).second)continue;
        minCost+=b.first;
        Union(b.second.first, b.second.second);
    }
    return minCost;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        bool k;
        node.clear();
        for(int i=1; i<=n; i++){
            cin >> k;
            id[i]={i,k};
        }
        int x, y, w;
        for(int i=0; i<m; i++){
            cin >> x >> y >> w;
            node.push_back({w, {x,y}});
        }
        sort(node.begin(), node.end());
        ll ans = kruskal();k=1;
        for(int i=1; i<=n; i++){
            if(!root(i).second)k=0;
        }
        if(k)cout << ans << endl;
        else cout << "impossible" << endl;
    }
}
