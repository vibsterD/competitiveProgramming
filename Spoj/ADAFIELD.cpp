#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

multiset <ll, greater<ll> > X,Y;
multiset <ll> X1,Y1;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    ll n,m,q;
    while(t--){
        cin >> n >> m >> q;
        X.clear();X1.clear();
        Y.clear();Y1.clear();
        X.insert(n);X1.insert(0);X1.insert(n);
        Y.insert(m);Y1.insert(0);Y1.insert(m);
        int a,b,c;
        while(q--){
            cin >> a >> b;
            if(a){
                if(Y1.find(b)!=Y1.end()){
                    cout << (*X.begin())*(*Y.begin()) << endl;
                    continue;
                }
                auto it= Y1.lower_bound(b);
                int r=*it;it--;
                int l=*it;
                Y.erase(Y.find(r-l));
                Y.insert(b-l);Y.insert(r-b);
                Y1.insert(b);
            }else{
                if(X1.find(b)!=X1.end()){
                    cout << (*X.begin())*(*Y.begin()) << endl;
                    continue;
                }
                auto it= X1.lower_bound(b);
                int r=*it;it--;
                int l=*it;
                X.erase(X.find(r-l));
                X.insert(b-l);X.insert(r-b);
                X1.insert(b);
            }
            cout << (*X.begin())*(*Y.begin()) << endl;
        }
    }
}
