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
typedef pair<ll, ll> pp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const ll MAX = 200009;
const ll MOD = 1e9+7;

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gc = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gc;
}

ll modI(ll a, ll m=MOD)
{
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if (g != 1)cout<<"Inverse doesn't exist";
    else
    {
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

ll Sin(ll t);
ll Cos(ll t);

ll c1;


ll d,l;
ll Cos(ll t){
  if(t==1)return c1;
  ll f=(1-c1*c1+5*MOD)%MOD;
  ll x,y;

  if(t%2==0){
    ll a=t/2,b=t-a;
    ll Ca=Cos(a),Sa=Sin(a);

    x=(Ca*Ca+5*MOD)%MOD;
    y=(Sa*Sa+5*MOD)%MOD;
  }
  else{
    ll a=t-1,b=1;

    x=(Cos(a)*c1+5*MOD)%MOD;
    y=(Sin(a)*1+5*MOD)%MOD;
  }

  y=(y*f+5*MOD)%MOD;
  return (x-y+5*MOD)%MOD;
}

ll Sin(ll t){
  if(t==1)return 1;
  ll x,y;

  if(t%2==0){
    ll a=t/2;
    ll Ca=Cos(a),Sa=Sin(a);

    x=(Sa*Ca+5*MOD)%MOD;
    y=(Ca*Sa+5*MOD)%MOD;
  }
  else{
    ll a=t-1,b=1;

    x=(Sin(a)*c1+5*MOD)%MOD;
    y=(Cos(a)*1+5*MOD)%MOD;
  }

  return (x+y+5*MOD)%MOD;
}

pp euler(ll t){
  if(t==1)return mp(c1,1);

  if(t%2==0){
    pp a=euler(t/2);

    ll x=(2*a.fst*a.fst-1+5*MOD)%MOD;
    ll y=(2*a.fst*a.snd+5*MOD)%MOD;
    return mp(x,y);
  }
  else{
    pp a=euler(t-1),b=euler(1);

    ll f=(1-c1*c1+5*MOD)%MOD;
    ll x=((a.fst*b.fst+5*MOD)%MOD-(a.snd*b.snd*f+5*MOD)%MOD+5*MOD)%MOD;
    ll y=((a.fst*b.snd+5*MOD)%MOD+(a.snd*b.fst+5*MOD)%MOD+5*MOD)%MOD;
    return mp(x,y);
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int tt;cin>>tt;
    rep(aa,tt){
      ll t;cin>>l>>d>>t;
      ll g=gcd(d,l);
      ll lt=l;
      l/=g,d/=g;

      c1=(d*modI(l)+5*MOD)%MOD;

      pp tmp=euler(t);

      ll ans=(tmp.fst*lt+5*MOD)%MOD;
      cout<<ans<<endl;
    }

    // fin();

    return 0;
}
