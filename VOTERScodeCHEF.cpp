#include<iostream>
#include<vector>
#include<set>

#define endl '\n'

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long int x,y,z,a;
    cin >> x >> y >>z;
    vector<int> x1,y1,z1;
    set<int> f;
    for(int i=0;i<x; i++){
            cin >>a;
            x1.push_back(a);
    }
    for(int i=0;i<y; i++){
            cin >>a;
            y1.push_back(a);
    }
    for(int i=0;i<z; i++){
            cin >>a;
            z1.push_back(a);
    }
    long int i=0, j=0;
    while(i<x&&j<y){
        if(x1[i]==y1[j]){
            f.insert(x1[i]);
            i++;j++;
        }else if(x1[i]<y1[j]){
            i++;
            continue;
        }else if(x1[i]>y1[j]){
            j++;
            continue;
        }
    }

    i=0;j=0;
    while(i<x&&j<z){
        if(x1[i]==z1[j]){
            f.insert(x1[i]);
            i++;j++;
        }else if(x1[i]<z1[j]){
            i++;
            continue;
        }else if(x1[i]>z1[j]){
            j++;
            continue;
        }
    }

    i=0;j=0;
    while(i<y&&j<z){
        if(y1[i]==z1[j]){
            f.insert(y1[i]);
            i++;j++;
        }else if(y1[i]<z1[j]){
            i++;
            continue;
        }else if(y1[i]>z1[j]){
            j++;
            continue;
        }
    }


    cout << f.size() << endl;
    for(auto k : f){cout << k << endl;}
}
