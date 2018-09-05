//NOTE: istringstream is not time-efficient and may cause TLE!!!!!
#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

string a;int b,c;
int dp[10000][101];

bool isWin(string i, int j){
    /*istringstream d(i);*/int r=0,y=1000; /*d>>r;*/
    for(int f=0; f<4; f++){
        r+=(i[f]-'0')*y;
        y/=10;
    }
    if(j>b&& !(b&1)){
        if(r>c)return 1;
        return 0;
    }else if(j>b &&(b&1)){
        if(r>c)return 0;
        return 1;
    }
    if(dp[r][j]!=-1)return dp[r][j];
    string p;
    for(int f=0; f<4; f++){
        p=i;
        if(p[f]!='9'){
            p[f]++;
        }else p[f]='0';
        if(!isWin(p,j+1)){
            dp[r][j]=1;
            return 1;
        }
    }
    dp[r][j]=0;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        cin >> a>>b;

        istringstream r(a);
        r>>c;
        int y=1000;c=0;
        for(int f=0; f<4; f++){
            c+=(a[f]-'0')*y;
            y/=10;
        }
        memset(dp, -1, sizeof(dp));
        if(isWin(a,1))cout << "Ada" << endl;
        else cout << "Vinit" << endl;
    }
}
