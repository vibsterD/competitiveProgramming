//Insight for the code/solution: https://www.quora.com/What-is-the-correct-approach-to-solve-SPOJ-com-Problem-ACMAKER
#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

vector <string> Wlist;
string acr;
int DP[151][151];
int dp[151][151];
void subProb(int i, int j, int k){
    //if(i+k>acr.size())return 0;
    int m=Wlist[i].size();
    for(int r=0; r<m+1; r++)
        for(int f=0;f<k+1; f++)dp[f][r]=0;
    for(int r=0; r<m+1; r++){
        dp[r][0]=1;
    }
    for(int r=1; r<k+1; r++){
        dp[0][r]=0;
    }
    for(int r=0; r<m; r++){
        for(int f=0; f<k; f++){
            if(tolower(acr[j+f])==Wlist[i][r]){
                dp[r+1][f+1]=dp[r][f]+dp[r][f+1];
            }else{
                dp[r+1][f+1]=dp[r][f+1];
            }
        }
    }

    /*cout << endl << endl << flush;
    for(int r=0; r<=m; r++){
        for(int f=0; f<=k; f++)cout<<dp[r][f] << ' ' << flush;
        cout << endl << flush;
    }
    cout << endl << endl << flush;*/
    //return dp[k][m];
}

void makeFalse(){
    for(int i=0; i<=acr.size(); i++){
        for(int j=0; j<=Wlist.size(); j++)DP[i][j]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    unordered_map <string, bool> iWrd;
    while(1){
        int n;
        cin >> n;
        if(!n)break;
        iWrd.clear();
        string s;
        for(int i=0; i<n; i++){
            cin >>s;
            iWrd[s]=1;
        }
        string ch;
        while(1){
            cin >>acr;
            getline(cin, s);
            if(s==" CASE")break;
            istringstream ss(s);
            Wlist.clear();
            while(ss>>ch){
                if(iWrd[ch])continue;
                Wlist.push_back(ch);
            }
            //makeFalse();
            memset(DP, 0, sizeof(DP));
            DP[0][0]=1;
            for(int i=0; i<Wlist.size(); i++){
                for(int j=0; j<acr.size(); j++){
                    int mx=min(acr.size()-j, Wlist[i].size());
                    //cout<< "FFF" << flush;
                    subProb(i,j,mx);
                    //cout<< "FFF" << i << ' ' << j << ' '<< mx << endl << flush;
                    for(int k=1; k<=mx; k++){
                        DP[i+1][j+k]+=DP[i][j]*dp[Wlist[i].size()][k];
                    }
                }
            }
            if(DP[Wlist.size()][acr.size()])cout << acr <<" can be formed in " <<DP[Wlist.size()][acr.size()]<< " ways" << endl;
            else cout << acr<< " is not a valid abbreviation" << endl;
        }
    }
}
