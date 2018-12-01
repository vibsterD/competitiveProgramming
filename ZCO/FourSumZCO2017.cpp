#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18
#pragma GCC optimize ("O3")

typedef long long int ll;

using namespace std;

const int NMAX=1e6+2;
ll n,t;
vector<ll> s;
vector<tuple<ll,int,int>>A;
vector<pair<int,int>>B[NMAX];
bool sorted[NMAX];

bool cmp(pair<ll,ll> &_A, pair<ll,ll> &_B){
    return _A.second<_B.first;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin >> n >> t;
    ll a;
    s.push_back(0);
    for(int i=1; i<=n; i++){
        cin >> a;
        s.push_back(a);
    }
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(s[i]+s[j]>=t)continue;
            A.push_back({s[i]+s[j],i,j});
            B[s[i]+s[j]].push_back({i,j});
        }
    }
    memset(sorted,0,sizeof(sorted));
    for(int i=1; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(s[i]+s[j]>=t)continue;
            if(sorted[s[i]+s[j]])continue;
            sort(B[s[i]+s[j]].begin(),B[s[i]+s[j]].end());
            sorted[s[i]+s[j]]=1;
        }
    }
    ll ans=0,k;
    for(auto b:A){
        if(get<0>(b)>=t)continue;
        k=t-get<0>(b);
        auto c=lower_bound(B[k].begin(),B[k].end(),make_pair(get<2>(b)+1,-1));
        if(c==B[k].end())continue;
        ans+=B[k].end()-c;
    }
    cout << ans << endl;
}
