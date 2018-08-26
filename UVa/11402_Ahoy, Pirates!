#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

class SegmentTree{
    vector <int> st,A, Lazy;
    int n;
    int left(int i){return i<<1;}
    int right(int i){return (i<<1)+1;}

    void LazyCheck(int node, int l, int r){
        if(Lazy[node]){
            if(Lazy[node]==1){
                st[node]=0;
                if(l!=r){
                    Lazy[left(node)]=Lazy[right(node)]=1;
                }
            }else if(Lazy[node]==2){
                st[node]=r-l+1;
                if(l!=r){
                    Lazy[left(node)]=Lazy[right(node)]=2;
                }
            }else{
                st[node]=(r-l+1)-st[node];
                if(l!=r){                    
                    Lazy[(left(node))]=applyFlip(left(node));
                    Lazy[(right(node))]=applyFlip(right(node));
                }
            }
            Lazy[node]=0;
        }
    }

    int applyFlip(int i){
      if(Lazy[i]==1)return 2;
      if(Lazy[i]==2)return 1;
      if(Lazy[i]==3)return 0;
      return 3;
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
            if(type==1){
                st[node]=0;
                if(l!=r){
                    Lazy[left(node)]=Lazy[right(node)]=1;
                }
            }else if(type==2){
                 st[node]=r-l+1;
                if(l!=r){                   
                    Lazy[left(node)]=Lazy[right(node)]=2;
                }
            }else{
                st[node]=(r-l+1)-st[node];
                if(l!=r){
                    Lazy[left(node)]=applyFlip(left(node));
                    Lazy[right(node)]=applyFlip(right(node));
                }
            }
            return;
        }
        update(left(node), l, (l+r)/2, i, j, type);
        update(right(node), (l+r)/2+1, r, i, j, type);
        st[node]=st[left(node)]+st[right(node)];

    }

    int rmq(int node, int l, int r, int i, int j){
        if(l>j || r<i)return 0;
        LazyCheck(node, l, r);
        if(l>=i && r<=j)return st[node];
        int p1=rmq(left(node), l, (l+r)/2, i, j);
        int p2=rmq(right(node), (l+r)/2+1, r, i, j);
        return p1+p2;
    }

    public:

    SegmentTree(const vector <int> &_A){
        A=_A;
        n=A.size();
        st.assign(4*n,0);
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
        SegmentTree Pir(A);
        int q,cc=1;
        cin >> q;
        char Q;int a,b;
        cout << "Case " << T << ':' << endl;
        while(q--){
            cin >> Q >> a >> b;
            if(Q=='F'){
                Pir.update(a,b,2);
            }else if(Q=='E'){
                Pir.update(a,b,1);
            }else if( Q=='I'){
                Pir.update(a,b,3);
            }else{
                cout << 'Q' << cc++ << ": " << Pir.rmq(a,b) << endl;
            }
        }
    }

}
