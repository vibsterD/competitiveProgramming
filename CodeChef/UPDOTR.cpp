//Technique: binary Lifting + DFS
#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;
const int N = 1e6+7;
int n;
int A[N], M[N], C[N], table[N][22], p[N];
bool vis[N];
vector <int> node[N];

void DFS(int i, int d, int c, int w){
    if(vis[i])return;
    if(A[i]>w){
        w=A[i];
        c++;
    }
    C[i]=c;
    M[i]=w;
    vis[i]=1;
    table[i][0]=d;
    for(int j=1; j<ceil(log2(n)); j++){
        table[i][j]=table[table[i][j-1]][j-1];
    }
    for(auto b:node[i]){
        DFS(b,i,c,w);
    }
}
int ans(int v, int w){
    if(M[v]<=w)return 0;
    int f=v;
    for(int i=ceil(log2(n))-1; i>=0; i--){
        if(M[table[v][i]]>w && table[v][i]!=-1){
            v=table[v][i];
        }
    }
    return C[f]-C[v]+1;
}

void makeFalse(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<22; j++)table[i][j]=-1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> A[i];
            node[i].clear();
        }int y;
        for(int i=2; i<=n; i++){
            cin >> y;
            node[i].push_back(y);
            node[y].push_back(i);
        }
        int q,a,pr=0;
        cin >> q;
        memset(vis, 0, sizeof(vis));
        makeFalse();
        p[1]=1;
        DFS(1,0,0,0);
        while(q--){
            cin >> a >> y;
            a^=pr;
            y^=pr;
            pr=ans(a, y);
            cout << pr <<endl;
        }
    }
}
