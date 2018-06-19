#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// using namespace __gnu_pbds;
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
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 400009;
const int MAX2 = 50;
const ll MOD = 1e9+7;
const int inf = 1e9+10;

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

vll f,invf;

void pre(){
  f.resize(MAX2+4),invf.resize(MAX2+4);
  ll tmp=1;
  f[0]=1,invf[0]=1;
  repA(i,1,MAX2-1)tmp=(tmp*i)%MOD,f[i]=tmp;

  invf[MAX2-1]=modI(f[MAX2-1]);
  repD(i,MAX2-2,1)invf[i]=invf[i+1]*(i+1)%MOD;
}

int cnt[10];
ll powe(ll x,ll y){
  if(y==0)return 1;
  ll tmp=powe(x,y/2);tmp=tmp*tmp%MOD;
  if(y%2)tmp=tmp*x%MOD;
  return tmp;
}

ll func(){
  ll tot=0;
  rep(i,10)tot+=cnt[i];
  ll ans=f[tot];
  rep(i,10)ans=ans*invf[cnt[i]]%MOD;
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    pre();

    ll n;cin>>n;
    rep(i,n){
      int x;cin>>x;
      cnt[x]++;
    }

    ll s=(powe(10,n-1)-1+MOD)%MOD*modI(9)%MOD,ans=0;

    repA(i,1,9)if(cnt[i]>0){
      cnt[i]--;
      ans=(ans+func()*powe(10,n-1)%MOD*i%MOD)%MOD;
      repA(j,1,9)if(cnt[j]>0){
        cnt[j]--;
        ans=(ans+func()*s%MOD*i%MOD)%MOD;
        cnt[j]++;
      }
      cnt[i]++;
    }
    cout<<ans<<endl;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
