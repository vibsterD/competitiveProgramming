#include<iostream>
using namespace std;
 
int main(){
    int n, h;
    cin >> n >> h;
    int s[n];
    for(int i=0;i<n;++i){
        cin >> s[i];
    }
    int k;
    int i=0;
    int f=0;
    while(cin>>k){
            if(k==0)break;
        switch(k){
        case 1:
            if(i>0)i-=1;
            break;
        case 2:
            if(i<n-1)i+=1;
            break;
        case 3:
            if(s[i]>0 && f==0){
                    f=1;s[i]--;
            }
            break;
        case 4:
            if(s[i]<h && f==1){
                f=0;
                s[i]++;
            }
            break;
 
        }
 
    }
    for(int k=0;k<n;++k){
        cout << s[k] << " " << flush;
    }
 
}
