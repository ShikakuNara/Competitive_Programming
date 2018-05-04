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
typedef vector<pp> vpp;
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
#define sortD(v)      (sort(v.rbegin(), v.rend())
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

const ll MAX = 300006;

vll adj[MAX];
ll n;
ll vis[MAX] = {0}, white[MAX] = {0}, cnt[MAX] = {0};


void dfs(ll i)
{
    vis[i] = 1;

    if(white[i] == 1)
      cnt[i] += 1;

    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs(adj[i][j]);
          cnt[i] += cnt[adj[i][j]];
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

    cin >> n;

    for (size_t i = 0; i < n-1; i++) {
      ll a, b, c; cin >> a >> b >> c;


      if( c == 2)
      {
        white[a] = 1; white[b] = 1;
      }

      adj[a].pb(b);
      adj[b].pb(a);
    }


    dfs(1);

    ll count = 0;
    for (size_t i = 0; i <= n; i++) {
      if(cnt[i] == 1)
        count++;
    }

    cout << count << end;
    for (size_t i = 0; i <= n; i++) {
      if(cnt[i] == 1)
        cout << i << ' ';
    }

    return 0;
}
