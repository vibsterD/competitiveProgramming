#include<iostream>
#include<algorithm>

#define endl '\n'

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    bool grid [100000][500];
    for(int i=0; i<100000; i++){
        for(int j=0; j<500; j++){
            grid[i][j]=true;
        }
    }
    int n;
    cin >> n;
    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        grid[a][b]=false;
    }
    long long int ans =0;
    for(ll i=0; i<500; i++){
        ll row=0, best=0;
        for(int j=0; j<100000; j++){
            if(!grid[j][i]){
                if(i>0)grid[j][i+1]=false;
                row=1;
            }else{
                row++;
                best=max(best, row);
            }
        }
        //best=max(best, row);
        ans=max(ans, (i+1) *best);
    }
    cout << ans;
}
