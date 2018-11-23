#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18
#define cout Fout
#define cin Fin
#pragma GCC optimize ("O3")

typedef long long int ll;

using namespace std;

const int NMAX=1e5+2, nn=1e5;

set<pair<int,int>> node[NMAX];
int dis[2*NMAX],dis1[2*NMAX];
int sz[NMAX];
bool vis[2*NMAX];
ll ans=0;
//centroid Decomposition
//size
int dfs0(int u, int p){
    sz[u]=1;
    for(auto b:node[u]){
        if(b.first==p)continue;
        sz[u]+=dfs0(b.first,u);
    }
    return sz[u];
}
//find centroid
int dfs1(int u, int p, int n){
    for(auto b:node[u]){
        if(b.first==p)continue;
        if(sz[b.first]>n/2)return dfs1(b.first,u,n);
    }
    return u;
}
//Update
void dfs2(int u, int p, bool s, int l=0){
    if(u!=p){
        if(s)dis[nn+l]++;
        else dis[nn+l]--;
    }
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfs2(b.first,u,s,l+b.second);
    }
}
//PnC
void dfs3(int u, int p, int l){
    if(dis1[nn+l]){
        if(!l)ans+=dis[nn-l]+1;
        else ans+=dis[nn-l];
    }else if(!l){
        ans+=dis[nn-l];
    }
    dis1[nn+l]++;
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfs3(b.first,u,l+b.second);
    }
    dis1[nn+l]--;
}
void dfs4(int u, int p, int l){
    if(!dis1[nn+l]&&l!=0)dis[nn+l]++;
    dis1[nn+l]++;
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfs4(b.first,u,l+b.second);
    }
    dis1[nn+l]--;
}
void dfsclear(int u, int p, int l){
    dis[nn+l]=0;
    for(auto b:node[u]){
        if(b.first==p)continue;
        dfsclear(b.first,u,l+b.second);
    }
}
//Decompose
void build(int u, int p){
    int n=dfs0(u,p);
    int centroid=dfs1(u,p,n);
    dfs2(centroid,centroid,1);
    for(auto b:node[centroid]){
        dfs2(b.first,centroid,0,b.second);
        dfs3(b.first,centroid,b.second);
        dfs4(b.first,centroid,b.second);
    }
    dfsclear(centroid,p,0);
    for(auto b:node[centroid]){
        node[b.first].erase({centroid,b.second});
        build(b.first,centroid);
    }
    node[centroid].clear();
}

int main(){
//    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ifstream Fin("yinyang.in");
    //ifstream Fin("10.in");
    ofstream Fout("yinyang.out");
    int n;
    cin >> n;
    int a,b,w;
    for(int i=1; i<n; i++){
        cin >> a >> b >> w;
        w=2*w-1;
        node[a].insert({b,w});
        node[b].insert({a,w});
    }
    memset(dis,0,sizeof(dis));
    memset(dis1,0,sizeof(dis1));
    build(1,1);
    cout << ans << endl;
}
