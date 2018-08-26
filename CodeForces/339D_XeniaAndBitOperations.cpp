#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;
//A.size() is a perf power of 2 --> SegmentTree would be a Perfect BinaryTree
class SegmentTree{
    vector <ll> st, A;
    vector <bool> OP;
    ll n;
    ll left(int i){return i<<1;}
    ll right(int i){return (i<<1)+1;}
//1->OR & 0->XOR
    void build(ll node, ll i, ll j){
        if(i==j){
            st[node]=A[i];
            OP[node]=1;
            return;
        }
        build(left(node), i, (i+j)/2);
        build(right(node), (i+j)/2+1, j);
        if(OP[left(node)]){
            st[node]= st[left(node)]|st[right(node)];
            OP[node]=0;
        }else{
            st[node]= st[left(node)]^st[right(node)];
            OP[node]=1;
        }
    }
    void update(ll node, ll i, ll j,  ll idx, ll val){
        if(i==j){
            st[node]=val;
            A[idx]=val;
            return;
        }
        ll mid=(i+j)/2;
        if(idx>=i && idx<=mid){
            update(left(node), i, mid, idx, val);
        }else{
            update(right(node), mid+1, j, idx, val);
        }
        if(OP[left(node)]){
            st[node]=st[left(node)]|st[right(node)];
        }else{
            st[node]=st[left(node)]^st[right(node)];
        }
    }

    public:

    SegmentTree(const vector<ll> &_A){
        A=_A;
        n = A.size();
        st.assign(4*n,0);
        OP.assign(4*n,0);
        build(1,0,n-1);
    }
    ll Query(){return st[1];}
    void update(ll idx, ll val){update(1, 0, n-1, idx, val);}
};


int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n,m;
    cin >> n>> m;
    vector <ll> A;
    ll b;
    for(ll i=0; i<(1<<n); i++){
        cin >> b;
        A.push_back(b);
    }
    SegmentTree ans(A);
    ll a;
    while(m--){
        cin >> a >> b;a--;
        ans.update(a,b);
        cout << ans.Query() << endl;
    }
}
