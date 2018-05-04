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


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    ll n;
    cin >> n;

    vll a;

    for (size_t i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      a.pb(tmp);
    }


    for (size_t i = 0; i < (n + 1) / 2; i+=2) {

      ll tmp = a[i];
      a[i] = a[n-i-1];
      a[n-i-1] = tmp;
      /* code */
    }

    for (size_t i = 0; i < n; i++) {
      cout << a[i] << ' ';
    }

    // cout.close();
    // cin.close();

    return 0;
}
