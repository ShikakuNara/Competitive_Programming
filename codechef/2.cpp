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
    return a * (b / gcd(a, b));
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

const int MAX = 400009;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin>>n;

    ll mp[3][10];

    rep(i, 10)
    {
      mp[0][i] = 0;
      mp[1][i] = 0;
      mp[2][i] = 0;
    }

    rep(i, n)
    {
      rep(j, 6)
      {
        ll tmp; cin>>tmp;
        mp[i][tmp] = 1;
      }
    }


    ll flag = 0, i=0, j=0, k=0;

    for (k = 1; flag == 0 && k <= 9; k++) {
        if(mp[2][k] == 1|| mp[1][k] == 1 || mp[0][k] == 1)
        {

        }
        else
        {
          flag = 1;
          break;
        }
    }

    if(flag == 1)
    {
      cout <<k-1<<end; return 0;
    }

    for (j = 1; flag == 0 && j <= 9; j++) {
      for (k = 0; flag == 0 && k <= 9; k++) {
        if(mp[1][j]== 1 && mp[2][k]== 1)
        {
        }
        else if(mp[2][j]== 1 && mp[1][k]== 1)
        {
          continue;
        }
        else if(mp[0][j]== 1 && mp[2][k]== 1)
        {
          continue;
        }
        else if(mp[2][j]== 1 && mp[0][k]== 1)
        {
          continue;
        }
        else if(mp[0][j]== 1 && mp[1][k]== 1)
        {
          continue;
        }
        else if(mp[1][j]== 1 && mp[0][k]== 1)
        {
          continue;
        }
        else
        {
          flag = 1; break;
        }
      }

      if(flag == 1)
      {break;}
    }

    if(flag == 1)
    {
      cout << j*10+k-1<<end; return 0;
    }

    return 0;
}
