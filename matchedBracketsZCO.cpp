#include <iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);

    long int n;cin >>n;
    long int z;
    long int r=0,k=0,pos,coun=0,j,cm=0,b;
    for(long int i =0;i<n;i++){
        if(k==0){coun=0;j=i+1;}
        cin >> z;
        if(z==1)k++;else k--;
        if(k>r){
                r=k;pos=i+1;
        }
        coun++;if(coun>cm){cm=coun;b=j;}
    }

    cout << r << " " << pos << " " << cm << " " << b << endl;

}
