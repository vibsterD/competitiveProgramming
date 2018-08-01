#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int n;
string A[101];
vector <int> node[26];
bool vis[26], recvis[26];
bool poss=1;

void makeGraph(){
    char a='a';
    for(int i=0; i<n-1; i++){
        int x=0;
        for(int j=0; j<A[i].size() && x<A[i+1].size(); j++,x++){
            if(A[i][j]!=A[i+1][x]){
                int l=A[i][j]-a, r=A[i+1][x]-a;
                node[l].push_back(r);
                break;
            }else if(x+1>=A[i+1].size())poss=0;
        }
    }
}
vector <int> ans;
void DFS(int i){
    if(vis[i]){
            if(recvis[i])poss=0;
            return;
    }
    recvis[i]=1;vis[i]=1;
    for(auto a: node[i]){
        DFS(a);
    }
    recvis[i]=0;
    ans.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++)cin >> A[i];
    makeGraph();
    for(int i=0; i<26; i++){
            if(!vis[i])DFS(i);
    }
    if(!poss){
        cout << "Impossible";
        return 0;
    }
    auto it1= ans.rbegin();
    while(it1!=ans.rend()){
        char y='a';
        int b= *it1;
        it1++;
        y+=b;
        cout << y;
    }
}
