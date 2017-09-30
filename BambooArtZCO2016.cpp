#include<iostream>
#include<limits.h>
#include<algorithm>
#define endl '\n'

typedef unsigned long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);

    ll n; cin >> n;
    int Check[100001]={0};
    ll R[n];
    for(int i=0; i<n;i++){
        cin >> R[i];
        Check[R[i]]=1;
    }
    sort(R,R+n);
    int ans =2, d,k,g;
    for(int i=0;i<n;i++){
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
