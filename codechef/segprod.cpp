#include <bits/stdc++.h>

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
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


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

const int MAX = 40000009;
// const ll  1LL = 1;
#define __ %= MOD
#define _ % MOD
int MOD;
ll tree[MAX] = {0};  // To store segment tree

void updateU(int i, int s, int e, int us, int ue, int diff)
{
    if (s>e || s>ue || e<us)
        return ;

    int m = s + (e-s)/2;
    updateU(i<<1|1, s, m, us, ue, diff); updateU((i<<1)+2, m+1, e, us, ue, diff);

    tree[i] = (1LL*tree[i<<1|1]*tree[(i<<1)+2]) % MOD;
}

void update(int us, int ue, int diff, int n)
{
   updateU(0, 0, n-1, us, ue, diff);
}

ll getSumU(int s, int e, int qs, int qe, int i)
{

    if (s>e || s>qe || e<qs)
        return 1;

    if (s>=qs && e<=qe)
        return tree[i];

    int m = s + (e-s)/2;
    return (getSumU(s, m, qs, qe, i<<1|1)*getSumU(m+1, e, qs, qe,(i<<1)+2)) % MOD;
}

int getSum(int qs, int qe, int n)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Inputs");
        return -1;
    }

    return getSumU(0, n-1, qs, qe, 0);
}

void buildtreeU(int arr[], int s, int e, int i)
{
    if (s > e)
        return ;

    if (s == e)
    {
        tree[i] = arr[s] % MOD;
        return;
    }

    ll m = (s+e)/2;
    buildtreeU(arr, s, m, i<<1|1); buildtreeU(arr, m+1, e, (i<<1)+2);

    tree[i] = (1LL*tree[i<<1|1]*tree[(i<<1)+2]) % MOD;
}

void buildtree(int a[], int  n)
{
  buildtreeU(a, 0, n-1, 0);
  return;
}

int a[1000001] = {0}, b[1000002] = {0};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    int t;scanf("%d", &t);

    rep(aj, t)
    {
      int n,q;scanf("%d %d %d", &n, &MOD, &q);
      rep(i, n) {scanf("%d", a+i);}
      buildtree(a, n);
      rep(i, q/64 + 2) scanf("%d", b+i);

      int lprev, rprev, ans = -1;
      rep(i, q)
      {
        int l, r;
        if(i % 64 == 0)
        {
          l = (b[i/64]+(ans+1)%MOD)%n, r = (b[i/64+1]+(ans+1)%MOD)%n;
        }
        else
        {
          l = (lprev+(ans+1)%MOD)%n, r = (rprev+(ans+1)%MOD)%n;
        }
        if( l > r) {ll tmp = l; l = r; r = tmp;}

        ans = getSum(l, r, n);
        lprev = l, rprev = r;
      }
      cout<<(ans+1)%MOD<<end;
    }


    return 0;
}
