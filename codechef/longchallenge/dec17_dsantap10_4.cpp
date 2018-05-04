#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector <ll> vll;
typedef vector<ld > vld;
typedef pair<ll, ll> pp;
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

ll bag[105]={0};
void pick(ll i){cout<<"2 "<<i<<endl;bag[i]=1;}
void drop(ll i){cout<<"3 "<<i<<endl;bag[i]=0;}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");//ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(tt,t)
    {
      fill(bag);
      ll n,g,b,x,y;cin>>n>>g>>b>>x>>y;
      vll vol;//gift
      rep(i,g){ll a;cin>>a;vol.pb(a);}
      vpp ch,gf;//child,child gift last->this
      vpp d;vld po;vll dist;
      rep(i,n)
      {
        ll cx,cy,l,c;cin>>cx>>cy>>l>>c;
        cx-=x,cy-=y;
        ch.pb(mp(cx,cy));gf.pb(mp(l,c));
        dist.pb(cx*cx+cy*cy);
        d.pb(mp(cx*cx+cy*cy,i));
        po.pb(atan2(cy,cx));
      }
      sortA(d);
      vll hv[55],nd[55];//child having and needing gift g
      rep(i,n)
      {
        ll a=gf[i].X,b=gf[i].Y;
        hv[a].pb(i),nd[b].pb(i);
      }

      ll cnt=0,vis[509]={0};
      queue<ll> que;
      rep(i,n)if(vis[d[i].Y]==0){pick(gf[d[i].Y].Y),que.push(d[i].Y);break;}

      while(cnt<n)
      {
        if(!que.empty())
        {
          ll i=que.front();que.pop();
          vis[i]=1;
          cout<<"1 "<<i+1<<endl;
          drop(gf[i].Y),pick(gf[i].X);
          cnt++;

          ll m=1e17,ind=-1;
          rep(j,sz(nd[gf[i].X]))
          {
            ll c=nd[gf[i].X][j];
            if(vis[c]==0&&dist[c]<m)m=dist[c],ind=c;
          }
          if(ind!=-1)que.push(ind);

        }
        else
        {
          cout<<"1 "<<0<<endl;
          rep(i,g+1)if(bag[i]==1)drop(i);

          rep(i,n)if(vis[d[i].Y]==0){pick(gf[d[i].Y].Y),que.push(d[i].Y);break;}
        }
      }

      cout<<"1 0"<<endl;
      rep(i,g+1)if(bag[i]==1)drop(i);
      cout<<0<<endl;
    }



    return 0;
}
