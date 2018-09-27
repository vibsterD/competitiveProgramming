#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <pair<int,int> > node[100002];
bool vis[100002];
ll e[100002];
priority_queue <pair<ll,int>> q;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n,m,s,t;
        cin >> n >> m >> s >> t;
        int x,y,w;
        for(int i=0; i<m; i++){
            cin >> x >> y >> w;
            node[x].push_back({y,w});
            node[y].push_back({x,w});
        }
        for(int i=0; i<=n; i++){
            e[i]=INF;
        }
        memset(vis, 0, sizeof(vis));
        while(!q.empty())q.pop();
        q.push({0,s});
        e[s]=0;
        while(!q.empty()){
            int a=q.top().second;q.pop();
            if(vis[a])continue;
            if(vis[t])break;
            vis[a]=1;
            for(auto b:node[a]){
                if(e[b.first]>e[a]+b.second){
                    e[b.first]=e[a]+b.second;
                    q.push({-e[b.first], b.first});
                }
            }
        }
        if(vis[t]){
            cout << e[t] << endl;
        }else{
            cout << "NONE" << endl;
        }
    }
}
