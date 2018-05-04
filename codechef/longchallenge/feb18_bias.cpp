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
typedef vector<pp > vp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 1009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX][MAX];
ll ans[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){
      fillA(ans);

      ll n,m;cin>>n>>m;
      vp p;
      rep(i,m){
        ll l,r;cin>>l>>r;
        p.pb(mp(l,r));
      }
      rep(i,n)rep(j,m)cin>>a[i][j];

      ll tmp[MAX]={0},tmpb[MAX]={0};
      repA(i,0,n/4)rep(j,m)tmp[j]+=(n-i)*(n-i)*(n-i)*a[i][j];
      repA(i,n-n/4,n-1)rep(j,m)tmpb[j]+=(i)*(i)*(i)*a[i][j];

      rep(i,m)if(tmp[i]<=tmpb[i])ans[i]=p[i].fst; else ans[i]=p[i].snd;

      rep(i,m)cout<<ans[i]<<' ';cout<<endl;
      // rep(i,n){int sc=0;rep(j,m)sc+=ans[j]*a[i][j];cout<<sc<<' ';}cout<<endl;
    }

    return 0;
}
