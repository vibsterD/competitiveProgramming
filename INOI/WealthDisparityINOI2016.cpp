#include<bits/stdc++.h>
#define INF 9999999999
#define endl '\n'

typedef long long int  ll;

using namespace std;

int n;

vector <int> adj[100001];
int A[100001], pr[100001];
set <pair<int, int>> inProc;
bool vis[100001]={false};
ll ans = -INF;
void DFS(int p){
    if(vis[p])return;
    vis[p]=true;
    inProc.insert({A[p],p});
    for(auto r:adj[p]){
        if(!inProc.empty()){
            pair<int,int> m=*inProc.rbegin();
            ans =max(ans,(ll)m.first-A[r]);
        }
        DFS(r);
    }
    inProc.erase({A[p],p});
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    //int A[n], p[n];
    for(int i=0; i<n; i++)
        cin >> A[i];
    for(int i=0; i<n; i++)
        cin >> pr[i], pr[i]--;
    int head;
    for(int i=0; i<n; i++){
        if(pr[i]==-2){
            head=i;
            continue;
        }
        adj[pr[i]].push_back(i);
    }
    DFS(head);
    cout << ans;
}
