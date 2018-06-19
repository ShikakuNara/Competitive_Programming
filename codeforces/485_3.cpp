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
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 3009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


ll s[MAX],c[MAX],dp[MAX],dp2[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n)cin>>s[i];
    rep(i,n)cin>>c[i];

    rep(i,n)dp[i]=1e15,dp2[i]=1e15;

    repD(i,n-1,0)repA(j,i+1,n-1)if(s[i]<s[j])dp[i]=min(dp[i],c[j]);

    repD(i,n-1,0)repA(j,i+1,n-1)if(s[i]<s[j]&&dp[i]!=1e15)dp2[i]=min(dp2[i],c[i]+c[j]+dp[j]);

    ll ans=1e15;
    rep(i,n)ans=min(ans,dp2[i]);
    if(ans!=1e15)cout<<ans;
    else cout<<-1;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
