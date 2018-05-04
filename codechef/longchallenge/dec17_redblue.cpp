#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector <ll> vll;
typedef pair<ld, ld> pp;
typedef pair<double, int> dd;
typedef vector<pp > vpp;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
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
ld Abs(ld a){if(a>0)return a;return -a;}

const int MAX = 1009;
// const double eps=1e-12;

ld angle(ld y,ld x){
  ld tmp=atan2(y,x);//+PI;
  // if(tmp<0)return tmp+2*PI;
  return tmp;
}
ll n,m,k=0,cr[2*MAX]={0},cb[2*MAX]={0};
pp r[MAX],b[MAX];
dd po[2*MAX];//angle,type 0red 1blue
ll tle(){return tle();}
ll binary(ld a,ll s,ll e)
{
  ll m=(e+s+1)/2;
  if(s==e)return s;//&&po[s].X<a
  if(po[m].X==a)return binary(a,s,m-1);
  if(po[m].X>a)return binary(a,s,m-1);
  return binary(a,m,e);
}

ll binary2(ld a,ll s,ll e)
{
  ll m=(e+s)/2;
  if(s>=e)return e;//&&po[s].X>a
  if(po[m].X==a)return binary2(a,m+1,e);
  if(po[m].X<a)return binary2(a,m+1,e);
  return binary2(a,s,m);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(aa,t)
    {
      cin>>n>>m;
      rep(i,n)cin>>r[i].X>>r[i].Y;
      rep(i,m)cin>>b[i].X>>b[i].Y;

      if(n==1&&m==1){cout<<0<<end;continue;}

      ll d=1e17;
      rep(i,n)
      {
        k=0;
        rep(j,n){if(j!=i)po[k].X=angle(r[j].Y-r[i].Y,r[j].X-r[i].X),po[k].Y=0,k++;}
        rep(j,m)po[k].X=angle(b[j].Y-r[i].Y,b[j].X-r[i].X),po[k].Y=1,k++;
        sort(po,po+n+m-1);

        rep(j,n+m-1){if(po[j].Y==0)cr[j]=1,cb[j]=0;else cr[j]=0,cb[j]=1;}
        repA(j,1,n+m-2)cr[j]+=cr[j-1],cb[j]+=cb[j-1];

        // rep(j,n+m-1)cout<<po[j].X<<' ';cout<<end;
        // rep(j,n+m-1)if(po[j].X>2*PI)tle();

        ll x,y;
        rep(j,n+m-1)
        {
          ld l=po[j].X,h=l+PI;if(h>PI)h-=2*PI;
          if(h<l)swap(l,h);

          ll li=binary2(l,0,n+m-2),hi=binary(h,0,n+m-2);

          // if(hi<li)cout<<"ooo\n";
          if(li>=hi&&(po[li].X<=l||po[li].X>=h||po[hi].X<=l||po[hi].X>=h))x=y=0;//cout<<"ka\n";
          else
          {
            x=cr[hi],y=cb[hi];
            if(li)x-=cr[li-1],y-=cb[li-1];
          }

          // cout<<i<<' '<<j<<' '<<l<<' '<<h<<"li,hi="<<li<<','<<hi<<"x,y="<<x<<','<<y<<end;
          if(po[j].Y==1)d=min(d,min(x+m-y-1,y+n-x-1));//cout<<"RB"<<min(x+m-1-y,y+n-1-x)<<end;
          else d=min(d,min(x+m-y,y+n-x-2));//cout<<"RR"<<min(x+m-y,y+n-2-x)<<end;
        }
      }
      rep(i,m)
      {
        k=0;
        rep(j,n)po[k].X=angle(r[j].Y-b[i].Y,r[j].X-b[i].X),po[k].Y=0,k++;
        rep(j,m){if(j!=i)po[k].X=angle(b[j].Y-b[i].Y,b[j].X-b[i].X),po[k].Y=1,k++;}
        sort(po,po+n+m-1);

        rep(j,n+m-1)if(po[j].Y==0)cr[j]=1,cb[j]=0;else cr[j]=0,cb[j]=1;
        repA(j,1,n+m-2)cr[j]+=cr[j-1],cb[j]+=cb[j-1];

        // rep(j,n+m-1)if(po[j].X>2*PI)tle();
        // rep(j,n+m-1)cout<<po[j].X<<' ';cout<<end;

        ll x,y;
        rep(j,n+m-1)
        {
          ld l=po[j].X,h=l+PI;if(h>PI)h-=2*PI;
          if(h<l)swap(l,h);

          ll li=binary2(l,0,n+m-2),hi=binary(h,0,n+m-2);
          // if(hi<li)cout<<"ooo\n";

          if(li>=hi&&(po[li].X<=l||po[li].X>=h||po[hi].X<=l||po[hi].X>=h))x=y=0;//cout<<"ka\n";
          else
          {
            x=cr[hi],y=cb[hi];
            if(li)x-=cr[li-1],y-=cb[li-1];
          }

          // cout<<i<<' '<<j<<' '<<l<<' '<<h<<"li,hi="<<li<<','<<hi<<"x,y="<<x<<','<<y<<end;
          if(po[j].Y==1)d=min(d,min(x+m-y-2,y+n-x));//cout<<"BB"<<min(x+m-2-y,y+n-x)<<end;
          else d=min(d,min(x+m-y-1,y+n-x-1));//cout<<"BR"<<min(x+m-1-y,y+n-1-x)<<end;
        }
      }

      cout<<max(d,(ll)0)<<end;
    }






    return 0;
}
