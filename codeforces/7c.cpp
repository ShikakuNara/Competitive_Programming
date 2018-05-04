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
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define fi first
#define se second
#define PI 3.14159265

const int MAX = 500;
const int MOD = 1e9+7;

#define __ %= MOD;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll absn(ll a)
{
  if(a > 0) return a;
  return -a;
}
ll abs(ll a, ll b){
  if( a > b) return a-b;
  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

ll flag = 0;

ll extGcd(ll a, ll b, ll& x, ll& y) {
	if (!a) {
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll d = extGcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
  if( x > 5000000000000000001|| y > 5000000000000000001 || x < -5000000000000000001|| y < -5000000000000000001 )
    flag = 1;

  return d;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a,b,c;cin>>a>>b>>c;

    if( absn(c) % gcd(a, b) != 0)
    {
      cout<<-1<<end;
    }
    else
    {
      ll x, y;

      extGcd(absn(a), absn(b), x, y);

      if(a != absn(a)) x = -x;
      if(b != absn(b)) y = -y;

      x *= -c/gcd(absn(a), absn(b));
      y *= -c/gcd(absn(a), absn(b));

      if(flag ==0)
      cout << x << " " <<  y << end;
      else
      cout << -1<<end;
    }


    return 0;
}
