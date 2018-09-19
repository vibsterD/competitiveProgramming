#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

string s;
int dp[6111][6111];

int cost(int i, int j){
    if(s[i]!=s[j])return INF;
    return 0;
}

int Palin(int i, int j){//cout << i << ' ' << j << endl << flush;
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    dp[i][j]=min(1+Palin(i+1,j), min(1+Palin(i,j-1), Palin(i+1,j-1)+cost(i,j)));
    //cout << 1+Palin(i+1,j) << ' ' << Palin(i,j-1)+1 << ' ' << Palin(i+1, j-1) + cost(i,j) << endl;
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        cin >> s;
        memset(dp, -1, sizeof(dp));//cout << s.size() << flush << endl;
        cout << Palin(0,s.size()-1) << endl;
    }
}
