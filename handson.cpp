#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define word char
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;

    string str = to_string(n);

    ll lp = str.length();

    for(word c : str){
        ll dg = c - '0';

        if(dg % 2 == 0){
            cout << pow(dg, 2)<<""; 
        } else {
            cout << dg <<"";
        }
    }
return 0;

}