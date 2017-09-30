#include<iostream>
#include<algorithm>

#define INF -20000
#define endl '\n'

using namespace std;
bool valid[505][505];

bool possible(int n){
    unsigned long int p[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0;j<=n;j++)p[i][j]=0;
    }
    p[1][1]=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(valid[i-1][j-1])
                p[i][j]+= p[i-1][j] + p[i][j-1];
            else
                p[i][j]=0;
        }
    }
    if(p[n][n]==0){
        return false;
    }else return true;

}


int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    int n,m;
    cin >> n >> m;

    int grid[n][n]={0};
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++)cin >> grid[i][j];
    }
    //bool valid[n][n]={false};
    int x,y,k;//vertex validator
    while(m--){
        cin >> x >> y >> k;
        x--;y--;
        for(int x1=max(x-k,0); x1<=min(x+k,n-1); x1++){
            for(int y1=max(y-k,0); y1<=min(y+k,n-1); y1++){
                if(abs(x-x1)+abs(y-y1)<=k)valid[x1][y1]=true;
            }
        }
    }
    long int ans[n][n]={0};
    for(int i=0;i<n;i++){
        ans[0][0]=grid[0][0];
        if(i>0){
            ans[0][i]=grid[0][i]+ans[0][i-1];
            ans[i][0]=grid[i][0]+ans[i-1][0];
        }
        if(!valid[0][i])ans[0][i]=INF;
        if(!valid[i][0])ans[i][0]=INF;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(valid[i][j]){
                ans[i][j]=max(ans[i-1][j], ans[i][j-1])+grid[i][j];
            }else
                ans[i][j]=INF;
        }
    }

    if(possible(n)){
        cout << "YES" << endl;
        cout << ans[n-1][n-1] << endl;
    }else
        cout << "NO" << endl;

}
