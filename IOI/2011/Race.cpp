#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

const int NMAX=2e5+1, LOGN=19, NMAX2=1e6+1;
int sz[NMAX];
ll k;
vector <set<pair<int,int>>> node(NMAX);
multiset <int> dis[NMAX2];
ll ans=INF;

//Decompose
//subtree size
int dfs0(int u, int p){
    sz[u]=1;
    for(auto b: node[u]){
        if(b.first==p)continue;
        sz[u]+=dfs0(b.first, u);
    }
    return sz[u];
}
//find centroid
int dfs1(int u, int p, int n){
    for(auto b:node[u]){
        if(b.first==p)continue;
        if(sz[b.first]>n/2)return dfs1(b.first, u, n);
    }
    return u;
}
//updating dist multiset
void dfs2(int u, int p, ll dista, int len, bool s){
    if(dista<=k)
    if(s)dis[dista].insert(len);
    else if(dis[dista].find(len)!=dis[dista].end())dis[dista].erase(dis[dista].find(len));
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfs2(b.first,u,dista+b.second, len+1,s);
    }
}
//upading ans
void dfs3(int u, int p, ll dista, int len){
    if((ll)k-dista>=0 && !dis[k-dista].empty())ans=min(ans,(ll) (*dis[k-dista].begin())+len);
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfs3(b.first, u, dista+b.second, len+1);
    }
}
//Decompose
void Decompose(int u, int p){
    int n=dfs0(u,p);
    int centroid=dfs1(u,p,n);
   // cout << "WE " << ans  << ' ' << n << ' ' << centroid << endl << flush;
    dfs2(centroid, p, 0, 0, 1);
    for(auto b:node[centroid]){
        if(b.first==p)continue;
        dfs2(b.first,centroid,b.second,1,0);
        dfs3(b.first,centroid,b.second,1);
    }
    for(auto b:node[centroid]){
        if(b.first==p)continue;
        node[b.first].erase({centroid,b.second});
        Decompose(b.first, centroid);
    }
    node[centroid].clear();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cin >> n >> k;
    int a,b,w;
    for(int i=1; i<n; i++){
        cin >> a >> b >> w;
        node[a].insert({b,w});
        node[b].insert({a,w});
    }
    Decompose(0,-1);
    if(ans>=INF)cout << -1 << endl;
    else cout << ans << endl;
}
