#include<iostream>
#include<algorithm>

using namespace std;

long long int n; long long int R[100000];

int calc(long long int u){
    int lo=0,hi=n-1,mid,ans=-1;

    while(lo<=hi){
        mid =(lo+hi)/2;
        if(R[mid]>=u){
            hi=mid-1;
        }else{
            ans=mid;
            lo=mid+1;
        }
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long int k,num=0;
    cin >> n >> k;
    for(int i=0;i<n;i++)cin >> R[i];
    sort(R,R+n);
    long long int cc=0;
    for(int i=0; i<n; i++){
        num=max(0,(calc(k-R[i])-i));
        cc=cc+num;
    }

    cout << cc <<endl;
}
