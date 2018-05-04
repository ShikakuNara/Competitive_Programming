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
#define PI 3.14159265

const int MAX = 100009;
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

std::map<int, bool> mp;

ll sol[MAX] = {0}, soli[MAX] = {0};

pp ans = make_pair(-1, -1);

ll s(ll n, ll t, ll num)
{
    if( n <= 64)
    {
      num += sol[soli[n]];
      t += soli[n];
      ans = max(ans, make_pair(num, t));
      return sol[soli[n]];
    }

    ll i;
    for ( i = 0; i <= (ll)1e5; i++) {
      if(i*i*i > n)
        break;
      /* code */
    } i--;

    return 1 + max( s(n - i*i*i, t+i*i*i, num+1), s(i*i*i - 1 - (i-1)*(i-1)*(i-1), t+ (i-1)*(i-1)*(i-1), num+1));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    for (size_t i = 0; i <= 63; i++) {
      ll itmp = i;
      if(itmp >= 27)
      {
        sol[i] += itmp / 27; itmp %= 27;
      }
      if(itmp >= 8)
      {
        sol[i] += itmp / 8; itmp %= 8;
      }
      sol[i] += itmp;
    } sol[64] = 1;
    ll max = -1, indm= -1;
    // calculate sol
    for (size_t i = 0; i <= 64; i++) {
      if(sol[i] > max)
      {
        max = sol[i];
        indm = i;
      }
      else if(sol[i] == max)
      {
        indm = i;
      }
      soli[i] = indm;
    }
    for (size_t i = 0; i < (ll)1e5; i++) mp[i*i*i] = true;

    ll n; cin>>n;
    ll tmp = s(n, 0, 0);

    cout<< ans.first << " " <<  ans.second <<end;




    return 0;
}
