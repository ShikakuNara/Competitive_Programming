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
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.begin(), v.end(), greater<auto>()))
#define fill(a)       (memset(a, 0, sizeof (a)))

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD

// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("in.txt");
    ofstream cout("out.txt");

    ll n; cin >> n;

    int sum = 0;
    for (size_t i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      if(tmp % 2 == 1)
      {
        sum = 1;
      }
      /* code */
    }

    if(sum == 1)
    {
      cout << "First\n";
    }
    else
    {
        cout << "Second\n";
    }

    cout.close();
    cin.close();

    return 0;
}
