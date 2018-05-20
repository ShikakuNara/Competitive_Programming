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
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll dp[1000][8005];
vll w;ll n;

ll solve(ll i,ll rw){
  if(i>=n||rw<=0){return 0;}
  if(dp[i][rw]!=-1){return dp[i][rw];}

  ll a1=solve(i+1,rw);
  ll a2=0;
  if(rw>=w[i])a2=1+solve(i+1,min(rw-w[i],6*w[i]));

  return dp[i][rw]=max(a1,a2);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(aa,t){
      w.clear();
      rep(i,299)rep(j,8005)dp[i][j]=-1;
      // fillA(dp);

      cin>>n;
      rep(i,n){ll tmp;cin>>tmp;w.pb(tmp);}
      reverse(all(w));

      ll m=-1;
      rep(i,n)m=max(m,1+solve(i+1,6*w[i]));

      cout<<"Case #"<<aa+1<<": "<<m<<endl;
    }
    return 0;
}
