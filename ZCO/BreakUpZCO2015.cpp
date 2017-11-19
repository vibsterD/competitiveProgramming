#include<iostream>
#include<algorithm>
#define endl '\n'

typedef long long int ll;

using namespace std;

ll A[301];
int dpp[301];
int n, k;
bool check[301];

bool isPalin(int i, int j){
    if(i==j)return true;
    while(i<=j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;j--;
    }
    return true;
}

int dp(int i){
    int best=i+1;
    if(i==-1)return 0;
    if(i==0)return 1;
    if(check[i]==1){
        return dpp[i];
    }
    for(int j=0; j<=i; j++){
        if(isPalin(j,i)){
            best=min(best, 1+dp(j-1));
        }
    }
    dpp[i]= best;
    check[i]=true;
    return dpp[i];
}
void makeFalse(){
    for(int i=0; i<=n; i++)check[i]=false;
}


int main(){
    std::ios_base::sync_with_stdio(false); cout.tie(NULL);
    cin >> n;
    for(int i =0; i<n; i++){
        cin>>A[i];
    }
    cout << dp(n-1) << endl;
}
