// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

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
ll sum[200006];
ll maxsum[200006];
ll vis[200006];
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

void dfs(ll i)
{

    vis[i] = 1;

    ll ss = a[i];

    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs(adj[i][j]);
          ss += sum[adj[i][j]];
      }
    }

    sum[i] = ss;
    return;
}

void dfs3(ll i)
{
    vis[i] = 1;

    int flg = 0;
    ll m;
    for (size_t j = 0; j < adj[i].size(); j++) {

      if(vis[adj[i][j]] == 0)
      {
          dfs3(adj[i][j]);
          if(flg == 0)
          {
            m = maxsum[adj[i][j]];
            flg = 1;
          }
          else
          {
            if( m < maxsum[adj[i][j]])
              m = maxsum[adj[i][j]];
          }
      }

    }

    if(flg == 0)
    {
      maxsum[i] = sum[i];
    }
    else
    {
      maxsum[i] = max(m, sum[i]);
    }

    return;
}

void dfs2(ll i)
{

    vis[i] = 1;

    int count = 0;
    ll mc[3]; ll maxx; //mmax initialised

    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs2(adj[i][j]);

          if(count > 1)
          {
            mc[2] = maxsum[adj[i][j]];
            count++;
            sort(mc, mc+3, greater<int>());
          }
          else if(count > 0)
          {
            mc[1] = maxsum[adj[i][j]];
            count++;
          }
          else{
            mc[0] = maxsum[adj[i][j]];
            count++;
          }
      }
    }


    if(count > 1)
    {
      if(maxxx < mc[0] + mc[1])
        maxxx = mc[0] + mc[1];
    }

    return ;
}


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    cin >> n;

    if(n < 3)
    {
      cout << "Impossible\n";
    }

    else
    {
      a.pb(0);
      for (size_t i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
        /* code */
      }

      for (size_t i = 0; i < 200006; i++) {
        vis[i] = 0;
        /* code */
      }

      for (size_t i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
        /* code */
      }


      //sum at each element
      dfs(1);

      for (size_t i = 0; i < 200006; i++) {
        vis[i] = 0;
        /* code */
      }

      dfs3(1);

      //two max child while maintaining maximum sum
      for (size_t i = 0; i < 200006; i++) {
        vis[i] = 0;
        /* code */
      }
      // for (size_t i = 1; i <= n; i++) {
      //   cout << sum[i] << " ";
      //   /* code */
      // } cout << endl;
      //
      // for (size_t i = 1; i <= n; i++) {
      //   cout << maxsum[i] << " ";
      //   /* code */
      // } cout << endl;

      dfs2(1);

      if(maxxx == llinf)
        cout << "Impossible\n";
      else
        cout << maxxx << "\n";

    }

    // cout.close();
    // cin.close();

    return 0;
}
