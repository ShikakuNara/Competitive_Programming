#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < ll > sll;
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


const int MAX = 40;
ll adj[MAX][MAX]; ll n, vis[MAX] = {0}, flag = 0;
qll srt;

void dfs(ll i)
{
  vis[i] = 1;

  rep(j, n)
  {
    if(flag != 0) break;

    if(j == i || adj[i][j] == 0) continue;

    ll u = j;
    if(vis[u] == 1)
    {
      // cout << i << ", "<< u <<end;
      flag = 1;
    }
    else if(vis[u] == 0)
    {
      dfs(u);
    }
  }

  vis[i] = 2;
  srt.push(i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n; ll t = 0;
    std::map<string, ll> mp;
    std::map<ll, string> mp2;

    while(n != 0 && t < 3)
    {
      t++;
      flag= 0;
      mp.clear(), mp2.clear();
      // rep(i, 40) adj[i].clear();
      rep(i, 40)
      {
        rep(j, 40) adj[i][j] = 0;
      }
      fill(vis);


      rep(i, n)
      {
        string a; cin>> a; mp[a] = i; mp2[i] = a;
      }

      rep(i, n)
      {
        string a; cin>>a;
        ll aa, u = mp[a]; cin>>aa;

        rep(i, aa)
        {
          cin >> a;
          ll v = mp[a];
          // cout << u << ", " << v<<end;
          adj[u][v] = 1;//.pb(v);
        }
      }

      fill(vis);
      rep(i, n)
      {
        if(vis[i] == 0)
        {
          // cout << i <<", ";
          dfs(i);
        }

      }

      cout <<"Test "<<t<<end;
      if(flag != 0) cout << "impossible\n\n";
      else
      {
        ll f = 0;
        while(!srt.empty())
        {
          // if(f == 1)
          //   cout<<" ";
          // f = 1;

          ll tmp = srt.front(); srt.pop();
          cout << mp2[tmp] <<" ";

        } cout << end<<end;
      }


      cin>>n;
    }


    return 0;
}
