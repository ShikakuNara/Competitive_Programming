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
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'

const ll MOD = 1e9 + 7;
const ll MAX = 1e7 + 7;
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

ll d[MAX] = {0}, a[MAX] = {0};

void generate(ll i)
{
  if( i == MAX -  1)
  {
    return;
  }

  a[i] = (2*a[i-1])_;
  a[i] += 1*d[i-1];
  a[i] = a[i]_;
  d[i] = (6*a[i-2])_;
  d[i]  += (3*d[i-2])_;
  d[i] = d[i]_;

  return generate(i+1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    d[0] = 1; d[1] = 0; d[2] = 3;
    a[0] = 0; a[1] = 1; a[2] = 2;
    generate(3);


    ll n; cin >> n;
    cout << d[n] << end;


    return 0;
}