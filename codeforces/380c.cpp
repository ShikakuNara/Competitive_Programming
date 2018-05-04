#include <bits/stdc++.h>
// #ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
// #endif
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef pair<int, pp> ppp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
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
const int MAX = 1000009;
const int MOD = 1e9+7;

ppp tree[4*MAX];

ppp getU(ll s,ll e,ll qs,ll qe,ll i)
{
    if (s>e||s>qe||e<qs)return mp(0,mp(0,0));
    if (s>=qs&&e<=qe)return tree[i];
    ll m=(s+e)/2;

    ppp ta=getU(s,m,qs,qe,2*i+1),tb=getU(m+1,e,qs,qe,2*i+2);
    ppp ans;
    ll tmp=min(ta.Y.X,tb.Y.Y);
    ans.X=ta.X+tb.X+tmp;
    ans.Y.X=ta.Y.X+tb.Y.X-tmp;
    ans.Y.Y=ta.Y.Y+tb.Y.Y-tmp;

    return ans;
}

ppp get(ll qs,ll qe,ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return mp(0,mp(0,0));}
    return getU(0,n-1,qs,qe,0);
}

void buildU(string a,ll s,ll e,ll i)
{
    if(s>e) return;
    if(s==e)
    {
      tree[i].X=tree[i].Y.X=tree[i].Y.Y=0;
      if(a[s]=='(')tree[i].Y.X=1;
      else tree[i].Y.Y=1;
      return;
    }
    ll m=(s+e)/2;
    buildU(a,s,m,i*2+1); buildU(a,m+1,e,i*2+2);

    ll tmp=min(tree[i*2+1].Y.X,tree[i*2+2].Y.Y);
    tree[i].X=tree[i*2+1].X+tree[i*2+2].X+tmp;
    tree[i].Y.X=tree[i*2+1].Y.X+tree[i*2+2].Y.X-tmp;
    tree[i].Y.Y=tree[i*2+1].Y.Y+tree[i*2+2].Y.Y-tmp;
}

void build(string a,ll n){buildU(a,0,n-1,0); return;}


string s;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>s;
    build(s,sz(s));
    int m;cin>>m;

    rep(i,m)
    {
      int l,r;cin>>l>>r;l--,r--;
      ppp ans=get(l,r,sz(s));
      cout<<2*ans.X<<endl;
    }



    return 0;
}
