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
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll x[109],y[109];

int vis[109];
vi adj[109];

bool dfs(int i,int v){
  vis[i]=1;
  rep(j,sz(adj[i])){
    int u=adj[i][j];
    if(u==v)return true;
    if(!vis[u]&&dfs(u,v))return true;
  }
  return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int q;cin>>q;int ii=0;

    rep(i,q){
      int t;cin>>t;
      if(t==1){
        cin>>x[ii]>>y[ii];ii++;

        rep(i,ii)rep(j,ii)if(i!=j){
          if(x[j]<x[i]&&x[i]<y[j])
            adj[i].pb(j);
          else if(x[j]<y[i]&&y[i]<y[j])
            adj[i].pb(j);
        }
      }
      else{
        fill(vis);
        int i,j;cin>>i>>j;i--,j--;
        if(dfs(i,j))cout<<"YES\n";
        else cout<<"NO\n";
      }
    }




    return 0;
}
