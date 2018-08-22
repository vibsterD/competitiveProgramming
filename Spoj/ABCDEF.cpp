#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    int S[n];
    for(int i=0; i<n; i++)cin>>S[i];
    vector <int> LHS, RHS;set <int> dis;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                LHS.push_back((S[i]*S[j]+S[k]));
                if(S[i]!=0)
                    RHS.push_back((S[i]*(S[j]+S[k])));
                dis.insert((S[i]*S[j]+S[k]));
            }
        }
    }
    sort(LHS.begin(), LHS.end());
    sort(RHS.begin(), RHS.end());
    ll ans=0,k1;
    for(auto b:dis){
        auto it=lower_bound(LHS.begin(),LHS.end(),b);
        auto it1=upper_bound(LHS.begin(),LHS.end(),b);
        auto ls=lower_bound(RHS.begin(),RHS.end(),b);
        auto ls1=upper_bound(RHS.begin(),RHS.end(),b);
        k1=(it1-it)*(ls1-ls);
        ans+=k1;
    }
    cout << ans;

}
