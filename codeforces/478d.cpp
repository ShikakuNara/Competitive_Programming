#include <bits/stdc++.h>

#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

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
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define end '\n'
#define PI 3.14159265

const int MAX = 300009;
const ll MOD = 1e9 + 7;
#define _  %  MOD
#define __ %= MOD

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll r,g; cin>>r>>g;
    r=r+g;
    g=r-g;
    r=r-g;

    ll n, d[MAX] = {0};

    for (n = 0; n < 1000; n++) {
        if(n*(n+1) > 2*(r+g))
        {
          break;
        }
    } n--;

    d[0] = 1;
    for (ll i = 1; i <= n; i++) {
      ll sum = (i*(i+1))/2;

      for (ll j = r; j >= 0; j--) {
        if(sum > j+g)
        {
          d[j] = 0;
        }
        else if( j - i >= 0)
        {
          d[j] += d[j-i];
          d[j] __;
        }
      }
    }

    ll ans = 0;

    for (ll i = 0; i <= r; i++) {
      ans += d[i];
      ans __;
    }

    cout<<ans<<end;

    return 0;
}
