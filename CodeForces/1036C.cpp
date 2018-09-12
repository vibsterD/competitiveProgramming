#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

vector <int> L, R;
ll DP[20][5][2][2];

ll solve(int pos, int f, bool sL, bool sR){
    if(f>3){
        return 0;
    }
    if(pos == R.size()){
        if(f<=3)return 1;
        return 0;
    }
    if(DP[pos][f][sL][sR]!=-1)return DP[pos][f][sL][sR];
    int lp=0,up=9;
    if(!sL){
        lp=L[pos];
    }
    if(!sR){
        up=R[pos];
    }
    ll ans=0;
    for(int i=lp; i<=up; i++){
        if(!sL || !sR){
            if(!sL && !sR){
                ans+=solve(pos+1,i!=0?f+1:f, i>L[pos], i<R[pos]);
                continue;
            }
            if(!sL){
                ans+=solve(pos+1, i!=0?f+1:f, i>L[pos], 1);
                continue;
            }
            ans+=solve(pos+1, i!=0?f+1:f, 1, i<R[pos]);
            continue;
        }
        ans+=solve(pos+1, i!=0?f+1:f, 1, 1);
    }

    DP[pos][f][sL][sR]=ans;
    return DP[pos][f][sL][sR];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    ll t, l, l1, r, r1;
    cin >> t;
    while(t--){
        cin >> l >> r;
        L.clear();
        R.clear();
        l1=l;r1=r;
        while(r1>0){
            R.push_back(r1%10);
            r1/=10;
        }
        while(l1>0){
            L.push_back(l1%10);
            l1/=10;
        }int k=R.size()-L.size();
        for(int i=0;i<k; i++)L.push_back(0);
        reverse(L.begin(),L.end());
        reverse(R.begin(),R.end());
        memset(DP, -1, sizeof(DP));
        cout << solve(0, 0, 0, 0) << endl;
    }
}
