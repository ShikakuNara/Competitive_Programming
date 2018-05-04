#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  #pragma comment(linker, "/stack:16777216")
#endif
#ifndef LOCAL_TEST
  #include <bits/stdc++.h>
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) ll((a).size())
#define pb push_back
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll abs(ll a, ll b)
{
  if( a > b)
    return a-b;

  return b-a;
}

const int MAX = 300000;

ll n, m, k, s = 0;
ll vis[550][550] = {0}, a[550][550], flag = 0;

void dfs(ll i, ll j)
{

  // cout << i << ", " << j;
    if(i >= n || i < 0 || j >= m || j < 0)
    {
      // cout << ", a\n";
      return;
    }
    else if(a[i][j] != 1)
    {
      // cout << ", b: " << a[i][j] << " \n";
      return;
    }
    else if(vis[i][j] == 1)
    {
      // cout << ", c\n";
      return;
    }

    // cout << end;

    vis[i][j] = 1;
    s++;

    //neighbours
    dfs(i, j+1);
    dfs(i, j-1);
    dfs(i+1, j);
    dfs(i-1, j);

    return;
}

void dfs2(ll i, ll j)
{
    if(flag == 1)
    {
      return;
    }
    else if(i >= n || i < 0 || j >= m || j < 0)
    {
      return;
    }
    else if(a[i][j] != 1)
    {
      return;
    }
    else if(vis[i][j] == 1)
    {
      return;
    }

    vis[i][j] = 1;
    a[i][j] = 2;
    k--;

    if(k == 0)
    {
      flag = 1;
    }

    //neighbours
    dfs2(i, j+1);
    dfs2(i, j-1);
    dfs2(i+1, j);
    dfs2(i-1, j);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin >> n >> m >> k;
    ll x = -1, y = -1;

    for (size_t i = 0; i < n; i++) {
      string s; cin >> s;
      for (size_t j = 0; j < m; j++) {
        if(s[j] == '.')
        {
          if(x == -1)
          {
            x = j; y = i;
          }
          a[i][j] = 1;
        }
        if(s[j] == '#')
          a[i][j] = 0;
      }
    }

    dfs(y, x);
    fill(vis);

    k = s-k;
    dfs2(y, x);

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if(a[i][j] == 0)
          cout << '#';
        else if(a[i][j] == 2)
          cout << '.';
        else if(a[i][j] == 1)
          cout << 'X';
      }
      cout << end;
    }



    return 0;
}
