//algorithm: Floyd Warshall; Important observation: floyd warshall finds shortestPaths using a range of intermidiate nodes
//Thus, the prdering of the nodes for the formation of the chains doesn't matter and also the end points of the chain of edges
// also don't matter in the formation of its edge chain!
#include<bits/stdc++.h>
#define endl '\n'
#define INF 1000000

typedef long long int ll;

using namespace std;

int main(){
    int T, r=1; cin >> T;
    while(T--){
        //cout << "Case " << r++ << ":";
        int n; cin>>n;
        int dp[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=INF;
            }
            dp[i][i]=0;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int a; cin>>a;
                if(a!=-1)
                    dp[i][j]=dp[j][i]=a;
                else continue;
            }
        }
        int p; cin>>p;
        int List[p];vector <tuple<int,int,int>> Queries[p];
        for(int i=0; i<p; i++){
            int a; cin >>a; a--;
            List[i]=a;
            Queries[i].clear();
        }
        int Q; cin >>Q;
        int ans[Q];
        for(int i=0; i<Q; i++){
            int k,s,d;
            cin>>k>>s>>d;
            s--;d--;k--;
            if(k+1==0){
                if(dp[s][d]==INF)
                    ans[i]=-1;
                else
                    ans[i]=dp[s][d];
                continue;
            }
            Queries[k].push_back(make_tuple(s,d,i));
        }
        //cout << endl << endl << "Q: " << Q << endl << endl;
        for(int k=1; k<=p; k++){
            int node =List[k-1];
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j]=min(dp[i][j], dp[i][node]+dp[node][j]);
                }
            }
            for(auto e:Queries[k-1]){
                int s,d,j;
                tie(s,d,j)=e;
                if(dp[s][d]==INF)
                    ans[j]=-1;
                else
                    ans[j]=dp[s][d];
            }
        }
        cout << "Case " << r++ << ":";
        for(auto u:ans){
            cout << " " << u;
        }
        cout << endl;
    }
}
