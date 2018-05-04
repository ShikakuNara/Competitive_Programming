#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
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
const int MAX = 400009;
const ll MOD = 32416190071;

int p1[MAX],p2[MAX];
ll v1[MAX][2],v2[MAX][2];
vi adj[MAX],adj2[MAX];
ll pw1[MAX]={0},pw2[MAX]={0};

map<pp,int> mp;

pp dfs1(int i,int p)
{
  v1[i][0]+=pw1[i];
  v1[i][1]+=pw2[i];
  rep(j,sz(adj[i]))
  {
    int u=adj[i][j];
    if(u!=p)
    {
      pp tmp=dfs1(u,p1[u]);
      v1[i][0]+=tmp.X;
      v1[i][1]+=tmp.Y;
    }
  }
  return mp(v1[i][0],v1[i][1]);
}

pp dfs2(int i,int p)
{
  v2[i][0]+=pw1[i];
  v2[i][1]+=pw2[i];
  rep(j,sz(adj2[i]))
  {
    int u=adj2[i][j];
    if(u!=p)
    {
      pp tmp=dfs2(u,p2[u]);
      v2[i][0]+=tmp.X;
      v2[i][1]+=tmp.Y;
    }
  }

  return mp(v2[i][0],v2[i][1]);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int pa=31,pb=8537,t1=pa,t2=pb;
    rep(i,MAX)
    {
      pw1[i]=t1,t1*=pa;
      pw2[i]=t2,t2*=pb;
    }

    int n;cin>>n;
    repA(i,2,n)cin>>p1[i],adj[i].pb(p1[i]),adj[p1[i]].pb(i);
    repA(i,2,n)cin>>p2[i],adj2[i].pb(p2[i]),adj2[p2[i]].pb(i);

    dfs1(1,0);
    dfs2(1,0);

    int cnt=0;

    repA(i,2,n)
    {
      pp t=mp(v1[i][0],v1[i][1]);
      if(mp.find(t)==mp.end())mp[t]=1;
      else mp[t]++;
    }
    repA(i,2,n)
    {
      pp t=mp(v2[i][0],v2[i][1]);
      if(mp.find(t)!=mp.end())cnt++;
    }
    cout<<cnt<<endl;


    return 0;
}
