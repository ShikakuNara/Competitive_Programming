#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}

const int MAX = 4009;
const int MAX2 = 4000008;
const ll MOD = 1e9+7;
const int inf = 1e9+10;

vpp b;
ll dp[MAX];
ll f[MAX2],invf[MAX2];

ll gcdExtended(ll a,ll b,ll *x,ll *y){
    if(a==0){*x=0,*y=1;return b;}

    ll x1,y1;
    ll gcd=gcdExtended(b%a,a,&x1,&y1);

    *x=y1-(b/a)*x1;
    *y=x1;

    return gcd;
}

ll modI(ll a,ll m=MOD){
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if(g != 1)cout<<"Inverse doesn't exist";
    else return (x%m+m)%m;;
    return -1;
}

void pre(){
  ll tmp=1;
  f[0]=1,invf[0]=1;
  repA(i,1,MAX2-1)tmp=(tmp*i)%MOD,f[i]=tmp;

  invf[MAX2-1]=modI(f[MAX2-1]);
  repD(i,MAX2-2,1)invf[i]=invf[i+1]*(i+1)%MOD;
}

void tle(){
  int a=0;
  while(a==0)a++,a--;
}

ll C(ll n, ll m) {
  if(n<m)return 0;
  // if(n<0)tle();
	return ((f[n]*invf[m])%MOD)*invf[n-m]%MOD;
}

ll getp(pp a,pp c){
  if(c.snd<a.snd)return 0;
  ll ans=C(c.fst+c.snd-a.fst-a.snd,c.fst-a.fst);
  // if(a.fst>c.snd)return ans;
  ans=(ans-C(c.fst+c.snd-a.fst-a.snd,c.fst-a.snd+1)+8*MOD)%MOD;
  return ans;
}

set<pp> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    ll p,q,c,m;cin>>p>>q>>c>>m;
    p-=c;
    if(p<q){cout<<0<<endl;return 0;}

    rep(i,m){
      ll x,y;cin>>x>>y;x-=c;
      cout<<x<<"."<<y<<endl;
      if(mp.find(mp(x,y))!=mp.end())continue;
      b.pb(mp(x,y)),mp.insert(mp(x,y));
    }


    b.pb(mp(p,q));

    rep(i,sz(b)){
      dp[i]=getp(mp(0,0),b[i]);
      rep(j,i)dp[i]=(dp[i]-((dp[j]*getp(b[j],b[i]))%MOD)+8*MOD)%MOD;
    }

    cout<<dp[sz(b)-1]<<endl;
    return 0;
}
