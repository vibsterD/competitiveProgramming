#include<bits/stdc++.h>
#define endl '\n'

typedef long long int ll;

using namespace std;

bool valid[320][320];
int R,C,D;
ll ans[320][320][320][2];
bool dpp[320][320][320][2];


ll dp(int i, int j, int k, bool s){
    if(i<0||j<0)return 0;
    if(!valid[i][j])return 0;
    if(k>=D && D<max(R,C))return 0;
    if(i==0&&j==0)return 1;
    if(dpp[i][j][k][s])return ans[i][j][k][s];
    if(s){
        ans[i][j][k][s]=(dp(i-1,j,k+1,s)+dp(i,j-1,0,0))%20011;
        dpp[i][j][k][s]=true;
    }else{
        ans[i][j][k][s]=(dp(i-1,j,0,1)+dp(i,j-1,k+1,s))%20011;
        dpp[i][j][k][s]=true;
    }
    return ans[i][j][k][s];
}


void makeFalse(){
    for(int i=0; i<=R; i++){
        for(int j=0; j<=C; j++){
            for(int k=0; k<=D; k++){
                for(int t=0; t<2; t++){
                    dpp[i][j][k][t]=false;
                    ans[i][j][k][t]=0;
                }
            }
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    //ifstream files;
    //files.open("case.txt");
    cin >> R >>C >>D;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>valid[i][j];
        }
    }
    R--;C--;
    makeFalse();
    if(valid[R][C])
        cout <<  (dp(R-1,C,0,1) + dp(R,C-1,0,0))%20011;
    else cout << 0;

}
