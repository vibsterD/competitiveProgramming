#include<iostream>
#include<limits.h>
#include<algorithm>
#define endl '\n'
 
typedef long long int ll;
 
using namespace std;
 
int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
 
    ll n; cin >> n;
    bool Check[1000001]={false};
    int R[n];
    for(int i=0; i<n;i++){
        cin >> R[i];
        Check[R[i]]=1;
    }
    sort(R,R+n);
    int ans =0, d,k,g;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            d=R[j]-R[i];
            k=R[j];
            g=2;
            while(1){
                k+=d;
                if(Check[k])g++;
                else break;
            }
            ans = max(ans, g);
        }
    }
    cout << ans << endl;
 
}
