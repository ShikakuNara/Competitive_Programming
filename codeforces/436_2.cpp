// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    ll n; cin >> n;
    string s; cin >> s;

    vll cap; int count[26] = {0}; int M = 0;

    for (size_t i = 0; i < n; i++) {

      if(s[i] <= 'z' && s[i] >= 'a')
      {
          count[s[i] - 'a'] = 1;
        }
      else
      {
        int sum = 0;
        for (size_t i = 0; i < 26; i++) {
          sum += count[i];
          /* code */
        }
        M = max(M, sum);


        fill(count);
      }
      /* code */
    }

    int sum = 0;
    for (size_t i = 0; i < 26; i++) {
      sum += count[i];
      /* code */
    }
    M = max(M, sum);

    cout << M << end;

    // cout.close(); cin.close();
    return 0;
}
