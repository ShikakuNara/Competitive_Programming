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

    ll m, s;cin>>m>>s; ll stmp = s;

    ll min[110], flag =0;
    rep(i, m)
    {
      flag = 0;
      rep(j, 10)
      {
        if(flag == 0 && (i > 0 || j > 0 || (m == 1 && j == 0)) &&  (s-j >=0  && 9*(m-i-1) >= s-j ))
        {
          min[i] = j; flag = 1;
          s -= j;
        }
      }
      if(flag == 0)
      {
        cout << -1 <<' '<<-1<<end;
        return 0;
      }
    }

    rep(i, m)
    {
      cout << min[i];
    }
    cout << ' ';

    ll max[110] ={0}; flag = 0, s = stmp;
    rep(i, m)
    {
      // cout <<'a';

      flag = 0;

      repD(j, 9, 0)
      {
        if(flag == 0 && (i > 0 || j > 0 || (m == 1 && j == 0)) &&  (s-j >=0  && 9*(m-i-1) >= s-j ))
        {
          max[i] = j; flag = 1;
          s -= j;
        }
      }
    }

    rep(i, m)
    {
      cout << max[i];
    }
    cout << ' ';



    return 0;
}
