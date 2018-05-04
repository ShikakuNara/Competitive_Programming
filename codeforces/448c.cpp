#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif
#pragma GCC target ("avx,avx2")
#pragma GCC optimize ("Ofast")

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 5000;
const int MOD = 1e9+7;
const ll  inf = 1e18;

ll a[MAX],n;
pp tree[4*MAX];

pp getU(ll s,ll e,ll qs,ll qe,ll i)
{
    if (s>e||s>qe||e<qs)return mp(inf,inf);
    if (s>=qs&&e<=qe)return tree[i];
    ll m=(s+e)>>1;
    return min(getU(s,m,qs,qe,2*i+1),getU(m+1,e,qs,qe,2*i+2));
}

pp get(ll qs,ll qe,ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return mp(inf,-1);}
    return getU(0,n-1,qs,qe,0);
}

void buildtreeU(ll arr[],ll s,ll e,ll i)
{
    if (s>e) return;
    if (s==e){tree[i]=mp(arr[s],s);return;}
    ll m=(s+e)/2;
    buildtreeU(arr,s,m,i*2+1); buildtreeU(arr,m+1,e,i*2+2);
    tree[i]=min(tree[i*2+1],tree[i*2+2]);
}

void buildtree(ll a[],ll n){buildtreeU(a,0,n-1,0); return;}

ll solve(ll s,ll e,ll h)
{
  if(s>e)return 0;
  pp mm=get(s,e,n);
  ll ans=min(e-s+1,solve(s,mm.Y-1,mm.X)+solve(mm.Y+1,e,mm.X)+mm.X-h);
  return ans;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n;
    rep(i,n)cin>>a[i];
    buildtree(a,n);

    // pp tmp=mp(20,100);//get(1,1,n);
    // pp tmp2=mp(20,2);
    // tmp=min(tmp,tmp2);
    // cout<<tmp.Y<<endl;
    cout<<solve(0,n-1,0);

    return 0;
}
