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

const int MAX = 400009;
const int MOD = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    string a, b; cin >> a>>b;
    ll sum = 0, psum = 0, cnt = 0;

    rep(i, sz(a))
    {
      if(a[i] == '+') sum++;
      else sum--;
    }
    rep(i, sz(b))
    {
      if(b[i] == '+') psum++;
      else if(b[i] == '-') psum--;
      else cnt++;
    }
    sum -= psum;
    if(sum < 0) sum = -sum;

    if(cnt < sum || cnt + sum % 2 == 1)
    {
      cout << fixed << setprecision(12) << (double)(0) << end;
    }
    else
    {
      double f[12];
      f[0] = 1; f[1] = 1;

      repA(i, 2, 11)
      {
        f[i] = f[i-1] * i;
      }

      double ans = 1;

      ans *= f[cnt];
      ans /= f[(cnt+sum)/2];
      ans /= f[(cnt-sum)/2];

      rep(i, cnt)
      {
        ans /= (double)2;
      }


       cout << fixed << setprecision(12) << ans << end;
    }







    return 0;
}
