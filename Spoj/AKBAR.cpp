#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <int>node[1000006];
vector <pair<int,int>> sl;
int e[1000006];
pair<bool, int> z[1000006];
int n,r,m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> r >> m;
        int x,y;
        for(int i=0; i<n; i++)node[i].clear();
        for(int i=0; i<r; i++){
            cin >> x >> y;x--;y--;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        sl.clear();
        for(int i=0; i<m; i++){
            cin >> x >> y;
            x--;
            sl.push_back({x,y});
        }
        bool ans=1;
        for(int i=0; i<n; i++)z[i]={0,-1};
        for(int j=0; j<m; j++){
            pair<int,int> b=sl[j];
            queue <pair<int,int>>q;
            q.push(b);
            if(z[b.first].first){
                ans=0;
                break;
            }
            z[b.first]=make_pair(1,j);
            while(!q.empty()){
                pair<int,int> a=q.front();q.pop();
                if(a.second<=0)continue;
                for(auto u:node[a.first]){
                    if(z[u].first && z[u].second!=j){
                        ans=0;
                        break;
                    }
                    if(z[u].first)continue;
                    z[u]=make_pair(1,j);
                    q.push({u,a.second-1});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(!z[i].first)ans=0;
        }
        if(!ans){
            cout << "No" << endl;
            continue;
        }else{
            cout << "Yes" << endl;
        }
    }
}
