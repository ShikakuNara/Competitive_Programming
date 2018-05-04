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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    ll n, k;
    cin >> n >> k;

    vll a;

    ll sum = 0, sum2 = 0, sum4 = 0, c=0;
    ll fr = n;
    ll tw = n * 2;
    for (size_t i = 0; i < k; i++) {
      ll tmp;
      cin >> tmp;

      sum4 += tmp/4;

      tmp = tmp - 4*(tmp/4);

      sum2 += tmp/2;

      tmp = tmp - 2*(tmp/2);

      c += tmp;

      a.pb(tmp);
    }


    //  cout << sum4 << " " << sum2 << " " << c;

    int fdone = 0, tdone = 0;
    if( fr - sum4 >= 0)
    {
      fr -= sum4; // fr =1
      sum4 =0;
    }
    else{
      sum4 -= fr;
      fr = 0;
      fdone = 1;

      if(tw >= 2*sum4)
      {
        tw -= sum4*2;
        sum4 = 0;
      }
      else{
        tw = 0;
        sum4 -= tw/2;
      }
    }

    ll frl = fr, frr = fr;

    if( tw - sum2 >= 0)
    {
      tw -= sum2;
      sum2 =0;
    }
    else{
      sum2 -= tw; // sum2 = 1
      tw = 0;
      tdone = 1;


      if( frl >= sum2)
      {
        frl -= sum2;
        sum2 = 0;
      }
      else{
        frl = 0;
        sum2 -= frl;
      }

    }


    if(tw >= c)
    {
      tw -= c;
      c = 0;

    }
    else
    {
      c -= tw;
      tw  = 0;

      if(frl >= c)
      {
        frl -= c;
        c = 0;
      }
      else{
        c -= frl;
        frl = 0;
      }

      if( c > 0 && frr >= c)
      {
        frr -= c;
        c = 0;
      }
      else
      {
        c -= frr;
        frr = 0;
      }
    }

    if( c == 0 && sum2 == 0 && sum4 == 0)
    {
      cout << "YES";
    }
    else
    {
      cout << "NO";
    }


    // cout.close();
    // cin.close();

    return 0;
}
