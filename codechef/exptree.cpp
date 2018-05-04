// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef pair <int, int> pi;
typedef vector < pi > vpi;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;
typedef std::priority_queue < int > pqi;
typedef std::priority_queue < pi > pqp;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

typedef unsigned long long int ull;
#define M1 1000000007
#define M2 1000000009

// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
  // ifj

  if (a == 0)
      return b;
  return gcd(b%a, a);
}

ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

// // To compute x raised to power y under modulo m
// ll power(ll x, ull y, ull m);
//
// // Function to find modular inverse of a under modulo m
// // Assumption: m is prime
// ll modInverse(ll a, ll m)
// {
//     ll g = gcd(a, m);
//     if (g != 1)
//     {
//         cout << "Inverse doesn't exist";
//         return -1;
//     }
//     else
//     {
//         // If a and m are relatively prime, then modulo inverse
//         // is a^(m-2) mode m
//         return power(a, m-2, m);
//     }
// }
//
// // To compute x^y under modulo m
// ll power(ll x, ull y, ull m)
// {
//     if (y == 0)
//         return 1;
//     ll p = power(x, y/2, m) % m;
//     p = (p * p) % m;
//
//     return (y%2 == 0)? p : (x * p) % m;
// }


// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y);

// Function to find modulo inverse of a
ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        ll res = ((x+m)%m + m) % m;
        return res;
    }

    return -1;
}

// C function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
      ll n;
      cin >> n;


      ll nu, de;
      ll a = n, b = n-1, d = 2*n - 3;
      ll aa, bb, dd;
      ll ans1, ans2;

      if (n % 2 == 0) {
        a /= 2;
      }
      else {
         b /= 2;
      }

      if(n % 3 == 0) {
        a /= 3;
        d = 2 * (n/3) - 1;
      }

      //M1---------------------------------------------------
      aa = (a + M1) % M1;
      bb = (b + M1) % M1;
      dd = (d + M1) % M1;

      nu = aa*bb;
      nu = nu % M1;
      de = dd;

      ans1 = ( nu * modInverse(de, M1) + M1 ) % M1;

      //M2---------------------------------------------------
      aa = (a + M2) % M2;
      bb = (b + M2) % M2;
      dd = (d + M2) % M2;

      nu = aa*bb;
      nu = nu % M2;
      de = dd;

      ans2 = ( nu * modInverse(de, M2) + M2 ) % M2;

      cout << ans1 << " " << ans2 << '\n';
    }

    // cout.close();
    // cin.close();

    return 0;
}
