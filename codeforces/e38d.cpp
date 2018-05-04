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
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'


typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 500009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

vpp adj[MAX];
ll dist[MAX],a[MAX];
ll n,m;

void dij(){
  priority_queue<pp > pq;

  rep(i,n)dist[i]=a[i],pq.push(mp(-a[i],i));

  while(!pq.empty()){
    pp cur=pq.top();pq.pop();
    int i=cur.snd;cur.fst*=-1;

    if(dist[i]<cur.fst)continue;
    dist[i]=cur.fst;
    // cout<<i<<endl;

    // cout<<"pushing...\n";
    rep(j,sz(adj[i])){
      int k=adj[i][j].snd;
      ll w=adj[i][j].fst;
      if(dist[i]+w<dist[k])
        pq.push(mp(-dist[i]-w,k));//cout<<adj[i][j].snd<<",";
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n>>m;
    rep(i,m){
      ll u,v,w;cin>>u>>v>>w;
      u--,v--;w*=2;
      adj[u].pb(mp(w,v));
      adj[v].pb(mp(w,u));
    }
    rep(i,n)cin>>a[i];

    dij();

    rep(i,n)cout<<dist[i]<<' ';cout<<endl;


    return 0;
}
