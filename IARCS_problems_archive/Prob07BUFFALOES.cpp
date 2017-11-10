#include<iostream>
#include<algorithm>
#define endl '\n'

typedef long long int ll;

using namespace std;

int n, k;
int cc[401];
bool check[401][401][2];//n,k,state
ll dp[401][401][2];

int cost(int i, int state){
    if(state==0){
        return cc[i];
    }
    if(state==1){
        return -cc[i];
    }

}

ll ans(int i, int k, int state){
    if(i>=n || k==0){
            return 0;
    }
    if(check[i][k][state])
        return dp[i][k][state];
    int inverse = ((state==0)? 1:0);
    dp[i][k][state]= max(cost(i, state) + ans(i+1,k-1, inverse), ans(i+1, k, state) );
    check[i][k][state]=true;
    return dp[i][k][state];
}

int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> cc[i];
    }
    ll best = ans(0, k, 1);
    cout << best ;
}
