#include<iostream>
#include<algorithm>
/*NOTE TO SELF:
  WHY USE GREEDY OR ANY OTHER TECHNIQUE
  WHEN BRUTE FORCE WOULD DO THE WORK
*/

#define endl '\n'

typedef long int ll;

using namespace std;

ll solve(ll tab[], ll tab1[], ll n, ll k){
    //ll i=0;
    for(ll i=0;i<k;i++){
        sort(tab, tab+n, greater<ll>());sort(tab1, tab1+n, greater<ll>());
        //if(tab1[0]>=tab[0]){
            if(tab1[n-1]<tab[0])swap(tab1[n-1], tab[0]);
            sort(tab, tab+n, greater<ll>());sort(tab1, tab1+n, greater<ll>());
        //}
        /*if(tab[0]>=tab1[0]){
            if(tab[n-1]<tab1[0])swap(tab[n-1], tab1[0]);
            sort(tab, tab+n, greater<ll>());sort(tab1, tab1+n, greater<ll>());
        }*/
    }
    sort(tab, tab+n, greater<ll>());sort(tab1, tab1+n, greater<ll>());
    return tab1[0]+tab[0];// << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll tab[n], tab1[n], taba[n],taba1[n];
    for(ll i=0; i<n; i++){
            cin>> tab[i];
            taba[i]=tab[i];
    }
    for(ll i=0; i<n; i++){
            cin>> tab1[i];
            taba1[i]=tab1[i];
    }
    cout << min(solve(tab, tab1, n, k), solve(taba1, taba, n, k)) << endl;

}
