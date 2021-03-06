#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;


typedef long long int ll;
typedef long double ld;
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
const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int vis[MAX],ev[MAX],deg[MAX];
set<int> que;
vi adj[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      fill(vis),fill(ev),fill(deg);rep(i,MAX)adj[i].clear();
      int n,m;cin>>n>>m;

      rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        deg[u]++,deg[v]++;
        adj[u].pb(v),adj[v].pb(u);
      }
      rep(i,n)if(deg[i]%2==0)ev[i]=1,que.insert(i);

      int st=0;
      while(que.size()!=0){
        auto it=que.begin();
        int u=*it;que.erase(it);

        if(ev[u]==0||vis[u]==1)continue;
        else vis[u]=1;
        // cout<<u+1<<':'<<st+1<<endl;
        st++;

        trav(i,adj[u]){
          if(vis[i]==0){
            if(ev[i]==0)que.insert(i);
            ev[i]^=1;
          }
        }
      }
      if(st%2==1)cout<<1<<endl;
      else cout<<0<<endl;
    }





    return 0;
}
