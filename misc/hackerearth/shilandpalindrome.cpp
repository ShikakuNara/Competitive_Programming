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

const int MAX = 200009;
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

#define LOGSZ 17

ll tree[27][MAX] = {0};//[(1<<LOGSZ)+1];
ll N;// = (1<<LOGSZ);
// add v to value at x
void Set(ll x, ll v, ll i) {
  while(x <= N) {
    tree[i][x] += v;
    x += (x & -x);
  }
}
// get cumulative sum up to and including x
ll get(ll x, ll i) {
  ll res = 0;
  while(x) {
    res += tree[i][x];
    x -= (x & -x);
  }
  return res;
}
// get largest value with cumulative sum less than or equal to x;
// for smallest, pass x-1 and add 1 to result
ll getind(ll x, ll i) {
  ll idx = 0, mask = N;
  while(mask && idx < N) {
    ll t = idx + mask;
    if(x >= tree[i][t]) {
      idx = t;
      x -= tree[i][t];
    }
    mask >>= 1;
  }
  return idx;
}

// Driver program to test above functions
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
      ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n, q; cin>>n>>q;
    N = n;
    string  a; cin>>a;

    for (size_t i = 0; i < n; i++) {
      Set(i+1, 1, (ll)(a[i]-'a'));
    }

    for (size_t i = 0; i < q; i++) {
      ll t; cin>>t;

      if(t == 1)
      {
        ll tmp; cin>>tmp; tmp--;
        char ch; cin>>ch;

        ll j;
        for (j = 0; j < n; j++) {
          if(tmp > 0)
          {
            if(get(tmp+1, j)!= get(tmp-1+1, j))
              break;
          }
          else
          {
            if(get(tmp+1, j) != 0)
              break;
          }
        }

        Set(tmp+1, -1, j);
        Set(tmp+1, 1, ch-'a');
      }
      else
      {
        ll a, b;cin>>a>>b; b--, a--;

        ll flag = 0;
        for (size_t i = 0; i < n; i++) {
          if(a > 0)
          {
            if( (get(b+1, i) - get(a-1+1, i)) % 2 == 1)
            {
              flag++;
            }
          }
          else
          {
            if( get(b+1, i) % 2 == 1)
            {
                flag++;
            }
          }
        }

        if(flag <= 1) cout << "yes\n";
        else cout<<"no\n";
      }
    }

    return 0;
}
