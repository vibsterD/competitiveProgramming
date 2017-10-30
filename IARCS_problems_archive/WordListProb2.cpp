#include<iostream>
#include<sstream>
#include<set>

#define endl '\n'

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string in="", r;
    int n;
    cin >> n;

    char k = 39;//asccii for apostrophe
    set <string> s;
    cin.ignore();
    for(int h=0; h<n; h++){
        string temp;
        //cin >> temp;
        getline(cin, temp);
        in = in+ " " + temp;
    }
    for(int i=0; i<in.length(); i++){
            in[i]= tolower(in[i]);
            if(in[i]==k|| in[i]=='.' || in[i]==';' || in[i]==':' || in[i]==',')
                in[i] = ' ';
    }
    istringstream iss(in);
    while(iss>>r){
        s.insert(r);
    }
    cout << s.size() << endl;
    for(auto x:s)
        cout << x << endl;
}
