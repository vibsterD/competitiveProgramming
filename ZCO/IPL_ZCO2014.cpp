#include<iostream>
#include<algorithm>

#define endl '\n'
#define INF 4000000000

typedef long long int ll;

using namespace std;

int n;
unsigned int pr[200005];
ll dp[200005][4];
bool check[200005][4];

ll ans(ll ind, int res){
    if(n<3){
        return pr[0]+pr[1];
    }
    if(res==3){
        return -INF;
    }
    if(ind==n){
        return 0;
    }
    if(check[ind][res]){
        return dp[ind][res];
    }
    dp[ind][res]= max(ans(ind+1,0), ans(ind+1,res+1)+pr[ind]);
    check[ind][res]=true;
    return dp[ind][res];
}

int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for(ll i=0; i<n; i++){
            cin>>pr[i];
            for(int j=0; j<4; j++){
                check[i][j]=false;
                dp[i][j]=-INF;
            }
    }
    pr[n]=0;
    cout << ans(0,0);
}
