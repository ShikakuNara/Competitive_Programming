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
#define PI 3.14159265

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

const int MAX = 200009;
const int MOD = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin>>n;

    ll key[MAX], loc[MAX];
    for (ll i = 0; i < n; i++) {
      cin >> key[i];
    }
    for (ll i = 0; i < n; i++) {
      cin >> loc[i];
    }

    sort(key, key+n); sort(loc, loc+n);

    ll cnt = 0;
    ll i,j;


    for (i = 0, j = 0; i < n && j < n; ) {

      if(key[i] < loc[j])
      {
        cnt++; i++;
      }
      else if(key[i] == loc[j])
      {
        i++; j++;
      }
      else if(key[i] > loc[j])
      {
        j++; cnt--;
        if(cnt < 0)
        {
          cout << "Sad\n";
          return 0;
        }
      }

    }

    if( i == n && j != n)
    {
      while(j != n)
      {
        j++; cnt--;
      }

      if(cnt < 0)
      {
        cout << "Sad\n"; return 0;
      }
    }

    cout << "Happy\n";

    return 0;
}
