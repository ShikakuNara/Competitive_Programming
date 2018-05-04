#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}


const int MAX = 200009;
const int MOD = 1e9;

ll f[40];

ll seg[320][320],psum[320],parr[320][40];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    repA(i,0,39)f[i]=1;
    repA(i,2,39)f[i]=f[i-1]*i%MOD;
    fill(seg),fill(psum),fill(parr);

    ll BIG=1000;
    ll n,m;cin>>n>>m;
    rep(i,n)
    {
      ll ii=i%320,j=i/320;
      cin>>seg[j][ii];
      // seg[j][ii]=1;
      if(seg[j][ii]>39)seg[j][ii]=BIG;
      else parr[j][seg[j][ii]]++;
    }
    rep(i,m)
    {
      ll val,l,r;cin>>val>>l>>r;
      ll ii=l,v=r;

      if(val==1)
      {
        l--;r--;
      	ll s=0;while(320*s<=l)s++;
        ll aa=320*(s-1);ll stmp=s;
        s--;
        repA(j,max((ll)0,l-aa),min((ll)319,r-aa))
        {
          ll t=psum[s];
          if(seg[s][j]+t<39&&seg[s][j]+t>0)parr[s][seg[s][j]+t]--,seg[s][j]++,parr[s][seg[s][j]+t]++;
          else if(seg[s][j]+t==39)parr[s][seg[s][j]+t]--,seg[s][j]=BIG;
        }
        s++;
        while(320*s>=l&&320*s+319<=r)
        {
          psum[s]++;
          repD(j,39,2)parr[s][j]=parr[s][j-1];
          parr[s][1]=0;
          s++;
        }
        aa=320*s;
        repA(j,max((ll)0,l-aa),min((ll)319,r-aa))
        {
          ll t=psum[s];
          if(seg[s][j]+t<39&&seg[s][j]+t>0)parr[s][seg[s][j]+t]--,seg[s][j]++,parr[s][seg[s][j]+t]++;
          else if(seg[s][j]+t==39)parr[s][seg[s][j]+t]--,seg[s][j]=BIG;
        }
      }
      else if(val==2)
      {
        ll ans[40]={0};
        l--;r--;
      	ll s=0;while(320*s<=l)s++;
        ll aa=320*(s-1);ll stmp=s;
        // cout<<s<<" "<<max((ll)0,l-aa)<<", "<<min((ll)319,r-aa)<<endl;
        repA(j,max((ll)0,l-aa),min((ll)319,r-aa))
        {
          ll t=psum[s-1];
          if(seg[s-1][j]+t>0&&seg[s-1][j]+t<=39)ans[seg[s-1][j]+t]++;
        }
        while(320*s>=l&&320*s+319<=r)
        {
          rep(k,40)ans[k]+=parr[s][k];
          s++;
        }
        // if(stmp!=s)
        // {
        aa=320*s;
        repA(j,max((ll)0,l-aa),min((ll)319,r-aa))
        {
          ll t=psum[s];
          if(seg[s][j]+t>0&&seg[s][j]+t<=39)ans[seg[s][j]+t]++;
        }
        // }
      	ll sum=0;
        repA(i,1,39)sum=(sum+f[i]*ans[i]%MOD)%MOD;
        cout<<sum<<endl;
      }
      else if(val==3)
      {
        ii--;
        if(v<40)
        {
          ll s=0;while(320*s<=ii)s++;s--;
          ii=ii-320*s;
          ll t=psum[s];
          if(seg[s][ii]+t<=39&&seg[s][ii]+t>0)parr[s][seg[s][ii]+t]--,parr[s][v]++,seg[s][ii]=v-t;
          else parr[s][v]++,seg[s][ii]=v-t;
        }
        else
        {
          ll s=0;while(320*s<=ii)s++;s--;
          ii=ii-320*s;
          ll t=psum[s];
          if(seg[s][ii]+t<=39&&seg[s][ii]+t>0)parr[s][seg[s][ii]+t]--;
          seg[s][ii]=v-t;
        }
      }
    }

    return 0;
}
