#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;
typedef long long int ll;
typedef vector <ll> vll;
typedef long double ld;
typedef pair<ld, ld> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
struct comp{bool operator()(pp lhs,pp rhs){if(lhs.Y!=rhs.Y)return lhs.Y<rhs.Y;else return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 400009;
const int MOD = 1e9+7;
const ld eps=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

	ll t;cin>>t;
	rep(i,t)
	{
		ll k;cin>>k;
		ll c[12],s[12];
    rep(i,k)cin>>c[i]>>s[i];

		ll n;cin>>n;
		vpp D;rep(i,n){ll a,b;cin>>a>>b;D.pb(mp(a,b));}

    sort(D.begin(),D.end(),comp());

		ll m=1e17,Mt=D[sz(D)-1].Y;

		repA(i,1,(1<<k)-1)
		{
			vll ck;ll p=0;
			vpp d(D);

			rep(j,k)if(i&(1<<j))ck.pb(c[j]),p+=s[j];sortD(ck);

			repD(tt,Mt,2)
			{
        //taking current day's dishes
				vpp curd,lf;ll ext=0;
				repD(j,sz(d)-1,0)
        {
          if(d[j].Y==tt)curd.pb(d[j]),d.pop_back();
          else break;
        }

        // if(tt==2&&p==163)
        // {
        //   cout<<"day "<<tt<<endl;
        //   cout<<"oth D\n";rep(j,sz(d))cout<<d[j].X<<' '<<d[j].Y<<'\n';
        //   cout<<"cur D:\n";rep(j,sz(curd))cout<<curd[j].X<<','<<curd[j].Y<<'\n';cout<<'\n';
        // }


        //greedily deleting
        rep(j,sz(curd))
				{
					ll tmp;if(j<sz(ck))tmp=ck[j];else tmp=0;
					if(curd[j].X>=tmp+ext)curd[j].X-=tmp+ext,ext=0,curd[j].Y-=1,lf.pb(curd[j]);
					else ext+=tmp-curd[j].X,curd[j].X=0,curd[j].Y-=1,lf.pb(curd[j]);
				}

        //averaging
        while(sz(lf)>0)
        {
          ld cur=lf[0].X;ll ff=0,p=0;
          repA(j,1,sz(lf)-1)
          {
            if(lf[j].X>cur+eps)
            {
              ff=1;
              cur=(cur*(j-p)+lf[j].X)/(j-p+1);
              repA(k,p,j)lf[k].X=cur;
            }
            else if(lf[j].X+eps<cur) p=j,cur=lf[j].X;
          }
          if(ff==0)break;
        }

        rep(j,sz(lf))if(lf[j].X>eps)d.pb(lf[j]);
        sort(d.begin(),d.end(),comp());
      }

      // if(p==163)
      // {
      //   cout<<"Dish\n";rep(j,sz(d))cout<<d[j].X<<' '<<d[j].Y<<'\n';
      //   cout<<"Cook\n";rep(j,sz(ck))cout<<ck[j]<<' ';cout<<'\n';
      // }

      ld ext=0;int ok=1;

      reverse(d.begin(),d.end());

      rep(j,sz(d))
      {
        ld cook;if(j<sz(ck))cook=ck[j];else cook=0;
        //if(p==163)cout<<"cook: "<<cook<<", "<<"ext: "<<ext<<", val"<<d[j].X<<endl;
			  if(d[j].X>cook+ext+eps){ok=0;break;}
			  else ext+=cook-d[j].X;
      }

			if(ok)m=min(m,p);
		}

    if(m<1e16)cout<<m<<'\n';
		else cout<<-1<<'\n';
	}

  return 0;
}
