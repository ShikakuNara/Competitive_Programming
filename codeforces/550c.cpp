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

    ll mul[126], siz[126];
    vll ind[126];

    for (size_t i = 0; i < 1000; i+=8) {
      mul[i/8] = i;


      if(mul[i/8] < 10)
      {
        siz[i/8] = 0;
      }
      else if( mul[i/8] < 100)
      {
          siz[i/8] = 1;
      }
      else
      {
          siz[i/8] = 2;
      }
    }

    string s; cin >> s;
    ll n[101];
    for (size_t i = 0; i < s.size(); i++) {
      n[i] = s[i] - '0';
      if(n[i] == 0)
      {
        cout << "YES\n0";
        return 0;
      }
    }


    for (size_t i = 0; i < s.size(); i++) {
      for (size_t j = 1; j < 125; j++) {

        if(n[i] == mul[j]/((ll)(powe(10, siz[j]))) - 10 * (mul[j]/((ll)(powe(10, siz[j]+1)))) )
        {
        //  mul[j] /= 10;
         siz[j]--;
       }

        if(siz[j] == -1)
        {
          cout << "YES\n";
          cout << j*8 << end;
          return 0;
        }
      }
    }

    cout << "NO\n";


    return 0;
}
