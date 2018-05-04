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
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const ll MAX = 3000009;
const ll MAX2 =3000009;
const ll MOD = 1e9+7;
const int inf = 1e9+10;

ll gcdExtended(ll a, ll b, ll *x, ll *y){
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
ll modI(ll a, ll m=MOD){
    ll x,y;
    ll g=gcdExtended(a,m,&x,&y);
    if (g != 1)cout<<"Inverse doesn't exist";
    else{
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

ll dp[8000]={0};

ll solve(ll n,ll k,ll a,ll b){
    fill(dp);
    dp[1]=k%MOD;

    repA(i,2,n){
        dp[i] = a*dp[i-1]%MOD;
        repA(j,1,i-1){
          ll tmp=dp[j] * dp[i-j]%MOD;
          tmp=(tmp*b)%MOD;
          dp[i]=(dp[i]+tmp)%MOD;
        }
    }

    return dp[n];
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

ll C(ll n, ll m) {
  if(n<m)return 0;
	return ((f[n]*invf[m])%MOD)*invf[n-m]%MOD;
}

ll pw(ll x,ll y){
  if(y==0)return 1;
  if(y==1)return x;

  ll tmp=pw(x,y/2);
  if(y%2)return (((tmp*tmp)%MOD)*x)%MOD;

  return (tmp*tmp)%MOD;
}

void tle(){
  int a=0;while(a==0)a++,a--;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    // rep(i,1000){
      ll n,k,a,b;cin>>n>>k>>a>>b;b=b%MOD,k=k%MOD,a=a%MOD;
      // n=rand()%1000+1;
      // k=rand()%MOD+1;
      // b=rand()%MOD+1;
      // a=0;

      if(n<7000){
        cout<<solve(n,k,a,b)<<endl;
        return 0;
      }

      // tle();
      // if(a!=0)tle();

      ll tmp=pw(k,n)*pw(b,n-1)%MOD;
      ll ans=C(2*n-2,n-1)*modI(n)%MOD;
      ans=(ans*tmp)%MOD;
      cout<<ans<<endl;

      // if(ans!=solve(n,k,a,b)){
      //   cout<<ans<<','<<solve(n,k,a,b);
      //   cout<<n<<','<<k<<','<<a<<','<<b<<endl;
      //   return 0;
      // }
    // }


    return 0;
}
