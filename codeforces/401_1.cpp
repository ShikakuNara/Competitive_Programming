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
// void dfs(ll i)
// {
//
//     vis[i] = 1;
//
//     ll ss = a[i];
//
//     for (size_t j = 0; j < adj[i].size(); j++) {
//       if(vis[adj[i][j]] == 0)
//       {
//           dfs(adj[i][j]);
//           ss += sum[adj[i][j]];
//       }
//     }
//
//     sum[i] = ss;
//     return;
// }


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");


    ll n; cin >> n;
    int b; cin >> b;

    n = n - 6*(n/6);
    // n = n%6;

    //
    // int a[3];


    for (size_t i = n; i > 0; i--) {

      if(i % 2 == 0)
      {
        if( b == 0)
        {
          b = 0;
        }
        else if ( b == 1)
        {
          b = 2;
        }
        else{
          b = 1;
        }
      }
      else{
        if( b == 0)
        {
          b = 1;
        }
        else if( b == 1)
        {
          b = 0;
        }
        else{
          b = 2;
        }
      }
      /* code */
    }

    // switch (n) {
    //   case 1 : a[0] = 1; a[1] = 0; a[2] = 2; break;
    //   case 2 : a[0] = 1; a[1] = 2; a[2] = 0; break;
    //   case 3: a[0] = 2; a[1] = 1; a[2] = 0; break;
    //   case 4: a[0] = 2; a[1] = 0; a[2] = 1; break;
    //   case 5: a[0] = 0; a[1] = 2; a[2] = 1; break;
    //   case 6: a[0] = 0; a[1] = 1; a[2] = 2; break;
    // }

    cout << b;

    // cout.close();
    // cin.close();

    return 0;
}
