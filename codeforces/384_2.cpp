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

    int n; ll k;
    cin >> n >> k;


    int flag = 0;
    while(true)
    {

      if(k == 1)
      {
        cout << 1;
        break;
      }

      if(ispwtw(k)== 1)
      {
        ll tw = 1;
        for (size_t i = 1; i < 50; i++) {
          tw *= 2;
          if(k == tw)
          {
            cout << i + 1 << "\n";
            break;
          }
          /* code */
        }

        break;
      }
      else
      {
        k = k - npwtw(k)/2;
      }

    }
    //
    // cout.close();
    // cin.close();

    return 0;
}
