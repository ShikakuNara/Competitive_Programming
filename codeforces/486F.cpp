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
typedef pair<int, int> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 2009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int uid[MAX],r[MAX];
ll dp[MAX][MAX];
map<ll,ll> uw;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    fillA(r),fillA(uid);
    rep(i,MAX)rep(j,MAX)dp[i][j]=1e18;

    int a,n,m;cin>>a>>n>>m;
    rep(i,n){
      int x,y;cin>>x>>y;
      repA(i,x,y)r[i]=1;
      r[x]=-1;
    }
    rep(i,m){
      int x,w;cin>>x>>w;
      if(uid[x]==-1)uid[x]=i+1,uw[i+1]=w;
      else if(uw[uid[x]]>w)uid[x]=i+1,uw[i+1]=w;
    }
    uw[0]=0;

    if(r[0]==-1)dp[0][0]=0;
    if(uid[0]!=-1)dp[0][uid[0]]=0;

    repA(i,1,a){
      repA(j,1,m)dp[i][j]=dp[i-1][j]+uw[j];
      if(uid[i-1]!=-1)repA(j,0,m)dp[i][uid[i-1]]=min(dp[i][uid[i-1]],dp[i-1][j]+uw[uid[i-1]]);
      if(r[i]==-1)repA(j,0,m)dp[i][0]=min(dp[i][0],dp[i-1][j]);
    }

    ll ans=1e18;
    rep(j,m+1)ans=min(ans,dp[a][j]);
    if(ans==1e18)ans=-1;
    cout<<ans<<endl;





    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
