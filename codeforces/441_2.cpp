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

    ll n,k,m;cin>>n>>k>>m;

    vll a; vll modm[MAX];

    for (size_t i = 0; i < n; i++) {
      ll tmp; cin >> tmp; a.pb(tmp);

      modm[(tmp+5*m) % m].pb(tmp);
    }

    int flag = 0;
    for (size_t i = 0; flag == 0 && i < m; i++) {
      if(modm[i].size() >= k)
      {
        cout << "Yes\n";
        for (size_t j = 0; j < k; j++) {
          cout << modm[i][j] << " ";
        }

        flag=1;
        return 0;
      }
      /* code */
    }


    cout << "No\n";





    return 0;
}
