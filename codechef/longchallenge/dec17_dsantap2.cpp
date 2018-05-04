#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
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
#define end '\n'

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
bool debug=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(tt,t)
    {
      ll n,g,b,x,y;cin>>n>>g>>b>>x>>y;
      vll vol;//gift
      rep(i,g){ll a;cin>>a;vol.pb(a);}
      vpp ch,gf;//child,child gift last->this
      rep(i,n)
      {
        ll cx,cy,l,c;cin>>cx>>cy>>l>>c;
        cx-=x,cy-=y;
        ch.pb(mp(cx,cy));gf.pb(mp(l,c));
      }
      vll hv[55],nd[55];//child having and needing gift g
      rep(i,n)
      {
        ll a=gf[i].X,b=gf[i].Y;
        hv[a].pb(i),nd[b].pb(i);
      }

      ll cnt=0,vis[509]={0},bag[55]={0};
      queue<ll> que;
      ll m=1e17,ind=-1;
      rep(i,n)
      {
        ll d=ch[i].X*ch[i].X+ch[i].Y*ch[i].Y;
        if(d<m)m=d,ind=i;
      }

      if(ind!=-1)
      {
        if(debug)cout<<"picked "<<gf[ind].Y<<",for "<<ind+1<<endl;//pickup
        else cout<<"2 "<<gf[ind].Y<<endl;//pickup
        que.push(ind),bag[gf[ind].Y]=1;//cout<<"pushed: "<<gf[ind].Y<<endl;
      }

      while(cnt<n)
      {
        if(!que.empty())
        {
          ll i=que.front();que.pop();
          //visit(i) //go there,vis[i]=1, pickup gift, dropgift, update count, push closest kid with the new gift
          vis[i]=1;
          if(debug)cout<<"moved to "<<i+1<<endl;//move
          if(debug)cout<<"dropped "<<gf[i].Y<<endl;//drop
          if(debug)cout<<"picked "<<gf[i].X<<endl;//pickup
          if(!debug)cout<<"1 "<<i+1<<endl;//move
          if(!debug)cout<<"3 "<<gf[i].Y<<endl;//drop
          if(!debug)cout<<"2 "<<gf[i].X<<endl;//pickup
          bag[gf[i].Y]=0,bag[gf[i].X]=1;//drop pickup
          cnt++;

          ll m=1e17,ind=-1;
          rep(j,sz(nd[gf[i].X]))//find closest child needing gift
          {
            ll c=nd[gf[i].X][j];
            if(vis[c]==0)
            {
              ll d=ch[c].X*ch[c].X+ch[c].Y*ch[c].Y;
              if(d<m)m=d,ind=c;
            }
          }
          if(debug&&ind!=-1)cout<<"decided to move to: "<<ind+1<<endl;
          if(ind!=-1)que.push(ind),bag[gf[ind].Y]=1;//push
          //else return home in the next step;
        }
        else
        {
          //return home, choose closest child, pickupgift, push him to que
          if(debug)cout<<"moved to "<<0<<endl;//move home
          else cout<<"1 "<<0<<endl;//move home
          //drop any gift you have
          rep(i,g+1)if(bag[i]==1&&!debug)cout<<"3 "<<i<<endl;
          rep(i,g+1)if(bag[i]==1&&debug)cout<<"dropped "<<i<<endl;

          ll m=1e17,ind=-1;//pickup next best
          rep(i,n)if(vis[i]==0)
          {
            ll d=ch[i].X*ch[i].X+ch[i].Y*ch[i].Y;
            if(d<m)m=d,ind=i;
          }

          if(debug)cout<<"picked "<<gf[ind].Y<<endl;//announce pickup
          else cout<<"2 "<<gf[ind].Y<<endl;//announce pickup
          if(debug)cout<<"pushed "<<ind+1<<endl;
          que.push(ind),bag[gf[ind].Y]=1;//add child, pickup
        }
      }

      if(debug)cout<<"move to 0\n";
      else cout<<"1 0"<<endl;

      rep(i,g+1)if(bag[i]==1&&!debug)cout<<"3 "<<i<<endl;
      rep(i,g+1)if(bag[i]==1&&debug)cout<<"dropped "<<i<<endl;

      if(debug)cout<<"end communication\n";
      else cout<<0<<endl;//end communication

    }



    return 0;
}
