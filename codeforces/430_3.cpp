#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

const ll llinf = -1000000000000000000;

vll adj[200006];
ll n;
vll a;
ll vis[200006], g[200006], gmax[200006], rem[200006];
ll maxxx = llinf;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
ll npwtw (ll n)
{
  n--;
  n|= n >> 1;
  n|= n >> 2;
  n|= n >> 4;
  n|= n >> 8;
  n|= n >> 16;
  n|= n >> 32;
  n++;
  return n;
}
int ispwtw (ll n)
{
  return !(n&(n-1));
}

ll dfs(ll i)
{
    vis[i] = 1;

    ll g = a[i];

    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          g = gcd( dfs(adj[i][j]), g);
      }
    }

    return g;
}

void dfs2(ll i, ll r, ll gcdmaxpr, ll gcdpr)
{
    vis[i] = 1;


    ll x = gcd( gcdmaxpr, a[i]), y = gcd(gcdpr, a[i]);

    ll ans;
    if( r == 1)
    {
      if( x > gcdpr)
      {
        r = 1; ans = x;
      }
      else
      {
        if ( gcdpr > y)
        {
          ans = gcdpr; r = 1;
        }
        else
        {
          r = 0; ans = y;
        }
      }
    }
    else
    {
      if( gcdpr > y)
      {
        ans = gcdpr; r = 1;
      }
      else{
        ans = y; r = 0;
      }
    }

    gmax[i] = ans;

    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs2(adj[i][j], r, ans, y);
      }
    }

    return;
}

int main()
{
    ifstream cin("in.txt"); ofstream cout("out.txt");

    cin >> n; cout << n << endl;

    for (size_t i = 0; i < n; i++) {
      ll tmp; cin >> tmp;
      a.pb(tmp);
      /* code */
    }

    for (size_t i = 0; i < 200006; i++) {
      vis[i] = 0; rem[i] = 0; gmax[i] = 1; g[i] = 1;
      /* code */
    }

    // for (size_t i = 0; i < n-1; i++) {
    //   ll abc, b;
    //   cin >> abc >> b;
    //   abc--; b--;
    //
    //   cout << abc << " " << b << "\n";
    //
    //   // adj[abc].pb(b);
    //   // adj[b].pb(abc);
    //   /* code */
    // }


    //sum at each element
    // dfs(0);
    //
    // for (size_t i = 0; i < 200006; i++) {
    //   vis[i] = 0;
    //   /* code */
    // }
    //
    // // dfs2(0, 0, a[0], a[0]);
    //
    //
    // for (size_t i = 0; i < n; i++) {
    //   cout << g[i] << " ";
    //
    //   /* code */
    // }
    // cout << "\n";


    cout.close();  cin.close();

    return 0;
}
