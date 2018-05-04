#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

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
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll used[200009] = {0};
ll done[200009] = {0};
ll rep[200009] = {0};
ll n;

ll fused()
{
  for (size_t i = 1; i <= n; i++) {
    if(used[i] == 0)
      return i;
    /* code */
  }

  return -1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream cin("in.txt"); ofstream cout("out.txt");


    ll x, y, f, k; cin >> x >> y >> f >> k;

    ll a  = f, b = 2*(x-f), c = 2*f, d = x-f;


    if(y < c || y < b)
    {
      cout << -1; return 0;
    }

    ll cur = a; ll ref = 0;
    for (size_t i = 0; i < (k-1)/2; i++) {

      cur += b;
      if(y < cur)
      {
        cur = b;
        ref++;
      }

      cur += c;
      if(y < cur)
      {
        cur = c;
        ref++;
      }
    }

    if( k % 2 == 0)
    {
      cur += b;
      if(y < cur)
      {
        cur = b;
        ref++;
      }
      cur += a;
      if(y < cur)
      {

        cur = a;
        ref++;
      }
    }
    else{
      cur += d;
      if(y < cur)
      {
        cur = d;
        ref++;
      }
    }


    cout << ref << end;

    cout.close(); cin.close();
    return 0;
}
