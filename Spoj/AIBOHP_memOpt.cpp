#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int n;
string s;
int dp[6511][2];

int cost(int i, int j){
    if(s[i]!=s[j])return INF;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        cin >> s;
        n=s.size();
        for(int i=n-1; i>=0; i--){
            dp[i][0]=0;
        }
        for(int j=1; j<n; j++){
            for(int i=n-1; i>=0; i--){
                if(i>=j){
                    dp[i][1]=0;
                    continue;
                }
                dp[i][1]=min(dp[i+1][1]+1,min(dp[i][0]+1, dp[i+1][0]+cost(i,j)));
            }
            for(int i=0; i<n; i++){
                dp[i][0]=dp[i][1];
            }
        }
        cout << dp[0][1] << endl;
    }
}
