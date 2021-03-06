#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e9

typedef long long int ll;

using namespace std;

int A[105],n;
int dp[105][105][105];

int LIDS(int pos, int i, int j){
    if(pos==n+2)return 0;
    if(dp[pos][i][j]!=-1)return dp[pos][i][j];
    dp[pos][i][j]= LIDS(pos+1, i, j);
    if(A[i]<A[pos]){
        dp[pos][i][j]=max(dp[pos][i][j], LIDS(pos+1, pos, j)+1);
    }
    if(A[j]>A[pos]){
        dp[pos][i][j]=max(dp[pos][i][j], LIDS(pos+1, i, pos)+1);
    }

    return dp[pos][i][j];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=2; i<=n+1; i++){
            cin >> A[i];
        }
        A[0]=INF;
        A[1]=-INF;
        memset(dp, -1, sizeof(dp));
        cout << LIDS(2,1,0) << endl;
    }
}
