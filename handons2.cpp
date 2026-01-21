#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define word char
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin >> st;

    for(word c : st){
        ll dig = c - 'A' + 1;

        if(isupper(c)){
            cout << dig << "";
        } else {
            cout << c << "";
        }
    }
return 0;

}