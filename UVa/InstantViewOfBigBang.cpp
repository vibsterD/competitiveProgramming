//belman ford with dummy node for -veCycle detection
//above used with reversing the directed edges for detecting nodes part of -veCycles or reachable through it
//finding rest of the nodes through BFS of the nodes detected in -veCycle detection
#include<bits/stdc++.h>
#define endl '\n'
#define INF 1000000000

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T, r=1; cin >> T;
    while(T--){
        cout << "Case " << r++ << ":";
        int n,m;
        cin >> n >> m;
        vector <pair<int,int>> adj[n+1];//adj.clear();
        for(int i=0; i<m; i++){
            int a,b,t;
            cin >> a >> b >> t;
            adj[b].push_back(make_pair(a,t));
        }
        for(int i=0;i<n; i++)adj[n].push_back({i,0});
        ll dis[n+1];
        for(int i=0; i<n; i++)dis[i]=INF;
        dis[n]=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<=n; j++){
                for(auto node:adj[j]){
                    dis[node.first]=min(dis[node.first],(dis[j]+node.second));
                }
            }
        }
        queue <int> v;
        for(int j=0; j<=n; j++){
            for(auto node:adj[j]){
                if(dis[node.first]>(dis[j]+node.second)){
                    v.push(node.first);
                    v.push(j);
                }
            }
        }
        if(v.empty()){
            cout << " impossible" << endl;
        }else{
            bool vis[n+1];memset(vis, 0, sizeof(vis));
            while(!(v.empty())){
                int a=v.front();v.pop();
                if(vis[a])continue;
                vis[a]=true;
                for(auto node:adj[a]){
                    if(vis[node.first])continue;
                    v.push(node.first);
                }
            }
            vector <int> sol;
            for(int i=0; i<n; i++){
                    if(vis[i]){
                        sol.push_back(i);
                    }
            }
            sort(sol.begin(),sol.end());
            for(auto u:sol){
                cout << " " << u;
            }
            cout << endl;
        }
    }
}
