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

const int MAX = 2010;
const int MOD = 1e9+7;

ll memo[MAX][MAX] ={0};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n; cin >> n;

    ll one=0, two=0, three=0;
    rep(i, n)
    {
      ll a, b; cin>>a>>b;

      if(a%2==1 && b%2==1)
      {
        one++;
      }
      else if((a%2== 0&& b%2==1))
      {
        two++;
      }
      else if((a%2== 1 && b%2==0))
      {
        three++;
      }
    }

    if((two+three)%2 == 0)
    {
      if(one % 2 == 0)
      {
        if(two%2 == 0) cout << 0<<end;
        else cout << 1 << end;
      }
      else
      {
        if(two % 2 == 1) cout << 0 <<end;
        else if(two != 0 || three != 0)cout<<1<<end;
        else cout << -1<<end;
      }
    }
    else
    {
      cout<<-1<<end;
    }

    return 0;
}
