#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
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

const int MAX = 110;
const ll INF = 1000000;
const int MOD = 1e9+7;

ll n, m, a[MAX], b[MAX], res[210][210] = {0},
   mf = 0, f, s, t, vis[210] ={0}, p[210] = {0};//bfs spanning tree
vll adj[210];//2*n + 2: 0, (1,2 ... n), (n+1,n+2, 2*n), 2*n+1


void augmentingpath(ll v, ll minedge)
{
  if(v == s)
  {
     f = minedge;
     return;
  }
  else
  {
    if(p[v] != -1)
    {
      augmentingpath(p[v], min(minedge, res[p[v]] [v]));
      res[p[v]] [v] -= f, res[v] [p[v]] += f;

      if(res[p[v]] [v] > 0) adj[v].pb(p[v]);

      //Future Optimisation
      // if(res[p[v]] [v] <= 0) //pop v from adj[p[v]]
    }
  }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    cin>>n>>m; ll sum = 0, sum2 = 0;
    //Set source and sink
    s = 0, t = 2*n+1;

    rep(i, n) cin >> a[i], sum+=a[i];
    rep(i, n) cin >> b[i], sum2+= b[i];

    if(sum != sum2) {cout << "NO\n"; return 0;}

    //Make Graph
    repA(i, 1, n){
      adj[s].pb(i);
      adj[n+i].pb(t);
      adj[i].pb(n+i);

      res[s][i] = a[i-1];
      res[n+i][t] = b[i-1];
      res[i][n+i] = INF;
    }
    rep(i, m){
      ll x, y; cin>>x>>y;
      adj[x].pb(n+y);
      adj[y].pb(n+x);
      res[x][n+y] = INF;
      res[y][n+x] = INF;
    }


    //Edmonds Carp
    while(1)
    {
      f = 0;
      rep(i, 210) p[i] = -1, vis[i] = 0;

      qll que; que.push(s); vis[s] = 1;

      while(!que.empty())
      {
        ll u = que.front(); que.pop();

        if(u == t) break;

        rep(i, sz(adj[u]))
        {
          ll v = adj[u][i];
          if(res[u][v] > 0 && vis[v] == 0)
          {
            que.push(v), vis[v] = 1, p[v] = u;
          }
        }
      }

      augmentingpath(t, INF);
      if(f == 0) break;
      mf += f;
    }

    //Output
    if(mf == sum)
    {
      cout << "YES\n";
      repA(i, 1, n)
      {
        repA(j, 1, n)
        {
          if(res[i][j+n] != 0)
          cout << INF-res[i][j+n] << ' ';
          else
          cout << res[i][j+n]<<' ';
        }
        cout << end;
      }
    }
    else
    {
      cout << "NO\n";
    }



    return 0;
}
