#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

vector <int> node[2001];
bool vis[2001],ans=1;
int col[2001];
void DFS(int i, bool c=0){
    if(vis[i]&&col[i]==c){
        return;
    }else if(vis[i]){
        ans=0;
        return;
    }
    col[i]=c;
    vis[i]=1;
    for(auto b:node[i]){
        DFS(b,!c);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t, N=0;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int x,y;
        for(int i=0; i<=n; i++)node[i].clear();
        for(int i=0; i<m; i++){
            cin >> x >> y;
            node[x].push_back(y);
            node[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        memset(col, -1, sizeof(col));
        ans=1;
        while(1){
            bool k=0;
            for(int i=1; i<=n; i++){
                if(!vis[i]){
                    DFS(i);
                    k=1;
                    break;
                }
            }
            if(!k){
                break;
            }
        }
        cout << "Scenario #" << ++N << ":" << endl;
        if(ans){
            cout << "No suspicious bugs found!" << endl;
        }else {
            cout << "Suspicious bugs found!" << endl;
        }
    }
}
