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


    string s; cin >> s;

    ll k; cin >> k;

    ll len = -1, flag = 0;
    for (ll i = s.size()/2; flag == 0 && i >= 0; i--) {

      for (ll j = 0; flag == 0 && j < s.size() - i; j++) {

        string b(s, j, i);
        string e(s, j+i, i);

        if(b.compare(e) == 0)
        {
          flag = 1;
          len = 2*i;
        }
      }
    }

    ll ans;

    if(k >= s.size())
    {
      ans = k + s.size() - (k + s.size()) % 2 ;
    }
    else
    {
      for (ll i = (s.size()-k)/2; i >= 0; i--) {
        string e(s, s.size() - i, i);
        string b(s, s.size() - 2*i - k, i);

        if(b.compare(e) == 0)
        {
          ans = 2*(i+k);
          break;
        }
      }
    }

    cout << max(ans, len) << end;

    return 0;
}
