#include<bits/stdc++.h>
#define endl '\n'
#define INF 1000000

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin >> n;
    ll dp[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            ll a; cin >> a;
            dp[i][j]=a;
        }
    int k;
    cin >> k;
    ll ans[k];
    for(int r=0; r<k; r++){
            ll x,y,w;
            cin >> x >> y >> w;
            x--;y--;
            if(dp[x][y]>w)
                dp[x][y]=dp[y][x]=w;
            //else continue;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j]=min(dp[i][j], dp[i][x]+dp[x][y] + dp[y][j]);
                    dp[i][j]=min(dp[i][j], dp[i][y]+dp[y][x] + dp[x][j]);
                }
            }
            ans[r]=0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++)
                    ans[r]+=dp[i][j];
            }
            cout << ans[r]/2 << " ";
    }
}
