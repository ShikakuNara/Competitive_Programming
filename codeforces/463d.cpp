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
const int MAX = 1009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

set<int> adj[MAX];
int a[MAX][6],vis[MAX]={0};

stack<int>stk;
void topo(int i)
{
	vis[i]=1;
	trav(it,adj[i])if(vis[it]==0)topo(it);
	stk.push(i);
}

int dis[MAX]={0};
void dfs(int i)
{
	trav(it,adj[i])dis[it]=max(dis[it],dis[i]+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

	int n,k;cin>>n>>k;
	rep(i,k)rep(j,n)cin>>a[j][i];

	rep(i,n)
	{
		repA(j,i+1,n-1)adj[a[i][0]].insert(a[j][0]);
	}

	repA(kk,1,k-1)rep(i,n)
	{
		repA(j,0,i-1)
		{
			int u=a[i][kk],v=a[j][kk];
			auto it=adj[u].find(v);
			if(it!=adj[u].end())adj[u].erase(it);
		}
	}

	repA(i,1,n)if(vis[i]==0)topo(i);
	fill(dis);
	
	while(!stk.empty())
	{
		int u=stk.top();stk.pop();
		dfs(u);
	}
	int m=-1;
	
	//rep(i,n+1)cout<<i%10;cout<<endl;
	//rep(i,n+1)cout<<dis[i];cout<<endl;
	rep(i,n+1)m=max(dis[i],m);
	cout<<m+1<<endl;

    return 0;
}


