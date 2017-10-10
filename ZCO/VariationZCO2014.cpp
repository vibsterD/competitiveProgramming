#include<iostream>
#include<algorithm>

using namespace std;
long long int n=0;
long long int R[65001];
long long int calc(long long int u){
    long long int lo=0,hi=n-1,ans=-1;
    while(lo<=hi){
        long long int mid = (lo+hi)/2;
        if(R[mid]<u){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}

int main(){
    long long int k;
    cin >> n >> k;
    //long long int R[n];
    for(int i=0;i<n;i++)cin >> R[i];
    sort(R,R+n);
    long long int CC=0, num;
    for(int i=0;i<n;i++){
        num=max((long long int)0,calc(k+R[i]));
        if(num==0){
            continue;
        }else{
            num=n-num;
            CC+=num;
        }
    }
    cout << CC << endl;


}
