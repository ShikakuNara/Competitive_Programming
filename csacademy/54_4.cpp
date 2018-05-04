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
typedef priority_queue<pp , vector<pp >, std::greater<pp > > pq;

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

const int MAX = 5010;
const int MOD = 1e9+7;

ll p[MAX] = {0}, r[MAX] = {0}, cnt[MAX] = {0};

ll findset(ll i)
{
  if(p[i] != i)
    p[i] = findset(p[i]);

  return p[i];
}

void merge(ll i, ll j)
{
  if(p[i] == p[j])
    return;

  i = findset(i);
  j = findset(j);

  if(r[i] > r[j])
  {
    p[j] = i;
    return;
  }
  p[i] = j;

  if(r[i] == r[j]) r[j]++;

  return;
}


bool sameset(ll i, ll j)
{
  return findset(i) == findset(j);
}

void build(ll n)
{
  repA(i,0, n) p[i] = i;
  repA(i,0, n) cnt[i] = 1;
}

ll n, m, vis[MAX] = {0}, deg = 0;
vpp adj[MAX];
pq que;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


     cin >> n >> m;

    build(n);

    rep(i, m) //input
    {
      ll a, b, c; cin>>a>>b>>c;

      merge(a, b);

      if(c == 0 && (a == 1 || b == 1))
      {
        deg++;
      }

      adj[a].pb(mp(c, b));
      adj[b].pb(mp(c, a));
    }

    if(findset(1) != findset(n)) //edge case
    {
      cout << -1 << end;
      return 0;
    }


    vis[1] = 1;
    rep(i, sz(adj[1]))
    {
      pp v = adj[1][i];

      if(deg < 2 && v.X % 2 == 1)
      {
        v.X += 2;
      }
      else
      {
        v.X++;
      }

      // cout << v.X << ", " << v.Y << end;
      que.push(v);
    }

    while(!que.empty())
    {
      pp tmp = que.top(); que.pop();
      vis[tmp.Y] = 1;

      // cout << "pop: " << tmp.X << ", " << tmp.Y << end;

      // cout << tmp.X << end;

      if(tmp.Y == n)
      {
        cout << tmp.X << end;
        return 0;
      }

      rep(i, sz(adj[tmp.Y]))
      {
        pp v = adj[tmp.Y][i];
        // cout << "    " << v.X << ", " << v.Y << end;

        if(vis[v.Y] == 1) continue;

        if(v.X < tmp.X)
        {
          v.X = tmp.X+1;
        }
        else
        {
          if(deg < 2 && (v.X - tmp.X + 40)% 2 == 1)
          {
            v.X += 2;
          }
          else
            v.X++;
        }

        // cout << v.X << ", " << v.Y << ": " << tmp.X << ", " << tmp.Y << end;
        que.push(v);
      }
    }

    return 0;
}
