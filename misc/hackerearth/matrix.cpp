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

const int MOD = 1e9+7;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
ll Abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double Abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

ll mini(ll a, ll b)
{
  if(a < b) return a;
  return b;
}


const int MAX = 600009;
ll tree[MAX] = {0};  // To store segment tree

void updateU(ll i, ll s, ll e, ll us, ll ue, ll diff)
{
    if (s>e || s>ue || e<us)
        return ;

    if (s>=us && e<=ue)
    {
        tree[i] = mini(diff, tree[i]);

        return;
    }

    ll m = (s+e)/2;
    updateU(i*2+1, s, m, us, ue, diff); updateU(i*2+2, m+1, e, us, ue, diff);

    tree[i] = mini(tree[i*2+1], tree[i*2+2]);
}

void update(ll us, ll ue, ll diff, ll n)
{
   updateU(0, 0, n-1, us, ue, diff);
}

ll getSumU(ll s, ll e, ll qs, ll qe, ll i)
{
    if (s>e || s>qe || e<qs)
        return 10000000000;

    if (s>=qs && e<=qe)
    {
        // cout << s << ", " << e << ", " << tree[i] << end;
        return tree[i];
      }

    ll m = (s + e)/2;
    return mini(getSumU(s, m, qs, qe, 2*i+1), getSumU(m+1, e, qs, qe, 2*i+2));
}

ll getSum(ll qs, ll qe, ll n)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumU(0, n-1, qs, qe, 0);
}

void buildtreeU(pp arr[], ll s, ll e, ll i)
{
    if (s > e)
        return ;

    if (s == e)
    {
        tree[i] = arr[s].Y;
        return;
    }

    ll m = (s+e)/2;
    buildtreeU(arr, s, m, i*2+1); buildtreeU(arr, m+1, e, i*2+2);

    tree[i] = mini(tree[i*2 + 1], tree[i*2 + 2]);
}

void buildtree(pp a[], ll  n)
{
  buildtreeU(a, 0, n-1, 0);
  return;
}



pp buil[MAX]; ll n, q, flag = 0;

ll binarysearch(ll s, ll e, ll i)
{
  ll m = (s+e)/2;

  if(s > e)
  {
    flag = 1;
    return 0;
  }

  if(s == e)
  {
    return s;
  }

  if(buil[m].X == i)
  {
    return m;
  }

  if(buil[m].X > i)
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

    cin>>n>>q;
    rep(i, MAX)
    {
      tree[i] = 100000000000;
    }


    rep(i, n)
    {
      ll a, b;
      cin>>a>>b;
      buil[i] = mp(a, b);
    }

    sort(buil, buil+n);

    buildtree(buil, n);
    ll Min = buil[0].X, Max = buil[n-1].X;



    rep(i, q)
    {
      ll u, v, s, t; cin>>u>>v>>s>>t;

      ll low, high;

      if(u <= Min)
      {
        low = 0;
      }
      else if(u >= Max)
      {
          low = n;
      }
      else
      {
        low = binarysearch(0, n-1, u);
      }

      if(s <= Min)
      {
        high = 0;
      }
      else if(s >= Max)
      {
        high = n;
      }
      else
      {
        high = binarysearch(0, n-1, s);
      }

      if(low == high)
      {
        cout << Abs(s-u) + Abs(t-v) << end;
      }
      else
      {
        if(low > high)
        {
          ll tmp = low; low = high; high = tmp;
        }

        ll mmin = getSum(low, high-1, n);

        if(mmin <= v || mmin <= t)
          cout << Abs(s-u) + Abs(v-mmin+1) + Abs(t-mmin+1) <<end;
        else
          cout << Abs(s-u) + Abs(t-v) << end;
      }

    }

    return 0;
}
