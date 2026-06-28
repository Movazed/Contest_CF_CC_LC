#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define fr(i,a,b) for(ii i=(a);i<=(b);++i)

template<class t>
struct bx{
    virtual void run()=0;
    virtual ~bx(){}
};

template<class t>
struct sv:bx<t>{
    void run(){
        ii tt;
        cin>>tt;
        function<void()> sl;
        sl = [&](){
            ii n,x,m;
            cin>>n>>x>>m;
            ii *pl = (ii*)::operator new(sizeof(ii));
            ii *pr = (ii*)::operator new(sizeof(ii));
            *pl = x;
            *pr = x;
            fr(i,1,m){
                ii l,r;
                cin>>l>>r;
                (max(*pl,l)<=min(*pr,r))?
                    (void)(*pl=min(*pl,l),*pr=max(*pr,r)):
                    (void)0;
            }
            cout<<((*pr)-(*pl)+1)<<"\n";
            ::operator delete(pl);
            ::operator delete(pr);
        };
        fr(i,1,tt) sl();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bx<ll>* ob = static_cast<bx<ll>*>(new sv<ll>());
    auto fn = [&](){
        ob->run();
    };
    fn();
    delete ob;
    return 0;
}
