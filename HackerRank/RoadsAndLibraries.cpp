#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <int> node[100005];
bool vis[100005];
ll kr=0;

void DFS(int i){
    if(vis[i])return;
    vis[i]=1;
    for(auto b:node[i]){
        if(!vis[b]){
            kr++;
            DFS(b);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int q;
    cin >> q;
    while(q--){
        ll n,m,cl,cr;
        cin >> n >> m >> cl >> cr;
        int x,y;
        for(int i=0; i<=n; i++)node[i].clear();
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<m; i++){
            cin >> x >> y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        ll ans=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                kr=0;
                DFS(i);
                ans+=min(cl+(cr*kr), cl*(kr+1));
            }
        }
        cout << ans << endl;
    }
}
