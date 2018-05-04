#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  #pragma comment(linker, "/stack:16777216")
#endif
#ifndef LOCAL_TEST
  #include <bits/stdc++.h>
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef pair<ll , pp> ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) ll((a).size())
#define pb push_back
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define PI 3.14159265

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt");
      ofstream cout("out.txt");
    #endif

    ll m, t, r; cin >> m >> t >> r;

    if(t < r)
    {
      cout << -1 << end;
      return 0;
    }

    ll w[310] = {0}, c[310] = {0};

    for (size_t i = 0; i < m; i++) {
      cin >> w[i];
    }

    ll count = 0;
    for (size_t i = 0; i < m; i++) {
      if(c[0] - w[i] <= 0)//candel is off
      {
        //find last off candle
        ll j;
        for (j = r-1; j >= 0 && c[j] - w[i] > 0; j--);

        //lighted the candles
        for (; j >= 0; j--) {
          c[j] = t + w[i] - j;
          count++;
        }

        sort(c, c+r);//arrange
      }
    }


    cout << count << end;

    return 0;
}
