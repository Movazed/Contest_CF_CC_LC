#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define word char
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string st;
    string re = "", ev = "";
    ll id = 0, dig;

    cin >> st;

    for(char c : st){
        dig = c - '0';

        if(dig % 2 == 0){
            ev += c;
        }
    }
    reverse(ev.begin(), ev.end());

    for(char c : st){
        dig = c - '0';

        if(dig % 2 == 0){
            re += ev[id++];
        } else {
            re += c;
        }

    }

    cout << re << "\n";

return 0;

}