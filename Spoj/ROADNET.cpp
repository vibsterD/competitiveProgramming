#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll dp[n+1][n+1];
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				dp[i][j]=INF;
			}
		}
		set <pair<int,int> > ans;
		int x;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				ans.insert({i,j});
				cin >> x;
				dp[i][j]=dp[j][i]=x;
			}
			dp[i][i]=0;
			ans.erase({i,i});
		}
		//cout << ans.size() << endl;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=n; k++){
					if(i!=j && i!= k){
						if(dp[j][k]==dp[j][i]+dp[i][k]){
							//cout << j << ' ' << k << ' ' << i << endl;
							ans.erase({j,k});
							ans.erase({k,j});
                        }
					}
				}
			}
		}
		//cout << ans.size() << endl;
		for(auto b:ans){
			cout << b.first << ' ' << b.second << endl;
			ans.erase({b.second, b.first});
		}
	}
}
