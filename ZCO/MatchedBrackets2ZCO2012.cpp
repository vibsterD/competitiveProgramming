#include<iostream>
#include<stack>
#include<algorithm>

#define endl '\n'

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long int n;
    cin >> n;
    stack <int> gg,gq;
    stack <long long int> ad;
    int k[n];
    long long int r1=0,r2=0,mad=1;
    for(int i=0;i<n;i++){
        cin >> k[i];
        if(k[i]==1||k[i]==3){
            if(gg.empty()){
                ad.push(1);
                mad=max(mad,ad.top());
            }else if(k[i]!=gg.top()){
                ad.push(ad.top()+1);
                mad=max(mad,ad.top());
            }else{
                ad.push(ad.top());
                mad=max(mad,ad.top());
            }
            gg.push(k[i]);
            gq.push(i);
        }else{
            ad.pop();
            if(gg.top()==1){
                r1=max(r1,(long long int)i-gq.top()+1);
                gg.pop();gq.pop();
            }else{
                r2=max(r2,(long long int) i-gq.top()+1);
                gg.pop();gq.pop();
            }
        }
    }




    cout << mad << " " << r1 << " " << r2 << endl;
}
