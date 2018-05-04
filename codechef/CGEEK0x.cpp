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

    ll t; cin >> t;
    ll a[2000] = {0};

    for (size_t j = 0; j < t; j++) {

      ll key, depth, al; cin >> depth >> key >> al;

      for (size_t i = 0; i < al; i++) {
        cin >> a[i];
      }

      sort(a, a+al);
      // for (size_t i = 0; i < al; i++) {
      //   cout << a[i] << " ";
      //   /* code */
      // }cout << end;

      ll ans = 0;
      for (ll i = 0; i < depth; i++) {
        for (ll j = 0; j < key ; j++) {
          if( al-1-j -key*i >= 0)
          {
                      ans += a[al-1-j - key*i] * (i+1);
          }
        }
      }

      cout << ans << end;

    }



    return 0;
}
