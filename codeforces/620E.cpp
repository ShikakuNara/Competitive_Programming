#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef int ll;
typedef vector <int> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;


#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a,b)       (make_pair(a,b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(),v.end()))
#define sortD(v)      (sort(v.rbegin(),v.rend()))
#define fill(a)       (memset(a,0,sizeof (a)))
#define rep(i,n)     for(ll i = 0; i < (n); ++i)
#define repA(i,a,n) for(ll i = a; i <= (n); ++i)
#define repD(i,a,n) for(ll i = a; i >= (n); --i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


ll gcd(ll a,ll b){
    if (a == 0) return b;
    return gcd(b%a,a);
}
ll lcm(ll a,ll b){
    return a * (b / gcd(a,b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}

const int MOD = 1e9+7;

const int MAX = 4*100009;

bitset<61> Null;
bitset<61> tree[MAX],lazy[MAX];

int n,m,fir[MAX]={0},las[MAX]={0},a[MAX],vis[MAX]={0};
vll adj[MAX],arr;

void updateU(ll i,ll s,ll e,ll us,ll ue,ll diff)
{
    if (lazy[i].any())
    {
        tree[i]=lazy[i];
        if(s!=e) lazy[(ll)i<<1|1]=lazy[i],lazy[(ll)(i<<1|1)+1]=lazy[i];
        lazy[i].reset();
    }

    if (s>e||s>ue||e<us) return;

    if (s>=us && e<=ue)
    {
        bitset<61> tmp;tmp.set(diff);
        tree[i].reset(); tree[i]|=tmp;
        if(s!=e) lazy[(ll)i<<1|1]=tmp,lazy[(ll)(i<<1|1)+1]=tmp;
        return;
    }

    ll m = (s+e)>>1;
    updateU(i<<1|1,s,m,us,ue,diff);updateU((ll)(i<<1|1)+1,m+1,e,us,ue,diff);

    tree[i].reset();
    tree[i]|=tree[(ll)i<<1|1];tree[i]|=tree[(ll)(i<<1|1)+1];
}

void update(ll us,ll ue,ll diff,ll n)
{
   updateU(0,0,n-1,us,ue,diff);
}

bitset<61> getSumU(ll s,ll e,ll qs,ll qe,ll i)
{
    if (lazy[i].any())
    {
        tree[i]=lazy[i];
        if (s != e) lazy[(ll)i<<1|1]=lazy[i],lazy[(ll)(i<<1|1)+1]=lazy[i];
        lazy[i].reset();
    }

    if (s>e||s>qe||e<qs) return 0;
    if (s>=qs&&e<=qe) return tree[i];

    ll m=(s+e)>>1;
    bitset<61> res=getSumU(s,m,qs,qe,2*i+1);
    res |= getSumU(m+1,e,qs,qe,2*i+2);
    return res;
}

bitset<61> getSum(ll qs,ll qe,ll n)
{
    if (qs<0||qe>n-1||qs>qe) {cout<<"invalid input\n"; return Null;}
    return getSumU(0,n-1,qs,qe,0);
}

void buildtreeU(vll arr,ll s,ll e,ll i)
{
    if (s > e) return;
    if (s == e){ tree[i].set(a[arr[s]]); return;}

    ll m=(s+e)>>1;
    buildtreeU(arr,s,m,i<<1|1); buildtreeU(arr,m+1,e,(ll)(i<<1|1)+1);
    tree[i]|=tree[(ll)i<<1|1];tree[i]|=tree[(ll)(i<<1|1)+1];
}

void buildtree(vll a,ll  n)
{
  buildtreeU(a,0,n-1,0);
  return;
}


void dfs(int i)
{
  vis[i]=1;
  arr.pb(i);
  rep(j,sz(adj[i]))
  {
    int u=adj[i][j];
    if(vis[u]==0) dfs(u);
  }
  arr.pb(i);
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m;
    rep(i,n) cin>>a[i];

    rep(i,n-1)
    {
      int x,y;cin>>x>>y;x--,y--;
      adj[x].pb(y),adj[y].pb(x);
    }
    dfs(0);
    rep(i,2*n) fir[i]=-1,las[i]=-1;
    rep(i,2*n)
    {
      int c=arr[i];
      if(fir[c]==-1)fir[c]=i;
      las[c]=i;
    }

    buildtree(arr,2*n);

    rep(i,m)
    {
      int q,v,c;cin>>q>>v;v--;
      if(q==1)
      {
        int c;cin>>c;update(fir[v],las[v],c,2*n);
      }
      else cout<<getSum(fir[v],las[v],2*n).count()<<end;
    }

    return 0;
}
