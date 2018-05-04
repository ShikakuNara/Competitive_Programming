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
typedef pair<ll , pp> ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;
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
		  ifstream cin("in.txt");
      ofstream cout("out.txt");
    #endif

    ll n; cin >> n;

    vppp a; ll edge = 0;
    for (size_t i = 0; i < n; i++) {
      ll x, y; cin >> x >> y;
      edge += x;
      pp p = make_pair(y, i);
      ppp f = make_pair(x, p);

      a.pb(f);
    }

    cout << edge / 2 << '\n';

    edge /= 2;

    vppp b;
    
    for (size_t i = 0; i < a.size(); i++) {
      if(a[i].first == 1)
      {
          b.push_back(a[i]);
      }
    }

    while(edge != 0)
    {
      if(b.back().first == 0 || a[b.back().second.second].first == 0)
      {
        b.pop_back();
      }
      else if(b.back().first == 1)
      {
        ll flag = 0;
        cout << b.back().second.second << " " << b.back().second.first << '\n';

          a[b.back().second.first].first--;
          a[b.back().second.first].second.first ^=  b.back().second.second;

          if(a[b.back().second.first].first == 1)
          {ll tmp = b.back().second.first;
            b.pop_back();
            flag = 1;
            b.push_back(a[tmp]);
          }

        if(flag == 0)
          b.pop_back();
        edge--;
      }

    }

    return 0;
}
