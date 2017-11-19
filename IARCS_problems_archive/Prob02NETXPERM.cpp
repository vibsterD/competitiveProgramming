#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int A[n];
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> A[j];
        }
        next_permutation(A, A+n);
        for(auto X:A)cout << X;
        cout << endl;
    }
}
