#include <bits/stdc++.h>

using namespace std;

vector <int> node[100005];
bool z[100005];
int k=0;
void DFS(int i){
    if(z[i])return;
    z[i]=1;
    k++;
    for(auto b:node[i]){
        DFS(b);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n,p;
    cin >> n >> p;
    int x,y;
    for(int i=0; i<n; i++)node[i].clear();
    for(int i=0; i<p; i++){
        cin >> x >> y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    memset(z,0,sizeof(z));
    long long int ans=0;
    vector<int> kk;
    for(int i=0; i<n; i++){
        if(!z[i]){
            k=0;
            DFS(i);
            kk.push_back(k);
        }
    }
    if(kk.size()==1){
        cout << 0 << endl;
        return 0;
    }
    long long int sk[kk.size()];
    sk[0]=kk[0];
    for(int i=1; i<kk.size(); i++){
        sk[i]=sk[i-1]+kk[i];
    }
    for(int i=kk.size()-1; i>0; i--){
        ans+=kk[i]*sk[i-1];
    }
    cout << ans << endl;
    return 0;
}
