#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

int n,m;
//node={w,{u,v,a,b}}
vector <pair<long double,tuple<int,int,int,int>>> node;
int id[100005];
ll A, B;

void initialize(){
    for(int i=0; i<=n; i++)id[i]=i;
}

int root(int i){
    while(i!=id[i]){
        id[i]=id[id[i]];
        i=id[i];
    }
    return i;
}

void Union(int i, int j){
    i=root(i);j=root(j);
    id[i]=id[j];
}

long double kruskal(){
    long double minCost=0;
    A=0;B=0;
    int u,v;
    for(auto b:node){
        u=get<0>(b.second);v=get<1>(b.second);
        if(root(u)==root(v))continue;
        minCost+=b.first;
        A+=get<2>(b.second);
        B+=get<3>(b.second);
        Union(u,v);
    }
    return minCost;
}

void Graph(long double X){
    for(int i=0; i<m; i++){
        node[i].first= ((X*get<3>(node[i].second))- get<2>(node[i].second));
    }
    sort(node.begin(), node.end());
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    cin >> n >> m;
    int u,v,a,b;
    for(int i=0; i<m; i++){
        cin >> u >> v >> a >> b;
        node.push_back({0,{u,v,a,b}});
    }
    long double hi=1e7, lo=0,mid,CC;
    int r=50;
    while(r--){
        mid=lo+(hi-lo)/2.0;
        Graph(mid);
        initialize();
        CC=kruskal();
        if(CC>=0){
            hi=mid;
        }else{
            lo=mid;
        }
    }
    ll AA=A;
    for(int i=sqrt(AA); i>1; i--){
        if(A%i==0 && B%i==0){
            A/=i;
            B/=i;
        }
    }
    cout << A << '/' << B << endl;
}
