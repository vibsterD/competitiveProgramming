#include<iostream>
#include<algorithm>
#define INF 99999999999999
#define endl '\n'

typedef long long int ll;

using namespace std;

int C[1000005];
ll check[1000005];
ll cost(int i){
    if(i<0){
        return 0;
    }
    if(check[i]>0){
        return check[i];
    }
    check[i]=C[i]+ min(cost(i-1), cost(i-2));
    return check[i];
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n; cin >> n;
    //ll check[n];
    for(int i=0; i<n; i++){
        cin >> C[i];
        //check[i]=0;
    }
    for(int i=0; i<=n;i++)check[i]=0;
    ll a = cost(n-1);
    reverse(C, C+n);
    for(int i=0; i<=n;i++)check[i]=0;
    ll b = cost(n-1);
   // cout << a <<  " " << b << endl;
    cout << min(a,b) << endl;

}
