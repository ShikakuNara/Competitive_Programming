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
typedef set <ll >  setl;
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

const int MAX = 100009;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n, m; cin >> n >> m;


    ll clr[MAX] = {0}, CMAX = 0;
    vll adj[MAX], tmp[MAX];
    setl adclr[MAX];

    for (size_t i = 0; i < n; i++) {
      cin >> clr[i];

      if(clr[i] > CMAX)
      {
        CMAX = clr[i];
      }

      tmp[clr[i]].pb(i);
    }


    for (size_t i = 0; i < m; i++) {
      ll a,b; cin >> a >> b;
      a--, b--;

      adj[a].pb(b);
      adj[b].pb(a);

      //new graph
      if(clr[a] != clr[b])
      {
        adclr[clr[a]].insert(clr[b]);
        adclr[clr[b]].insert(clr[a]);
      }
    }

    ll countMax = -1, cMax = -1;
    for (ll i = 0; i <= CMAX; i++) {
      if(!(tmp[i].empty()))
      {
        if(countMax < (ll)adclr[i].size() )
        {
          countMax = adclr[i].size();
          cMax = i;
        }
      }
    }

    cout << cMax << end;

    return 0;
}
