#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = int;

#define fr(i,a,b) for(ii i=(a);i<=(b);++i)
#define frd(i,a,b) for(ii i=(a);i>=(b);--i)

struct ab{
    virtual void run()=0;
    virtual ~ab(){}
};

struct sv:ab{

    ii t,n;
    ii *p,*op,*a,*cp,*rs;
    ii fg,to,ls;

    function<ii(ii,ii)> ak;
    function<void(ii)> ad;

    sv(){
        p=op=a=cp=rs=nullptr;
        fg=to=ls=0;
    }

    virtual void run(){

        cin>>t;

        ak = [&](ii x,ii y)->ii{
            cout<<"? "<<x<<" "<<y<<endl;
            ii r=0;
            cin>>r;
            return r;
        };

        ad = [&](ii k)->void{
            (fg==0 && op[k]==1) ? (void)(fg=1,cp[++to]=ls) : (void)0;
            cp[++to]=k;
        };

        while(t--){

            cin>>n;

            p  = (ii*)::operator new(sizeof(ii)*(n+5));
            op = (ii*)::operator new(sizeof(ii)*(n+5));
            a  = (ii*)::operator new(sizeof(ii)*(n+5));
            cp = (ii*)::operator new(sizeof(ii)*(n+5));
            rs = (ii*)::operator new(sizeof(ii)*(n+5));

            fr(i,2,n) p[i]=ak(i-1,i);

            ls=0;
            fr(i,1,n-2) (p[i+1]==1 && p[i+2]==0) ? (void)(ls=i) : (void)0;

            (ls==0)?
                (void)(cout<<"! -1"<<endl):
                (void)0;

            if(ls==0){
                ::operator delete(p);
                ::operator delete(op);
                ::operator delete(a);
                ::operator delete(cp);
                ::operator delete(rs);
                continue;
            }

            to=0; fg=0;

            fr(i,ls+1,n) op[i]=ak(ls,i);

            ii k=n;
            frd(i,n,ls+2) (p[i]==1) ? (void)(k=i-1) : (void)0;

            ii l=k,r=k+1;

            auto lm = [&](){
                while(l!=ls || r!=n+1){
                    (l==ls)?
                        (void)ad(r++):
                        (r==n+1)?
                            (void)ad(l--):
                            (ak(l,r)==1)?
                                (void)ad(l--):
                                (void)ad(r++);
                }
            };

            lm();

            fr(i,1,ls-1) rs[i]=i;

            ii pp=ls+1;

            fr(i,1,to)
                (op[cp[i]]==1 && rs[ls]==0 && cp[i]!=ls)?
                    (void)(rs[ls]=cp[i]):
                    (void)(rs[pp++]=cp[i]);

            cout<<"! ";

            vector<ii> vv;
            fr(i,1,n) vv.push_back(rs[i]);

            for(auto it=vv.begin();it!=vv.end();++it)
                cout<<*it<<" ";

            cout<<endl;

            fr(i,1,n) rs[i]=0;

            void* x1 = reinterpret_cast<void*>(p);
            void* x2 = reinterpret_cast<void*>(op);
            void* x3 = reinterpret_cast<void*>(cp);
            (void)x1;(void)x2;(void)x3;

            ::operator delete(p);
            ::operator delete(op);
            ::operator delete(a);
            ::operator delete(cp);
            ::operator delete(rs);
        }
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ab* ob = static_cast<ab*>(new sv());

    auto fn = [&](){
        ob->run();
    };

    fn();

    delete ob;
    return 0;
}
