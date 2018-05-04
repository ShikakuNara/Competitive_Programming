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
typedef vector<pp > vpp;
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

const int MAX = 100009;

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

ll n, k;
vpp b;
vll ans(MAX, 0), kk(MAX, 0);
ll cumsum[MAX] = {0}, pyra[MAX]= {0}, a[MAX] = {0};

ll binarysearch(ll s, ll e, ll i)
{
  ll m = (s+e)/2;

  if(s == e)
  {
    return s;
  }
  else if( a[i] * (i-m+1) - (cumsum[i] - cumsum[m] + a[m])  <=  k)
  {
    return binarysearch(s, m, i);
  }

  return binarysearch(m+1, e, i);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin >> n >> k;

    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a+n);

    ll cur = a[0], ccur = 1;
    for (size_t i = 1; i < n; i++) {
      if(a[i] == cur)
      {
        ccur++;
      }
      else
      {
        pp p = make_pair(cur, ccur);
        b.pb(p);

        cur = a[i];
        ccur = 1;
      }
    }

    pp p = make_pair(cur, ccur);
    b.pb(p);

    cumsum[0] = a[0];;
    for (size_t i = 1; i < n; i++) {
      cumsum[i] = cumsum[i-1] + a[i];
    }


    ans[0] = 1;
    kk[0] = 0;

    for (size_t i = 1; i < n; i++) {
      ll tmp = binarysearch(0, i-1, i);
      ans[i] = i - tmp + 1;
    }

    ll mmax = -1, mi = -1;

    for (size_t i = 0; i < n; i++) {
      if(ans[i] > mmax)
      {
        mmax = ans[i];
        mi = a[i];
      }
    }


    cout << mmax << " " << mi;

    return 0;
}
