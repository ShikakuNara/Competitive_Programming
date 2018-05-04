#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
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

ll npwtw (ll n)
{
  n--;
  n|= n >> 1;
  n|= n >> 2;
  n|= n >> 4;
  n|= n >> 8;
  n|= n >> 16;
  n|= n >> 32;
  n++;
  return n;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    string s; cin >> s;

    ll a[s.size()];

    for (size_t i = 0; i < s.size(); i++) {
      a[i] = s[i] - '0';
      /* code */
    }

    int flag = 0;

    for (size_t i = 0; i < s.size(); i++) {
      if( a[i] == 0 && flag == 0)
        flag = 1;
    }

    if(flag == 0)
    {
      for (size_t i = 0; i < s.size() - 1; i++) {
        cout << 1;
        /* code */
      }
    }
    else
    {
      flag = 0;
      for (size_t i = 0; i < s.size(); i++) {
        if(a[i] == 1)
          cout << a[i];
        else if( a[i] == 0 && flag == 0)
          flag = 1;
        else
          cout << a[i];
      }
    }

    return 0;
}
