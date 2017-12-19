#include <iostream>
using namespace std;
bool prime[10000]=false;
memset(prime,0,sizeof(prime));
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
	int t;
	cin >> t;
	while(t--){
		int a,b;cin>>a>>b;
		queue <int> q; int distance[10000], int digit[4];
		memset(distance, -1, sizeof(distance));
		distance[a]=0;q.push(a);
		while(!q.empty()){
			int num=q.front();
			for(int i=0; i<=3; i++){
				toArr(digit, num);
				for(int j=0; j<10; j++){
					digit[i]=j;
					int check=toNum(digit);
					if(Prime[check]){
						distance[check]=distance[num]+1;
						q.push(check);
					}
				}
			}
		}
		if(distance[b]=-1)cout<<"Impossible"<<endl;
		else cout<<distance[b]<<endl;
	}
}
