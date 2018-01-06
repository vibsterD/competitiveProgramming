//Deep & simple explanation: https://stackoverflow.com/questions/14040696/what-is-a-better-method-to-solve-this-prob
#include<bits/stdc++.h>
#define endl '\n'

typedef long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n; cin >> n;
    int table[n+2];
    table[0]=table[n+1]=0;
    for(ll i=1; i<=n; i++){
        int a; cin >> a;
        table[i]=a+i;
        table[i]=max(table[i-1], table[i]);
    }
    cout << table[n] << " ";
    int z=1;
    for(int i=n; i>1; i--){
        table[i]-=n;
        table[i]=max(table[i], table[i+1])+1;
        table[i-1]+=z;
        z++;
        cout << max(table[i],table[i-1]) << " ";
    }
}
