#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int A[5002];
int dp[5002][2];

int aLis(int i, bool s){//cout << i << endl << flush;
    if(i==0){
        if(s && A[i]>0)return 1;
        if(!s && A[i]<0)return 1;
        return 0;
    }
    if(!s && A[i]>0)return 0;
    if(s && A[i]<0)return 0;
    if(dp[i][s]!=-1)return dp[i][s];
    int ans=1;
    for(int j=i-1; j>=0; j--){
        if(abs(A[j])<abs(A[i])){
            ans=max(ans, 1+aLis(j, !s));
        }
    }
    dp[i][s]=ans;
    return dp[i][s];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> A[i];
    memset(dp, -1, sizeof(dp));
    //cout << max(aLis(n-1, 1), aLis(n-1, 0)) << endl;
    int ans=0;//cout << aLis(2,1) << endl;
    for(int i=0; i<n; i++){
        ans=max(ans,max(aLis(i,0), aLis(i, 1)));
    }
    cout << ans << endl;
}
