#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll, pp > ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;
typedef priority_queue<ppp > pq;

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

const int MAX = 100009;
const int MOD = 1e9+7;

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

bool comp(ppp a, ppp b)
{
  if(a.X < b.X) return 1;
  if(a.X == b.X)
  {
    if(a.Y.X > b.Y.X) return 1;
  }
  return 0;
}

ll n, m, s0 = 0, s1 = 0, mm = 1, flag = 0;
vpp sol(MAX, mp(0, 0)), ans;//ans(MAX, mp(0, 0));
vppp edge; //edge(MAX, mp(0,mp(0, 0)));
// pq pos;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    cin>>n>>m;

    rep(i, m)
    {
      ll a, b; cin>>a>>b;
      // edge[i] = mp(a, mp(b, i));
      edge.pb(mp(a, mp(b, i)));
    }

    sort(edge.begin(), edge.end(), comp);

    ll u = 3, v = 1;

    rep(i, m)
    {
      if(edge[i].Y.X == 0)
        s0++;
      else
        s1++;

      if(edge[i].Y.X == 0 &&  s1 < 2 && s0 != 0)
      {
        flag = 1;
      }
      else if(edge[i].Y.X == 0 && s0 > (s1*(s1-1))/2)
      {
        flag = 2;
      }
      else if(edge[i].Y.X == 0)
      {

        if(v < u-1)
        {
          v++;
        }
        else if( u < mm)
        {
          u++; v = 2;
        }
        else
        {
          flag = 1;
        }

        ans.pb(mp(u, v));

      }
      else
      {
        mm++;
        if(mm > n)
        {
          flag = 4;
        }

        ans.pb(mp(1, mm));
      }
    }

    if(flag != 0)
    {
      cout<<-1<<'\n';
    }
    else
    {
      rep(i, m)
      {
        ll j = edge[i].Y.Y;
        sol[j] = ans[i];
      }
      rep(i, m)
      {
        cout<<sol[i].X<<" "<<sol[i].Y<<'\n';
      }
    }

    return 0;
}
