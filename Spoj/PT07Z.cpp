#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e9

typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cin >> n;
    vector <int>node[n];
    int x,y;
    for(int i=0; i<n-1; i++){
        cin >> x >> y;x--;y--;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    int e[n];
    bool z[n];
    pair <int,int> target;
    for(int j=0; j<2; j++){
        for(int i=0; i<n; i++)e[i]=INF;
        memset(z,0,sizeof(z));
        queue <int> q;
        if(j==0){
            e[0]=0;
            z[0]=1;
            q.push(0);
            target={0,0};
        }else{
            e[target.first]=0;
            z[target.first]=1;
            q.push(target.first);
            target={target.first, 0};
        }
        while(!q.empty()){
            int a=q.front();q.pop();
            for(auto u:node[a]){
                if(z[u])continue;
                z[u]=1;
                e[u]=e[a]+1;
                if(e[u]>target.second){
                    target={u,e[u]};
                }
                q.push(u);
            }
        }
    }
    cout << target.second << endl;
}
