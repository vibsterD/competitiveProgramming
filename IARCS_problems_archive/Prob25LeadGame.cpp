#include<iostream>
using namespace std;
 
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int u,v,sum1=0,sum2=0;
    int l=0,w=0;
    for(int i=0;i<n;++i){
        cin >> u >> v;
        sum1+=u;
        sum2+=v;
        if(sum1>sum2){
            if(sum1-sum2>l){
                    l=sum1-sum2;
                    w=1;
            }
        }else{
            if(sum2-sum1>l){
                    l=sum2-sum1;
                    w=2;
            }
        }
    }
 
    cout << w << " " << l << endl;
 
}
