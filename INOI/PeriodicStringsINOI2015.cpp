#include<bits/stdc++.h>

typedef long long int ll;

using namespace std;

ll PowM(int a, int b, int m){
    ll ans=1;
    while(b>0){
        if(b%2==1)ans=(ans*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return ans%m;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    ll ans=PowM(2,n,m);
    bool flag=true;vector <int>en;
    for(int i=n/2;i>0;i--){
        flag=true;
        if(n%i!=0)continue;
        else{
            for(auto e:en){
                if(e%i==0)flag=false;
            }
            if(flag){
                ans-=PowM(2,i,m);
                en.push_back(i);
            }
        }
    }
    //if(ans<0)ans+=m;
    cout << ans%m;
    //cout<<endl<<"Execution time = "<<(float)clock()/CLOCKS_PER_SEC <<" s"<<endl;
}
