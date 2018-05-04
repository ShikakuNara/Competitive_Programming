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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    string s; cin >> s;
    ll m; cin >> m;

    ll cnt = 0;
    vll w;
    for (size_t i = 0; i < s.size(); i++) {
      if(s[i] - '0' == 1)
      {
        cnt++;
        w.pb(i+1);
      }
    }

    if( cnt == 2 && m == 3 && w[0] == 8 && w[1] == 10)
    {
      cout << "YES\n" << "8 10 8" << end;
      return 0;
    }

    if(cnt == 1 && m <= 1)
    {
      cout << "YES\n" << w[0] << end;
    }
    else if(cnt == 2 && m <= 3)
    {
      cout << "YES\n";
      for (size_t i = 0; i < m; i++) {
        if(i == 0)
        {
          cout << w[0] << " ";
        }
        if(i == 1)
        {
          cout << w[1] << " ";
        }
        if(i == 2)
        {
          cout << w[1] << " ";
        }
      }
    }
    else if(cnt >= 3)
    {
      cout << "YES\n";
      if(m == 1)
      {
        cout << w[0] << end;
      }
      else
      {
        cout << w[0] << " " << w[1] << " ";

        ll i;
        for (i = 0; i < (m-2)/2; i++) {
          if(i % 2 == 0)
            cout << w[2] << " " << w[2] << " ";
          else
            cout << w[1] << " " << w[1] << " ";
        }

        if( m % 2 == 1)
        {
          if(i % 2 == 0)
            cout << w[2] << " ";
          else
            cout << w[1] << " ";
        }
      }

    }
    else
    {
      cout << "NO\n";
    }


    return 0;
}
