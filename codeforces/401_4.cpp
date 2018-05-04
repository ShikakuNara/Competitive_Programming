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

    ll n; cin >> n;

    std::vector<string> a;

    for (size_t i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;
      a.pb(tmp);
    }

    for (size_t i = n-1; i > 0; i--)
    {
      if( a[i].compare( a[i-1]) < 0)
      {
        int flag = 0;
        for (size_t j = 0; j < a[i-1].length() && j < a[i].length() && flag == 0; j++)
        {
          if(a[i-1][j] != a[i][j])
          {
            string c (a[i-1], 0, j);
            a[i-1] = c;
            flag = 1;
          }
        }

        if(a[i-1].length() > a[i].length())
        {
          string c (a[i-1], 0, a[i].length());
          a[i-1] = c;
        }

      }
    }

    for (size_t i = 0; i < n; i++) {
      cout << a[i] << endl;
      /* code */
    }

    // cout.close();
    // cin.close();

    return 0;
}
