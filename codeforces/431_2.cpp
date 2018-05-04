// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

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

const ll INF = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 3;

#define end '\n'


// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int max = 1230;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    ll n; cin >> n;

    vll y;
    for (size_t i = 0; i < n; i++) {
      ll tmp; cin >> tmp;
      y.pb(tmp);
    }

    ll vis[n]; fill(vis);


    ll d, dd; ll count = 0; int flag = 0;

    for (size_t i = 1; i < n && flag == 0; i++) {
      flag = 1;
      fill(vis); vis[0] =1;

      d = y[i] - y[0];
      dd = i; ll xy = i;
      ll dpos = d, ddpos = dd;

      if(d < 0) dpos *= -1;
      if(dd < 0) ddpos *= -1;

      ll gc = gcd(dpos, ddpos);
      // cout << "gc = " << gc << end;

      // cout << i << ", " << d << ", " << dd << end;
      d = d/gc; dd =dd/ gc;
      // cout << d << ", " << dd << end;


      for (size_t i = xy; i < n; i += dd) {
        if( y[i] - y[0] == d*(i/dd))
        {
          vis[i] = 1; count++;
          // cout << ", " << i << "::";
        }
        /* code */
      }
      //  cout << end;

      int j = 0;
      //check if it fits
      for ( j = 0; j < n; j++) {
        if( vis[j] == 0)
          break;
      }
      if( j == n)
      {
        flag = 2; break;
      }
      vis[j] = 1;
      // cout << "j = " << j << end;

      for (size_t i = j+dd; i < n && flag == 1; i+= dd) {
        if( vis[i] == 0 )
        {
          // cout << i <<  " not visited" << end;
          if( y[i] - y[j] != d*((i-j)/dd))
            flag = 0;
          else{
            // cout << i << ":";
            vis[i] = 1;
          }
        }
      }
      // cout  << end << end;

      int c = 0;
      for (size_t i = 0; i < n; i++) {
        if(vis[i] == 1)
          c++;
      }
      // cout << "    " << c << end;
      if( c < n)
      {
        flag = 0;
      }

    }

    if(flag == 2)
    {
      cout << "No\n";
    }
    else if( flag == 1)
    {
      cout << "Yes\n";
    }
    else
    {
      flag = 1; fill(vis); vis[0] = 1; vis[1] = 1;
      d = y[2] - y[1];
      int j = 1;

      for (size_t i = j+1; i < n && flag == 1; i++) {
        if( vis[i] == 0 )
        {
          if( y[i] - y[j] != d*(i-j))
          {
            flag = 0;
          }
          else
          {
              vis[i] = 1;
          }
        }
      }

      if(flag == 1)
      {
        cout << "Yes\n";
      }
      else
      {
        cout << "No\n";
      }
    }


    // cout.close(); cin.close();
    return 0;
}
