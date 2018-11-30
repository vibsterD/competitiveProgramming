#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18
#pragma GCC optimize ("O3")

typedef long long int ll;

using namespace std;

const int NMAX=2502;
int n,m,k;
vector<tuple<int,int,int>> R[NMAX],C[NMAX];
ll dp[NMAX][NMAX];
bool valid[NMAX][NMAX];

bool pulse(int i, int j){
    int t=i+j-2,t1,f,d;
    for(auto b:R[i]){
        d=abs(j-get<0>(b));
        t1=get<1>(b);
        f=get<2>(b);
        while(t-t1>=0){
            if(t-t1==d)return 0;
            t1+=f;
        }
    }
    for(auto b:C[j]){
        d=abs(i-get<0>(b));
        t1=get<1>(b);
        f=get<2>(b);
        while(t-t1>=0){
            if(t-t1==d)return 0;
            t1+=f;
        }
    }
    return 1;
}

void makeGrid(){
    memset(valid,0,sizeof(valid));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            valid[i][j]=pulse(i,j);
        }
    }
}

bool solve(){
    makeGrid();
    if(!valid[1][1])return 0;
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(valid[i][j])dp[i][j]+=dp[i-1][j]+dp[i][j-1];
            else dp[i][j]=0;
        }
    }
    if(dp[m][n])return 1;
    else return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin >> n >> m >> k;
    int a,b,c,d;
    for(int i=0; i<k; i++){
        cin >> a >> b >> c >> d;
        R[a].push_back({b,c,d});
        C[b].push_back({a,c,d});
    }
    if(solve()){
        cout << "YES" << endl;
        cout << n+m-2 << endl;
    }else cout << "NO" << endl;
}
