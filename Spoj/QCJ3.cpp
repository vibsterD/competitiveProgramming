//Game Theory: Sprauge-Grunndy Theorem!!
#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t;
    cin >> t;
    ll n,x;
    while(t--){
        cin >> n;
        ll ans=0;
        for(ll i=1; i<=n; i++){
            cin >> x;
            if(x&1)ans=ans^i;
        }
        if(ans)cout << "Tom Wins" << endl;
        else cout << "Hanks Wins" << endl;
    }

}
