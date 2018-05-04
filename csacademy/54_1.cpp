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
// #define end '\n'

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

const int MAX = 110;
const int MOD = 1e9+7;

vpp AdjList[MAX];

list<ll> cyc; // we need list for fast insertion in the middle
void EulerTour(list<ll>::iterator i, ll u) {
  for (ll j = 0; j < (ll)AdjList[u].size(); j++) {
    pp v = AdjList[u][j];
    if (v.second) { // if this edge can still be used/not removed
      v.second = 0; // make the weight of this edge to be 0 (‘removed’)

      for (ll k = 0; k < (ll)AdjList[v.first].size(); k++) {
        pp uu = AdjList[v.first][k]; // remove bi-directional edge

        if (uu.first == u && uu.second) {
        uu.second = 0;
        break;
        }

      }

      cyc.insert(i, u);
      // EulerTour(cyc.insert(i, u), v.first);
    }
  }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    // inside int main()
    AdjList[0].pb(mp(1, 1));
    AdjList[1].pb(mp(2, 1));
    AdjList[2].pb(mp(3, 1));
    AdjList[3].pb(mp(1, 1));
    AdjList[1].pb(mp(5, 1));

    AdjList[1].pb(mp(0, 1));
    AdjList[2].pb(mp(1, 1));
    AdjList[3].pb(mp(2, 1));
    AdjList[1].pb(mp(3, 1));
    AdjList[5].pb(mp(1, 1));

    cyc.clear();
    EulerTour(cyc.begin(), 0); // cyc contains an Euler tour starting at A
    for (list<ll>::iterator it = cyc.begin(); it != cyc.end(); it++)
    cout << *it << '\n';

    return 0;
}
