//Game Theory: Sprauge-Grunndy Theorem!!
#include<bits/stdc++.h>
#define endl '\n'
#define INF 999999999

typedef long long int ll;

using namespace std;

int A[50];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;ll c=0;
        for(int i=0; i<n; i++){
            cin >> A[i];
            if(A[i]==1)c++;
        }
        ll result=A[0];
        if(c==n){
            if(c&1){
                cout << "Brother" << endl;
                continue;
            }else{
                cout << "John" << endl;
                continue;
            }
        }
        for(int i=1; i<n; i++){
            result=result^A[i];
        }
        if(result)cout << "John" << endl;
        else cout << "Brother" << endl;
    }

}
