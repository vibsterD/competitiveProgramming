#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool prime[10000];
//memset(prime,0,sizeof(prime));
void PrimeSeive(){
	for(int p=2;p*p<=9999;++p){
		if(!prime[p]){
			for(int i=p*2; i<=9999; i+=p){
				prime[i]=true;
			}
		}
	}
}

void toArr(int a[], int n){
	int temp=n;
	for(int i=3;i>=0;i--){
		a[i]=temp%10;
		temp/=10;
	}
}
int toNum(int a[]){
	int temp=0;
	for(int i=0;i<4;i++){
		temp=temp*10 +a[i];
	}
	return temp;
}
int main() {
	std::ios_base::sync_with_stdio(false); cin.tie(NULL);
	PrimeSeive();
	int t;
	cin >> t;
	while(t--){	
		int a,b;cin>>a>>b; //cout << a << " " << b << endl;
		queue <int> q; int distance[10000], digit[4];
		memset(distance, -1, sizeof(distance));
		distance[a]=0;q.push(a);
		while(!q.empty()){
			int num=q.front();
			for(int i=3; i>=0; i--){
				toArr(digit, num);
				for(int j=0; j<10; j++){
					digit[i]=j;
					int check=toNum(digit);//cout << check << endl;
					if((!prime[check])&&distance[check]==-1 && check>=1000){
						distance[check]=distance[num]+1;
						//if(check==b)cout << "DUMB" << distance[check] << endl;
						q.push(check);
					}
				}
			}
			q.pop();
		}
		if(distance[b]==-1)cout<<"Impossible"<<endl;
		else cout<<distance[b]<<endl;
		//cout << distance[b] << endl;
	}
}
