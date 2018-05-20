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
// #define endl '\n'

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

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int n;
ll a[5009];
ll dp[5009][5009];
ll f[5009][5009];

ll solve(int d,int i){
  if (dp[d][i]!=-1)return dp[d][i];
  if(d==0)return dp[d][i]=a[i];
  return dp[d][i]=solve(d-1,i)^solve(d-1,i+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>n;
    rep(i,n)cin>>a[i];

    fillA(dp);solve(n-1,0);

    rep(i,n)rep(j,n-i){
      if(i==0)f[j][j+i]=dp[i][j];
      else f[j][j+i]=max(f[j+1][j+i],max(f[j][j+i-1],dp[i][j]));
    }

    int q;cin>>q;
    rep(aa,q){
      ll l,r;cin>>l>>r;
      cout<<f[l-1][r-1]<<endl;
    }


    #ifdef LOCAL_TEST
    fin();
    #endif


    return 0;
}
