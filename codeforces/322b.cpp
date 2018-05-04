#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  #pragma comment(linker, "/stack:16777216")
#endif
#ifndef LOCAL_TEST
  #include <bits/stdc++.h>
#endif

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
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'


const ll MAX = 1000009;
const ll MOD = 1e9 + 7;
const ll factRange = MAX;
#define _  %  MOD
#define __ %= MOD


// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll abs(ll a, ll b)
{
  if( a > b)
    return a-b;

  return b-a;
}

ll powe(ll a, ll b)
{
  ll ans = 1;

  for (size_t i = 0; i < b; i++) {
    ans *= a;
    /* code */
  }
  return ans;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a, b, c, counta = 0, countb = 0, count = 0;
    cin >> a >> b >> c;

    if( a > 3)
    {
      if( a % 3 == 0)
      {
        count += a/3 - 1;
        a = 3;
      }
      else
      {
        count += a/3;
        a = a % 3;
      }
    }
    if( b > 3)
    {
      if( b % 3 == 0)
      {
        count += b/3 - 1;
        b = 3;
      }
      else
      {
        count += b/3;
        b = b % 3;
      }
    }
    if( c > 3)
    {
      if( c % 3 == 0)
      {
        count += c/3 - 1;
        c = 3;
      }
      else
      {
        count += c/3;
        c = c % 3;
      }
    }

    counta += count; countb += count;

    countb += a/3 + b/3 + c/3;
    countb += min(min((a+90)%3, (b+90)%3), (c+90)%3);

    counta += min(min(a, b), c);

    ll d = min(min(a, b), c);

    a -= d;
    b -= d;
    c -= d;

    counta += a/3 + b/3 + c/3;

    cout << max(counta, countb) << end;




    return 0;
}
