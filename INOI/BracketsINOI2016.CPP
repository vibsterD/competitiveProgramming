#include<bits/stdc++.h>
#define endl '\n'

typedef long long int ll;

using namespace std;

int n,k;
int V[701], B[701];
bool vis[701][701];
ll dp[701][701];
ll DP(int i, int j){
    if(i>=j)return 0;
    if(vis[i][j])return dp[i][j];
    dp[i][j]=DP(i+1,j);
    for(int r=i+1; r<=j; r++){
        if(B[r]==B[i]+k){
            dp[i][j]=max(dp[i][j], DP(i+1, r-1)+V[i]+V[r]+DP(r+1,j));
        }
    }
    vis[i][j]=true;
    return dp[i][j];
}

void makeFalse(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            vis[i][j]=false;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)cin >> V[i];
    for(int i=0; i<n; i++)cin >> B[i],B[i]--;
    makeFalse();
    cout << DP(0, n-1);
}
