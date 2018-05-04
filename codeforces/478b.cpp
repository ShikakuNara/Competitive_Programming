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
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'


// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a[110][110], c[10010] = {0};

    for (size_t i = 0; i < 110; i++) {
      for (size_t j = 0; j < 110; j++) {
        a[i][j] = 0;
        /* code */
      }
      /* code */
    }

    ll n, m, d; cin >> n >> m >> d;

    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        cin >> a[i][j];
        c[n*i+j] = a[i][j];
      }
    }

    sort(c, c+n*m);

    ll cur = (a[0][0] + 5*d) % d;

    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if((a[i][j] + 5*d) % d != cur)
        {
          cout << -1 << end;
          return 0;
        }
        a[i][j] /= d;

      }
    }


    ll ind = c[(m*n)/2] / d, ans = 0;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if(a[i][j] - ind > 0)
          ans += a[i][j] - ind;
        else
          ans -= a[i][j] - ind;
      }
    }

    cout << ans << end;



    return 0;
}
