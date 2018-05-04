#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

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
    ifstream cin("in.txt");
    ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
      int n, d;
      cin >> n >> d;

      vll a;
      for (size_t i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        a.pb(tmp);
      }

      ll sum = 0;
      for (size_t i = 0; i < n; i++) {
        sum += a[i];
      }

      if(sum % n != 0)
      {
        cout << -1 << "\n";
      }
      else
      {
        ll k = sum / n;
        int flag = 0;

        //check sum of all Ds are OK
        for (size_t i = 0; i < d; i++) {
          vll sumd(d, 0);
          for (size_t j = 0; j < n; j += d) {
            sumd[i] += a[j];
          }

          if(sumd[i] % k != 0)
            flag = 1;
        }

        //number of switches
        ll ans = 0;
        for (size_t i = 0; i < d; i++) {
          ll cur = 0, ss = 0;
          int flg = 0;

          for (size_t j = 0; j < n; j += d) {

            if(flg == 1)
            {
              ans += abs(cur);
              cur = 0;
              flg = 0;
            }

            ss += a[j] - k;

            if(ss == 0)
            {
              flg = 1;
            }.

            cur += a[j] * ( j / d + 1);
          }
        }

        cout << ans << "\n";
      }
    }

    cout.close();
    cin.close();

    return 0;
}
