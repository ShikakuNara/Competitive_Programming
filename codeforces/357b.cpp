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

const int MAX = 100009;
const int MOD = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,m; cin>>n>>m;

    ll mp[MAX] = {0};
    rep(i, MAX)
      mp[i] = -1;

    rep(i, m)
    {
      ll a,b,c; cin>>a>>b>>c;

      if(mp[a] == -1 && mp[b] == -1 && mp[c] == -1)
      {
        mp[a] = 0, mp[b] = 1, mp[c] = 2;
        // cout<< a<<", "<<b<<", "<<c<<end;
      }
      else if(mp[a] != -1)
      {
        mp[b] = (mp[a]+1)%3;
        mp[c] = (mp[a]+2)%3;
      }
      else if(mp[b] != -1)
      {
        mp[a] = (mp[b]+1)%3;
        mp[c] = (mp[b]+2)%3;
      }
      else if(mp[c] != -1)
      {
        mp[a] = (mp[c]+1)%3;
        mp[b] = (mp[c]+2)%3;
      }
    }

    repA(i,1, n)
    {
      cout << mp[i] +1<<' ';
    }



    return 0;
}
