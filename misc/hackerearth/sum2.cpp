#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<ll, ll> > sii;
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

const ll MAX = 100009;
const ll MOD = 1e9+7;

#define _  %  MOD
#define __ %= MOD

ll prime[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157};


ll d[20][170];

ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}

ll f(ll n, ll sum)
{
  if(sum < 0)
  {
    return 0;
  }

  if( n < 10)
  {
    if ( sum <= n)
    {
      return 1;
    }

    return 0;
  }

  ll m = n, k = 0;
  while(m >= 10)
  {
    k++;
    m /= 10;
  }

  ll ans = 0;
  for (ll i = 0; i < m && sum - i >= 0; i++) {
    ans += d[k][sum-i];
    ans __;
  }

  ans += f(n-m*power(10, k), sum-m);
  ans __;
  return ans;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifdef LOCAL_TEST
    ifstream cin("in.txt"); ofstream cout("out.txt");
  #endif

    ll t; cin >> t;

    for (size_t i = 0; i < 20; i++) {
      for (size_t j = 0; j < 170; j++) {
        d[i][j] = 0;
      }
    }

    for (size_t i = 0; i < 10; i++) d[1][i] = 1;

    for (ll i = 2; i < 20; i++)
      for (ll j = 0; j < 170; j++)
        for (ll k = 0; k < 10 && j-k >= 0; k++)
        {
          d[i][j] += d[i-1][j-k];
          d[i][j] __;
        }

    for (size_t iklm = 0; iklm < t; iklm++) {
      ll l, r; cin >> l >> r;

      ll sum1 = 0, sum2 = 0;

      for (size_t i = 0; i < 37; i++) {
        sum2 += f(r, prime[i]);
        sum2 __;
      }

      for (size_t i = 0; i < 37; i++) {
        sum1 += f(l-1, prime[i]);
        sum1 __;
      }

      if(sum2 - sum1 < 0)
      {
        cout << MOD + sum2 - sum1 << end;
      }
      else
      {
        cout << sum2 - sum1 << end;
      }


    }

    return 0;
}
