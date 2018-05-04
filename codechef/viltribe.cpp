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

    ll t; cin>>t;

    rep(aaja, t)
    {
      string a; cin>>a;

      ll aa=0, bb=0, cur = 0; char buf = 0;
      rep(i, sz(a))
      {

        if(buf != 0)
        {
          if(a[i] == '.') cur++;
          else if(a[i] == buf && buf == 'A') aa +=cur+1, cur=0,buf=0;
          else if(a[i] == buf && buf == 'B') bb +=cur+1, cur=0,buf=0;
          else if(a[i]== 'B') bb++, cur=0,buf=0;
          else if(a[i]== 'A') aa++, cur=0,buf=0;
        }
        else if(a[i] == 'A') aa++;
        else if(a[i] == 'B') bb++;
        else {
          if(i > 0 && a[i-1] != '.')
            buf = a[i-1], cur++;
        }
      }
      cout << aa <<' '<<bb<<end;
    }




    return 0;
}
