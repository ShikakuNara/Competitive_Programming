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

const int MAX = 10000009;
const int MOD = 1e9+7;
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

ll dp[MAX];

vll f,invf;

void pre(){
  f.resize(MAX+4),invf.resize(MAX+4);
  ll tmp=1;
  f[0]=1,invf[0]=1;
  repA(i,1,MAX-1)tmp=(tmp*i)%MOD,f[i]=tmp;

  invf[MAX-1]=modI(f[MAX-1]);
  repD(i,MAX-2,1)invf[i]=invf[i+1]*(i+1)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    ll n,k,a,b;cin>>n>>k>>a>>b;b=b%MOD,k=k%MOD,a=a%MOD;

    dp[1]=k;dp[2]=a*k%MOD+b*k%MOD*k%MOD;dp[2]%=MOD;


    ll aa=(a+2*k*b)%MOD;
    ll bb=a*a%MOD;
    repA(i,3,n){
      dp[i]=((2*i-3)*aa%MOD*dp[i-1]%MOD-bb*(i-3)%MOD*dp[i-2]%MOD+MOD)%MOD;
      dp[i]=dp[i]*invf[i]%MOD*f[i-1]%MOD;
    }

    rep(i,n+1)dp[i]=dp[i]*dp[i]%MOD;
    repA(i,2,n)dp[i]=(dp[i]+dp[i-1])%MOD;

    int q;cin>>q;
    rep(i,q){
      int l,r;cin>>l>>r;
      cout<<(dp[r]-dp[l-1]+MOD)%MOD<<endl;
    }



    return 0;
}
