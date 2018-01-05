#include<bits/stdc++.h>
#define endl '\n'
#define INF 99999999999

typedef long long int ll;

using namespace std;

int a[1000002],b[1000002];
bool dp[1000002]={false};
ll DP[1000002];
ll DPF(ll i){
    if(i==0)return a[0];
    if(i==1)return max(a[0]+a[1],a[1]);
    if(dp[i])return DP[i];
    DP[i]=max((ll)a[i]+a[i-1],DPF(i-1)-a[i-1]+a[i]+b[i-1]);
    dp[i]=true;
    return DP[i];
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;ll ans=-INF;
    //ll a[n],b[n];
    for(int i=0; i<n; i++){
        cin >> a[i];ans=max(ans, (ll)a[i]);
    }
    for(int i=0; i<n; i++)
        cin >> b[i];
    vector <ll> Pr;
    Pr.push_back(b[0]);
    for(int i=1; i<n; i++){
        Pr.push_back(Pr[i-1]+b[i]);
    }
    vector <ll> PrMax;
    //pair<ll,ll> M={-INF,0}, m={INF,0};
    PrMax.push_back(a[0]);
    for(int i=1; i<n; i++){
        /*if(M.first<Pr[i]){
            M={Pr[i],i};
        }
        if(m.first>Pr[i]){
            m={Pr[i],i};
        }*/
        PrMax.push_back(max(PrMax[i-1],a[i]+Pr[i-1]));
        //PrMin.push_back(m);
    }
    //ll af=-INF,ab=max(a[0],max(a[1], a[1]+a[0]+Pr[n-1]-Pr[1]));
    //cout << "af: \n \t";
    for(int i=0; i<n; i++){
        ans=max(ans, DPF(i));
    }
    for(int i=1; i<n ;i++){
        ans=max(ans,Pr[n-1]-Pr[i]+a[i]+PrMax[i-1]);
    }
    cout << ans;
    //cout << endl << "ab:" << ab << ";;af:" << af;
}
