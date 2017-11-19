#include<iostream>
#include<algorithm>

#define INF 4000000000
#define endl '\n'

typedef long long int ll;

using namespace std;

unsigned int tim[200005];
unsigned int n;

ll dp[200005][4];
bool check[200005][4];

ll ans(ll ind, int res){
    if(n<3){
        return 0;
    }
    if(check[ind][res]){
        return dp[ind][res];
    }

    if(res==3){
        //check[ind][res]=true;
        //dp[ind][res]=INF;
        return INF;
    }
    if(ind==n){
        //check[ind][res]=true;
        //dp[ind][res]=0;
        return 0;
    }

    dp[ind][res] = min(ans(ind+1,res+1), (ans(ind+1, 0)+ tim[ind]));
    check[ind][res]=true;
    return dp[ind][res];
}

int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    for(int i=0; i<200005; i++){
        for(int j=0; j<4; j++){
            dp[i][j]=-21;
            check[i][j]=false;
        }
    }
    cin >> n;
    for(unsigned int i=0; i<n; i++)cin >> tim[i];
    cout << ans(0,0) << endl;
}
