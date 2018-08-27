#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int n;
vector <pair<int ,int> > interval;
bool dp[100002];
ll dpp[100002];
const ll mod=100000000;

/*bool sortBySec(const pair<int,int>a, const pair<int,int> b){
  return a.second<b.second;
}*/

int next(int i){//returns the first interval which has its startTime >= EndTime of the ith interval
  auto it = lower_bound(interval.begin(), interval.end(), make_pair(interval[i].second,0));
  if(it==interval.end())return n+1;
  return it-interval.begin();
}

ll DP(int i){//int i represents ith interval the intervals sorted by their endtime
  if(i==n-1)return 1;
  if(i>=n)return 0;//handles when next(i) returns n+1
  if(dp[i])return dpp[i];
  dp[i]=1;
  dpp[i] = (DP(next(i))%mod+(1 + DP(i+1))%mod)%mod;
  return dpp[i];
}
void makeFalse(){
  for(int i=0; i<n+2; i++){
    dp[i]=dpp[i]=0;
    }
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int s,e;
  ll ans;
  while(cin >> n && n!=-1){
    interval.clear();
    for(int i=0; i<n; i++){
      cin >> s >> e;
      interval.push_back({s,e});
    }
    //sort(interval.begin(), interval.end(), sortBySec);
    sort(interval.begin(),interval.end());
    makeFalse();
    ans = DP(0);
    int res = 1 + floor(log10(ans));
    for(int i=0; i<8-res; i++)cout << 0;
    cout << ans << endl;
  }
}
