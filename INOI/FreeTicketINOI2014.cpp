#include<bits/stdc++.h>
#define endl '\n'
#define INF 9999999999

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int C;ll F;
    cin >> C >> F;
    bool edge[C][C];
    ll dist[C][C];
    for(int i=0; i<C; i++){
        for(int j=0;j<C; j++){
            dist[i][j]=INF;
            edge[i][j]=false;
        }
        dist[i][i]=0;
    }
    for(ll i=0; i<F; i++){
        ll x,y,p;cin >> x >> y >> p;x--;y--;
        edge[x][y]=edge[y][x]=true;
        dist[x][y]=dist[y][x]=p;
    }

    for(int k=0; k<C; k++){
        for(int i=0; i<C; i++){
            for(int j=0; j<C; j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    ll ans=-INF;
    for(int i=0; i<C; i++){
        for(int j=0; j<C; j++){
            if(dist[i][j]!=INF)
                ans=max(ans, dist[i][j]);
        }
    }
    cout << ans;
}
