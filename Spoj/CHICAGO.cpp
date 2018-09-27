#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

long double e[102];
vector <pair<int,double> > node[102];
bool vis[102];
priority_queue <pair<double, int> > q;

int main(){
    while(1){
        int n, m;
        cin >> n;
        if(n==0)return 0;
        cin >> m;
        int x,y,w;
        for(int i=0; i<=n; i++)node[i].clear();
        for(int i=0; i<m; i++){
            cin >>x >>y >>w;
            node[x].push_back({y,-log(w/100.0)});
            node[y].push_back({x,-log(w/100.0)});
        }
        while(!q.empty())q.pop();
        for(int i=0; i<=n; i++){
            e[i]=INF;
        }
        memset(vis,0,sizeof(vis));
        e[1]=-0;
        q.push({0,1});
        while(!q.empty()){
            int a=q.top().second; q.pop();
            if(vis[a])continue;
            if(vis[n])break;
            vis[a]=1;
            for(auto b: node[a]){
                if(e[b.first] > e[a]+b.second){
                    e[b.first]=e[a]+b.second;
                    q.push({-e[b.first], b.first});
                }
            }
        }
        double ans = exp(-e[n]);
        cout << fixed;
        cout << setprecision(6) << (double)100.0*ans << " percent"<< endl;
    }
    return 0;
}
