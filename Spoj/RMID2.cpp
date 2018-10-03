//intiution behing logic: median devides the sequence in elements greater that it and less than it
//we can maintain both of these halves with a minMax priority queue
#include<bits/stdc++.h>
#define endl '\n'
#define INF 1e18

typedef long long int ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int t;
    cin >> t;
    int n;
    priority_queue <int> mn,mx;
    while(cin >> n){
        if(n==0){
            t--;
            if(!t)break;
            while(!mn.empty())mn.pop();
            while(!mx.empty())mx.pop();
            cout << endl;
            continue;
        }
        if(n==-1){
            if(mn.size()>0&&mx.size()>0){
                if(mx.size()>mn.size()){
                    cout << mx.top() << endl;
                    mx.pop();
                }else if(mn.size()>mx.size()){
                    cout << -mn.top() << endl;
                    mn.pop();
                }else{
                    cout << mx.top() << endl;
                    mx.pop();
                }
            }else{
                if(mn.size()>0){
                    cout << -mn.top() << endl;
                    mn.pop();
                }else{
                    cout << mx.top() << endl;
                    mx.pop();
                }
            }
            continue;
        }
        if(mx.size()==0||mn.size()==0){
            if(!mx.size()){
                if(mn.size()){
                    int k=-mn.top();
                    if(n<=k){
                        mx.push(n);
                    }else{
                        mn.push(-k);
                        mx.pop();
                        mx.push(n);
                    }
                }else{
                    mx.push(n);
                }
            }else{
                if(mx.size()){
                    int k=mx.top();
                    if(n<k){
                        mx.pop();
                        mn.push(-k);
                        mx.push(n);
                    }else{
                        mn.push(-n);
                    }
                }else{
                    mn.push(-n);
                }
            }continue;
        }
        if(mx.size()==mn.size()){
            int a=mx.top(),b=-mn.top();
            if(n<=a){
                mx.push(n);
            }else{
                mn.push(-n);
            }
        }else{
            int a=mx.top(),b=-mn.top();
            if(mx.size()>mn.size()){
                if(n<=a){
                    mx.pop();
                    mn.push(-a);
                    mx.push(n);
                }else{
                    mn.push(-n);
                }
            }else{
                if(n<=b){
                    mx.push(n);
                }else{
                    mn.pop();
                    mx.push(b);
                    mn.push(-n);
                }
            }
        }
    }
}
