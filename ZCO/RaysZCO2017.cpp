#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18
#pragma GCC optimize ("O3")

typedef long long int ll;

using namespace std;

const int NMAX=1e6+1;
vector<pair<int,char>> R[NMAX];
int n,m;

ll solve(){
    ll ans=0;
    for(ll i=1; i<=n; i++){
        bool W1=0,k=0;
        ll i1=1,j,iW=-1;
        for(auto b:R[i]){
            j=get<0>(b);
            if(i1>m||k)continue;
            if(j==m&&get<1>(b)=='b'){
                k=1;
            }
            if(j==m&&get<1>(b)=='x'&&!k){
                if(!W1){
                    ans+=(((j-i1+1)*((2*(j-i1+1))-(j-i1)))/2);
                }else{
                    ans+=(((iW-i1)*((2*(j-i1+1))-(iW-i1-1)))/2)+(((j-iW)*((2*(j-iW))-(j-iW-1)))/2);
                }
                continue;
            }
            if(j==i1&&(!W1||(W1&&j-iW==1))){
                i1++;
                continue;
            }
            if(get<1>(b)=='w'){
                if(W1){
                    ans+=(((iW-i1)*((2*(j-i1+1))-(iW-i1-1)))/2);
                    i1=iW+1;W1=1;
                    iW=j;
                }else{
                    W1=1;
                    iW=j;
                }
            }else{
                if(W1){
                    ans+=(((iW-i1)*((2*(j-i1+1))-(iW-i1-1)))/2)+(((j-iW-1)*((2*(j-iW))-(j-iW-2)))/2);
                    i1=j+1;W1=0;
                }else{
                    ans+=(((j-i1)*((2*(j-i1+1))-(j-i1-1)))/2);
                    i1=j+1;
                }
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int w,b;
    cin >> n >> m >> w >> b;
    int x,y;
    for(int i=0; i<w; i++){
        cin >> x >> y;
        R[x].push_back({y,'w'});
    }
    for(int i=0; i<b; i++){
        cin >> x >> y;
        R[x].push_back({y,'b'});
    }
    for(int i=1; i<=n; i++){
        R[i].push_back({m,'x'});
    }
    for(int i=1; i<=n; i++)sort(R[i].begin(),R[i].end());
    cout << solve() << endl;
}
