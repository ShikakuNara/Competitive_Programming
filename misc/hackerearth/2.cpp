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

    ll t; cin >> t;

    for (ll il = 0; il < t; il++) {

      string a, b; cin >> a>>b;

      if(a.size() > b.size())
      {
        cout << "NO\n"; continue;
      }

      char cur = -1;
      ll ccnt = 0, bcnt = 0, flag = 0;

      ll i, j = 0;
      for (i = 0, j = 0; flag == 0 && i < a.size() && j < b.size();) {
        cur = a[i];

        while( i < a.size() && a[i] == cur)
        {
          ccnt++;i++;
        }

        if(b[j] != cur)
        {

          // cout << cur <<", "<< j<< end;
          cout << "NO\n"; flag = 1;
        }

        while(j < b.size() && b[j] == cur)
        {
          bcnt++; j++;

        }

        if(bcnt < ccnt && flag == 0 )
        {
          cout << "NO\n"; flag = 1;
        }
      }

      if( i < a.size() && flag == 0)
      {
        cout << "NO\n"; continue;
      }
      if( j < b.size() && flag == 0)
      {
        cout << "NO\n"; continue;
      }

      if(flag == 0)
      cout << "YES\n";

    }




    return 0;
}
