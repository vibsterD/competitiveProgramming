#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll PowM(ll a, int b, ll m){
    ll ans=1;
    a=a%m;
    while(b>0){
        if(b%2==1)ans=(ans*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    //if(ans<0)ans+=m;
    return ans%m;
}

ll PRRS(ll n, ll m){
    ll pp[n];
    ll ans =0;vector <int> c;
    for(ll i=1; i<((n/2)+1); i++){
        if(n%i!=0)continue;
        //ans=(ans+PowM(2,i,m))%m;
        pp[i]=PowM(2,i,m);
        for(auto e:c){
            if(i%e==0){
                //ans=(ans-pp[e])%m;
                pp[i]=(pp[i]-pp[e])%m;
            }
        }//cout << i << ": " << pp[i] << endl;
        c.push_back(i);
    }
    for(auto e:c)ans+=pp[e];//cout <<"FIN:: " << ans%m << endl;
    return ans%m;
}


int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;

    ll ans3= (PowM(2,n,m)-PRRS(n, m))%m;
    if(ans3<0)ans3+=m;

    cout << ans3%m;
    //cout<<endl<<"Execution time = "<<(float)clock()/CLOCKS_PER_SEC <<" s"<<endl;
    //cout << endl << -32%41;
}
