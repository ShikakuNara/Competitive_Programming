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
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

const int MAX = 100009;
const int MOD = 1e9+7;

vll adj[MAX]; ll n, k, deg[MAX] = {0}; pp d[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>k; ll flag =0;

    rep(i, n)
    {
      ll tmp; cin>>tmp;
      d[i] = mp(tmp, i);

      if( d[i].X == 0 && flag == 1)
      {
        cout << -1<<end;
        return 0;
      }
      else if(d[i].X == 0)
      {
        flag = 1;
      }
    }

    if(flag == 0)
    {
      cout<<-1<<end;
      return 0;
    }

    sort(d, d+n);

    ll cur = 0, cnt = 0;
    repA(i, 1, n-1)
    {

      ll u = d[i].Y;

      while(d[i].X - d[cur].X > 1)
      {
        cur++;
        if(cur >= i || cur >= n)
        {
          cout<<-1<<end;
          return 0;
        }
      }

      while(d[i].X - d[cur].X == 1 && deg[  d[cur].Y ] >= k)
      {
          cur++;
          if(cur >= i || cur >= n)
          {
            cout<<-1<<end;
            return 0;
          }
      }

      if(d[i].X - d[cur].X == 1 && deg[  d[cur].Y ] < k)
      {
        adj[ d[cur].Y ].pb(u);
        cnt++;
        deg[  d[cur].Y ]++;
        deg[  u ]++;
      }
      else if(d[i].X - d[cur].X < 1)
      {
        cout << -1<<end;
        return 0;
      }
    }

    cout <<cnt<<end;
    rep(i, n)
    {
      rep(j, sz(adj[i]))
      {
        cout << i+1 << ' ' << adj[i][j] + 1<<end;
      }
    }



    return 0;
}
