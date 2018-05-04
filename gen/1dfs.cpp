#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

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

const int MAX = 2e4+6;
const ll llinf = -1000000000000000000;

vll adj[MAX];
ll n;
vll a;
ll vis[MAX];
// use bitset<MAX> vis; // its faster


void dfs(ll i)
{

    vis[i] = 1;


    for (ll j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs(adj[i][j]);
      }
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
      ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    a.pb(0);
    for (ll i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      a.pb(tmp);
      /* code */
    }

    fill(vis);

    for (ll i = 0; i < n; i++) {
      ll a, b;
      cin >> a >> b;

      adj[a].pb(b);
      adj[b].pb(a);
    }

    dfs(1);
    fill(vis);

    return 0;
}
