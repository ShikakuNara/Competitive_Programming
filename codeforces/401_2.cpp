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

    int n; cin >> n;

    vll a, b;
    char c;

    for (size_t i = 0; i < n; i++) {
      cin >> c;
      int tmp = c-'0';
      a.pb(tmp);
    }
    for (size_t i = 0; i < n; i++) {
      cin >> c;
      int tmp = c-'0';
      b.pb(tmp);
    }

    int m = 0, M = 0;
    sort(a.begin(), a.begin()+n, greater<int>());
    sort(b.begin(), b.begin()+n, greater<int>());

    for (size_t i = 0; i < n; i++) {
      if(b[i] >= a[i])
      {
        // m++;
      }
      else
      {
        m++;
        if( i != n-1)
        {
        int tmp = b[i];
        b[i] = b[n-1];
        b[n-1] = tmp;
        sort(b.begin() + i + 1, b.begin() + n, greater<int>());
      }
      }
    }

    sort(a.begin(), a.begin()+n, greater<int>());
    sort(b.begin(), b.begin()+n, greater<int>());

    int j = 0;
    for (size_t i = 0; i < n && j < n; i++) {
      if( a[i] < b[j])
      {
        M++; j++;
      }
    }


    cout << m << endl << M;

    // cout.close();
    // cin.close();

    return 0;
}
