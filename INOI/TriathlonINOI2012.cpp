#include<bits/stdc++.h>
#define endl '\n'

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n;
    cin >> n;
    vector <pair<int,int>> citizens;
    ll d=0;
    for(int i=0; i<n; i++){
        ll a,b,c;
        cin >> a >>b >>c;
        citizens.push_back({b+c,a});
        d+=a;
    }
    sort(citizens.begin(), citizens.end());
    ll ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, d+citizens[i].first);
        d-=citizens[i].second;
    }
    cout << ans;
}
