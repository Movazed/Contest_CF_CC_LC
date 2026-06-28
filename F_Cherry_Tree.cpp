#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define fr(i,a,b) for(ii i=(a);i<=(b);++i)
#define frd(i,a,b) for(ii i=(a);i>=(b);--i)

const ii mx = 2000005;

template<class t>
struct bx{
    virtual void run()=0;
    virtual ~bx(){}
};

template<class t>
struct sv:bx<t>{

    vector<ii> *dp,*eg;
    ii n;

    sv(){
        dp=nullptr;
        eg=nullptr;
        n=0;
    }

    void run(){

        dp = (vector<ii>*)::operator new(sizeof(vector<ii>)*mx);
        eg = (vector<ii>*)::operator new(sizeof(vector<ii>)*mx);

        function<void(ii,ii)> df;

        df = [&](ii nw,ii ls)->void{

            ((nw!=1 && eg[nw].size()==1)?
                (void)(dp[nw]=vector<ii>{0,1,0}):
                (void)0);

            ((nw!=1 && eg[nw].size()==1)?
                (void)0:
                (void)(dp[nw]=vector<ii>{1,0,0}));

            for(auto it=eg[nw].begin();it!=eg[nw].end();++it){

                ii nx = *it;

                (nx==ls)?(void)0:(void)(
                    df(nx,nw),
                    [&](){
                        vector<ii> nc(3);
                        fr(i,0,2) fr(j,0,2){
                            vector<ii>* pnw = (vector<ii>*)((void*)dp + nw*sizeof(vector<ii>));
                            vector<ii>* pnx = (vector<ii>*)((void*)dp + nx*sizeof(vector<ii>));
                            ii *an = pnw->data();
                            ii *ax = pnx->data();
                            nc[(i+j)%3] |= (an[i] && ax[j]);
                        }
                        vector<ii>* pw = (vector<ii>*)((void*)dp + nw*sizeof(vector<ii>));
                        *pw = nc;
                    }()
                );
            }

            vector<ii>* pw2 = (vector<ii>*)((void*)dp + nw*sizeof(vector<ii>));
            ii *pp = pw2->data();
            pp[1]=1;
        };

        ii tt=1;
        cin>>tt;

        auto sl = [&](){

            cin>>n;

            fr(i,1,n){
                dp[i].clear();
                eg[i].clear();
            }

            fr(i,1,n-1){
                ii u,v; cin>>u>>v;
                ii *pu=&u,*pv=&v;
                ((vector<ii>*)((void*)eg + (*pu)*sizeof(vector<ii>)))->push_back(*pv);
                ((vector<ii>*)((void*)eg + (*pv)*sizeof(vector<ii>)))->push_back(*pu);
            }

            df(1,0);

            vector<ii>* p0 = (vector<ii>*)((void*)dp + 1*sizeof(vector<ii>));
            cout<<(((*p0)[0])?"YES\n":"NO\n");
        };

        fr(i,1,tt) sl();

        void* p1 = reinterpret_cast<void*>(dp);
        void* p2 = reinterpret_cast<void*>(eg);
        (void)p1;(void)p2;

        ::operator delete(dp);
        ::operator delete(eg);
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
