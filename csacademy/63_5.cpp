#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #paagma comment(linker, "/stack:16777216")
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
const long double PI=3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
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
const int MAX=10009;
const int MOD=1e9+7;
const int inf=1e9+10;

#define MAXN 100000
#define level 18

vi tree[MAX];
int depth[MAX];
int pa[MAX][level];

// pae-compute the depth foreach node and their
// first pa(2^0th pa)
// time complexity : O(n)
void dfs(int cur,int paev){
    depth[cur] = depth[paev] + 1;
    pa[cur][0] = paev;
    for (int i=0;i<tree[cur].size(); i++){
        if(tree[cur][i] != paev)
            dfs(tree[cur][i],cur);
    }
}

// Dynamic paogramming Sparse Matrix Appaoach
// populating 2^i pa foreach node
// Time complexity : O(nlogn)
void paecomputeSparseMatrix(int n){
    for (int i=1;i<level;i++){
        for (int node=1;node <= n;node++){
            if(pa[node][i-1] != -1)
                pa[node][i] =
                    pa[pa[node][i-1]][i-1];
        }
    }
}

// Returning the LCA of u and v
// Time complexity : O(log n)
int lca(int u,int v){
    if(depth[v]<depth[u])swap(u,v);

    int diff=depth[v]-depth[u];

    // Step 1 of the pseudocode
    for(int i=0;i<level;i++)
        if((diff>>i)&1)
            v=pa[v][i];

    // now depth[u] == depth[v]
    if(u==v)return u;

    // Step 2 of the pseudocode
    for (int i=level-1;i>=0;i--)
        if(pa[u][i]!=pa[v][i]){
            u=pa[u][i];
            v=pa[v][i];
        }

    return pa[u][0];
}

void adde(int u,int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
}

int si[MAX]={0},vis[MAX]={0};

int dfs2(int i){
  vis[i]=1;

  int sum=1;
  trav(u,tree[i]){
    if(vis[u]==0)sum+=dfs2(u);
  }
  return si[i]=sum;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,q;cin>>n>>q;
    rep(i,n-1){
      int u,v;cin>>u>>v;
      adde(u,v);
    }
    dfs(1,0);
    dfs2(1);
    paecomputeSparseMatrix(n);

    rep(i,q){
      int a,b,c;cin>>a>>b>>c;
      int ans=1;
      int x=-1,y=-1;
      if(lca(c,a)==c)x=0;
      else if(lca(c,a)==a)x=1;
      if(lca(c,b)==c)y=0;
      else if(lca(c,b)==b)y=1;

      int ab=lca(a,b);

      int ff=0;
      if(y==0)ff=1;
      if(x==0)ff=1;
      if(x==0&&y==0)if(lca(c,ab)==ab)ff=1;
      if(x==1&&y==1)ff=0;


      if(ff==1){
        // cout<<"hh\n";
        trav(u,tree[c]){
          int s=si[u];
          if(lca(u,c)==u)s=n-si[c];

          if(lca(u,a)!=u&&lca(u,b)!=u)ans+=s,cout<<u<<",";
          else if(lca(u,a)==u&&lca(u,b)==u&&lca(u,c)==u)ans+=s,cout<<u<<",";
        }
        cout<<endl;
      }
      else{cout<<0<<endl;continue;}
      cout<<ans<<endl;
    }


    return 0;
}
