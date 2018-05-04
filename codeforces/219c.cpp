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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n, k; cin >> n >> k;
    string s; cin >> s;


    if(k == 2)
    {
      string a(s), b(s);
      for (size_t i = 0; i < n; i++) {
        if(i % 2 == 0)
        {
          a[i] = 'A'; b[i] = 'B';
        }
        else
        {
          b[i] = 'A'; a[i] = 'B';
        }
      }

      ll counta = 0, countb = 0;
      for (size_t i = 0; i < n; i++) {
        if(s[i] != a[i])
        {
          counta++;
        }
        if(s[i] != b[i])
        {
          countb++;
        }
      }

      cout << min(counta, countb) << end;
      if(min(counta, countb) == counta)
      {
        cout << a << end;
      }
      else
      {
        cout << b << end;
      }
      return 0;
    }


    ll count = 0;
    for (size_t i = 1; i < n; i++) {
      if( s[i] == s[i-1])
      {
        if(s[i-1] != 'A' && s[i+1] != 'A')
        {
          count++;
          s[i] = 'A';
        }
        else if(s[i-1] != 'B' && s[i+1] != 'B')
        {
          count++;
          s[i] = 'B';
        }
        else if(s[i-1] != 'C' && s[i+1] != 'C')
        {
          count++;
          s[i] = 'C';
        }
      }
    }

    cout << count << end << s << end;


    return 0;
}
