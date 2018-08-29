#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

class SegmentTree{
    vector <ll> st,A;
    int n;
    ll left(ll i){return i<<1;};
    ll right(ll i){return (i<<1)+1;}

    void build(ll node, int i, int r){
        if(i==r){
            st[node]=A[i];
            return;
        }
        int mid=(i+r)/2;
        build(left(node), i, mid);
        build(right(node), mid+1, r);
        st[node]=st[left(node)]+st[right(node)];
    }

    void update(ll node, int i, int r, int idx, ll val){
        if(i==r){
            st[node]+=val;
            A[idx]+=val;
            return;
        }
        int mid=(i+r)/2;
        if(idx>=i && idx<=mid){
            update(left(node), i, mid, idx, val);
        }else{
            update(right(node), mid+1, r, idx, val);
        }
        st[node]=st[left(node)]+st[right(node)];
    }

    ll rsq(ll node, int i, int j, int l, int r){
        if(l>j || r<i)return 0;
        if(l<=i && r>=j)return st[node];
        int mid=(i+j)/2;
        return rsq(left(node), i, mid, l, r) + rsq(right(node), mid+1, j, l, r);
    }

    public:

    SegmentTree(vector <ll> &_A){
        A=_A;
        n=A.size();
        st.assign(4*n, 0);
        build(1,0,n-1);
    }
    void update(int idx, ll val){update(1, 0, n-1, idx, val);}
    ll rsq(int l, int r){return rsq(1, 0, n-1, l, r);}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cin >> n;
    vector <ll> A;ll a;
    for(int i=0; i<n; i++){
        cin >> a;
        A.push_back(a);
    }
    SegmentTree FT(A);
    int q;
    cin >>q;
    char u;
    ll l,r;
    while(q--){
        cin >>u >> l >>r;
        if(u=='u'){
            l--;
            FT.update(l,r);
        }else{
            l--;r--;
            cout << FT.rsq(l,r) << endl;
        }
    }
}
