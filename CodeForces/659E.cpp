#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <int> node[100005];
bool vis[100005], isTree;

void DFS(int i, int p){
    if(vis[i])return;
    vis[i]=1;
    for(auto b: node[i]){
        if(b==p)continue;
        //if(S.find(make_pair(edges[b],b))!=S.end())S.erase(S.find(make_pair(edges[b],b)));
        if(!vis[b])DFS(b,i);
        else isTree=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    int x,y;
//    for(int i=0; i<=n; i++)edges[i]=0;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    //memset(source, 0, sizeof(source));
    memset(vis, 0, sizeof(vis));
    int ans=0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            isTree=1;
            DFS(i,0);
            if(isTree)ans++;
        }
    }
    cout << ans << endl;
}
