// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

const ll llinf = -1000000000000000000;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
int lcm(int a, int b)
{
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
int ispwtw (ll n)
{
  return !(n&(n-1));
}


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    ll n, m; cin >> n >> m;

    vll a[n], b[m];

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        ll tmp; cin >> tmp;
        a[i].pb(tmp);

        if(i != 0 && a[i][j] < a[i-1][j])
        {
          b[j].pb(i);
        }
      }
    }


    ll c[n][m];

    for (size_t j = 0; j < m; j++) {
      ll h = 0;

      if(b[j].empty())
      {
        for (size_t i = 0; i < n; i++) {
          /* code */
          c[i][j] = n;
        }
      }
      else
      {
        for (size_t i = 0; i < n; i++) {
          if(i < b[j][h])
          {
            c[i][j] = b[j][h];
          }
          else
          {
            if( h+1 < b[j].size())
              { h++; i--; }
            else
              c[i][j] = n;
          }
        }
      }

    }

    ll d[n];

    for (size_t i = 0; i < n; i++) {
      ll max; int ff = 0;

      for (size_t j = 0; j < m; j++) {
        if(ff == 0)
        {
          max = c[i][j];
          ff = 1;
        }
        else
        {
          if(max < c[i][j])
            max = c[i][j];
        }
      }

      d[i] = max;
    }

    // for (size_t i = 0; i < n; i++) {
    //   for (size_t j = 0; j < m; j++) {
    //
    //     cout << c[i][j] << " ";
    //   }cout << endl;
    // }
    // cout << endl << endl;
    //
    // for (size_t i = 0; i < n; i++) {
    //   cout << d[i] << " ";
    //   /* code */
    // }cout << endl;

    //
    // for (size_t j = 0; j < m; j++) {
    //   for (size_t i = 0; i < b[j].size(); i++) {
    //     cout << b[j][i] << " ";
    //   }
    //   cout << endl;
    // }

    ll k; cin >> k;

    for (size_t i = 0; i < k; i++) {
      ll l, r; cin >> l >> r;
      l--; r--;

      int flag = 0;
      if(r < d[l])
        flag = 1;

      if(flag == 1) {
        cout << "Yes\n";
      }
      else {
        cout << "No\n";
      }
    }

    // cout.close();
    // cin.close();

    return 0;
}
