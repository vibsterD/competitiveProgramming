#include<iostream>
#include<utility>
#include<set>
#include<vector>
#include<algorithm>

#define endl '\n'

typedef long long int ll;

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    vector <pair<ll,ll>> intervals;
    ll a,b;
    for(int i=0;i<n;i++){
            cin >> a >> b;
            intervals.push_back(make_pair(a,b));
    }
    sort(intervals.begin(), intervals.end());

    ll min1, min2, count=0;
    while(intervals.size()>0){
            vector <pair<ll,ll>> temp;
            min1 = intervals[0].first; min2= intervals[0].second;
            for(int i=0;i<intervals.size(); i++){
                a=intervals[i].first;b=intervals[i].second;
                if(!(a>=min1 && a<=min2)){
                    temp.push_back(make_pair(a,b));
                }else{
                    min1 =a; if(b<min2)min2=b;
                }
            }
            intervals = temp;
            count++;
    }
    cout << count << endl;
}
