#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

class SegmentTree{
    vector <int> st,A, Lazy, Lazy2;
    vector <bool> Lazy1;
    int n;
    int left(int i){return i<<1;}
    int right(int i){return (i<<1)+1;}

    void LazyCheck(int node, int l, int r){
        if(Lazy1[node]){
            if(Lazy[node]==0){
                st[node]=0;
                if(l!=r){
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=0;
                }
            }else if(Lazy[node]==1){
                if(l!=r){
                    st[node]=r-l+1;
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=1;
                }else{
                    st[node]=1;
                }
            }else{
                if(l!=r){
                    st[node]=(r-l+1)-st[node];
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=3;
                }else{
                    st[node]=!st[node];
                }
            }
            Lazy1[node]=0;
        }
    }

    void build(int node, int i, int j){
        if(i==j){
            st[node]=A[j];
        }else{
            build(left(node), i, (i+j)/2);
            build(right(node), (i+j)/2+1, j);
            st[node]=st[left(node)]+st[right(node)];
        }
    }

    void update(int node, int l, int r, int i, int j, int type){
        LazyCheck(node,l,r);
        if(l>j || r<i)return;
        if(l>=i && r<=j){
            if(type==0){
                st[node]=0;
                if(l!=r){
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=0;
                }
            }else if(type==1){
                if(l!=r){
                    st[node]=r-l+1;
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=1;
                }else{
                    st[node]=1;
                }
            }else{
                if(l!=r){
                    st[node]=(r-l+1)-st[node];
                    Lazy1[left(node)]=Lazy1[right(node)]=1;
                    Lazy[left(node)]=Lazy[right(node)]=2;
                }else{
                    st[node]=!st[node];
                }cout << "ABC: " << st[node] << 'l' << l << " " << r<< endl;
            }
            return;
        }
        update(left(node), l, (l+r)/2, i, j, type);
        update(right(node), (l+r)/2+1, r, i, j, type);
        st[node]=st[left(node)]+st[right(node)];

    }

    int rmq(int node, int l, int r, int i, int j){
        LazyCheck(node, l, r);
        if(l>i || r<i)return 0;
        if(l>=i && r<=j)return st[node];
        int p1=rmq(left(node), l, (l+r)/2, i, j);
        int p2=rmq(right(node), (l+r)/2+1, r, i, j);
        //cout << "asd " << p1 << ' ' << p2 << endl;
        return p1+p2;
    }

    public:

    SegmentTree(const vector <int> &_A){
        A=_A;
        n=A.size();
        st.assign(4*n,0);
        Lazy1.assign(4*n,0);
        Lazy2.assign(4*n,0);
        Lazy.assign(4*n,0);
        build(1, 0, n-1);
    }
    void update(int i, int j, int type){update(1, 0, n-1, i, j, type);}
    int rmq(int i, int j){return rmq(1, 0, n-1, i, j);}
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    for(int T=1; T<=t; T++){
        int m,t1;
        cin >> m;
        string pirates="",temp;
        while(m--){
            cin >> t1>>temp;
            while(t1--){
                pirates+=temp;
            }
        }
        vector <int> A;A.clear();
        for(int i=0; i<pirates.size(); i++){
            A.push_back(pirates[i]-'0');
        }
        cout << pirates << endl;
        SegmentTree Pir(A);
        int q,cc=1;
        cin >> q;
        char Q;int a,b;
        cout << "Case " << T << ':' << endl;
        while(q--){
            cin >> Q >> a >> b;
            if(Q=='F'){
                Pir.update(a,b,1);
            }else if(Q=='E'){
                Pir.update(a,b,0);
            }else if( Q=='I'){
                Pir.update(a,b,2);
            }else{
                cout << 'Q' << cc++ << ": " << Pir.rmq(a,b) << endl;
            }
        }
    }

}
