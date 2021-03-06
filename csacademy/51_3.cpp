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

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll abs(ll a, ll b)
{
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

    ll t; cin >> t;

    for (size_t i = 0; i < t; i++) {
      ll a, b, c;
      cin >> a >> b >> c;

      ll x[3] = {a, b, c};

      sort(x, x+3);
      c = x[0];
      b = x[1];
      a = x[2];

      if(a-b > c)
      {
        cout << -1 << '\n';
      }
      else if(a - c > b)
      {
        cout << -1 << '\n';
      }
      else
      {
        ll y = (a+b-c)/2;

        if((a + b - c) % 2 != 0)
        {
          cout << -1 << '\n';
        }
        else
        {
          cout << 0 << " " << 0 << " "
               << a << " " << 0 << " "
               << y << " " << b - y << '\n';
        }


      }

    }


    return 0;
}
