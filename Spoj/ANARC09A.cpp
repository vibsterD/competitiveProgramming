#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e8

typedef long long int ll;

using namespace std;

int dp[2005][2005];
string s;

int cost(int i, int ans, bool st){
    char k=s[i];
    //cout << "a" << ans << endl;
    if(st){
        if(k=='{')k='}';
        else k='{';
    }
    if(k=='{')ans++;
    else{
        if(ans==0)return -1;
        else ans--;
    }
    //cout << i << ' ' << st << ' ' << ans << endl;
    return ans;
}

int solve(int i, int j){
    if(j==-1)return INF;
    if(i==s.size()){
        if(j!=0)return INF;
        else return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=min(solve(i+1,cost(i,j,0)), solve(i+1, cost(i, j, 1))+1);
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll T=0;
    while(1){
        cin >>s;
        if(s[0]=='-')return 0;
        memset(dp,-1,sizeof(dp));
        cout << ++T << ". " << solve(0,0) << endl;
    }
}
