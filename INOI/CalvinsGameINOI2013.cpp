#include<bits/stdc++.h>
#define INF 99999999999
#define endl '\n'

typedef long long int ll;

using namespace std;

ll n,k;
 int node[1000001];
 ll dp1[1000001];
 bool dpp1[1000001];
  ll dp2[1000001];
 bool dpp2[1000001];
 ll fr(int i){
     if(i<k)return -INF;
     if(i==k){
        dp1[i]=0;
        return 0;
     }
     if(dpp1[i])
        return dp1[i];
     dp1[i]=max(fr(i-1), fr(i-2))+node[i];
     dpp1[i]=true;
     return dp1[i];
 }
 void makeFalse(){
    for(int i=0; i<n; i++){
        dpp1[i]=false;
        dpp2[i]=false;
    }
 }
 ll bk(int i){
     if(i<0)return -INF;
     if(i==0){
        dp2[i]=0;
        return 0;
     }
     if(dpp2[i])
        return dp2[i];
     dp2[i]=max(bk(i-1)+node[i-1],bk(i-2)+node[i-2]);
     dpp2[i]=true;
     return dp2[i];
 }
int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n >> k;
    for(ll i=0; i<n; i++){
        cin >>node[i];
    }k--;
    ll cur, Tfr=-INF, Bck, dab;
    makeFalse();
    for(int i=k; i<n; i++){
        dab= fr(i);
        dab+= bk(i);
        if(dab>Tfr){
            Tfr=dab;
        }
    }
    cout << Tfr;
}
