#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e9

typedef long long int ll;

using namespace std;

const int NMAX=5e4+1, LOGN=17;
vector <set<int>> node(NMAX);
int dt[NMAX], sTable[NMAX][LOGN], dis[NMAX], sz[NMAX];
ll ans=0;
bool pr[NMAX];
vector<int> Prime;
//Pre Proc
void genPrime(){
    pr[1]=pr[0]=1;
    for(int i=2; i*i<NMAX; i++){
        if(!pr[i])
            for(int j=i*i; j<NMAX; j+=i)pr[j]=1;
    }
    for(int i=0; i<NMAX; i++){
        if(!pr[i])Prime.push_back(i);
    }
}
void DFS(int u, int p){
    if(p==-1)sTable[u][0]=u;
    else sTable[u][0]=p;
    for(int i=1; i<LOGN; i++){
        sTable[u][i]=sTable[sTable[u][i-1]][i-1];
    }
    for(auto b:node[u]){
        if(b==p)continue;
        dt[b]=dt[u]+1;
        DFS(b,u);
    }
}

int LCA(int u, int v){
    if(dt[u]>dt[v])swap(u,v);
    int dist=dt[v]-dt[u];
    for(int i=0; i<LOGN; i++){
        if(dist&(1<<i)){
            v=sTable[v][i];
        }
    }
    if(u==v)return u;
    for(int i=LOGN-1; i>=0; i--){
        if(sTable[u][i]!=sTable[v][i])u=sTable[u][i],v=sTable[v][i];
    }
    return sTable[u][0];
}
int dist(int u, int v){
    return dt[u]+dt[v]-2*dt[LCA(u,v)];
}
//Decompose into centroid tree

int dfs0(int u, int p){
    sz[u]=1;
    for(auto b:node[u]){
        if(b==p)continue;
        sz[u]+=dfs0(b,u);
    }
    return sz[u];
}
//find centroid
int dfs1(int u, int p, int n){
    for(auto b:node[u]){
        if(b==p)continue;
        if(sz[b]>n/2)return dfs1(b,u,n);
    }
    return u;
}
void dfs2(int u, int p, int centroid){
    dis[dist(u,centroid)]++;
    for(auto b:node[u]){
        if(b!=p)dfs2(b,u,centroid);
    }
}
void dfs3(int u, int p, int centroid){
    dis[dist(u,centroid)]--;
    for(auto b:node[u]){
        if(b!=p)dfs3(b,u,centroid);
    }
}
void dfs4(int u, int p, int centroid){
    int d=dist(u,centroid);
    for(auto b:Prime){
        if(b-d>=0){
            ans+=dis[b-d];
        }
    }
    for(auto b:node[u]){
        if(b!=p)dfs4(b,u,centroid);
    }
}
void Decompose(int u, int p){
    int n=dfs0(u,p);
    int centroid=dfs1(u,p,n);
    dfs2(centroid, p, centroid);
    for(auto b:node[centroid]){
        dfs3(b,centroid,centroid);
        dfs4(b,centroid,centroid);
    }
    dis[0]=0;
    for(auto b:node[centroid]){
        if(b==p)continue;
        node[b].erase(centroid);
        Decompose(b,centroid);
    }
    node[centroid].clear();
    for(int i=0; i<NMAX && dis[i]; i++)dis[i]=0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll n;
    cin >> n;
    int a,b;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        node[a].insert(b);
        node[b].insert(a);
    }
    memset(dis,0,sizeof(dis));
    memset(pr,0,sizeof(pr));
    genPrime();
    dt[1]=1;
    DFS(1,-1);
    Decompose(1,-1);
    ll nc2=(n*(n-1))/2;
    long double aa= (long double)ans/nc2;
    cout << fixed;
    cout << setprecision(10) <<aa << endl;
}
