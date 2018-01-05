#include<bits/stdc++.h>
#define endl '\n'

typedef long long int ll;

using namespace std;

bool visited[301];
vector <int> cit[301];
//memset(visited, 0, 301);
int n, k;
bool isTrue(int a, int b){
    int c=0;
    for(auto node:cit[a]){
        if(binary_search(cit[b].begin(), cit[end].end(), node))
            c++;
    }
    if(c>=k)
        return true;
    else
        return false;
}

void dfs(int a){
    if(visited[a])return;
    visited[a]=true;
    for(int i=0; i<n; i++){
        if(isTrue(a,i))
            dfs(i);
        else
            continue;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    //set<int> ans;
    cin >> n >> k;
    //int temp[301];
    //vector <int> cit[n];
    for(int i=0; i<n; i++){
        int p;
        cin >> p;int temp;
        for(int j=0; j<p ;j++){
            cin >> temp;
	    cit[i].push_back(temp);
        }
        sort(cit[i].begin(), cit[i].end());
    }
    dfs(0);
    int ans=0;
    for(int i=0; i<n; i++){
        if(visited[i])
            ans++;
    }
    cout << ans;
}
