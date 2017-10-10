#include <iostream>
#include<algorithm>
//#include<stdlib>

#define endl '\n'


typedef long long int ll;

using namespace std;



int main(){
    std::ios_base::sync_with_stdio(false);cout.tie(NULL);

    ll n;
    cin >>n;
    ll A[n];
    //ll ans = 0;

    for(ll i=0; i<n; i++)cin >> A[i];
    sort(A, A+n);
    ll s=0,s1=0;
    for(ll i=0; i<n; i++){
        s+=i*A[i];
        s1+=(n-(i+1))*A[i];
    }

    cout << abs(s-s1) << endl;

}
