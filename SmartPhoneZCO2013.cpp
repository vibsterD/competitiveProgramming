#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long int n;
    cin >> n;
    long long int R[n];
    for(int i=0;i<n;i++)cin >> R[i];
    sort(R,R+n);
    long long int ans[n];
    for(int i=0;i<n;i++){
        ans[i]=R[i]*(n-i);
    }
    cout<< *max_element(ans,ans+n);
}
