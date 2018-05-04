#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * (b / gcd(a, b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}

const int MAX = 400009;
const int MOD = 1e9+7;
const ll INF = 100000000000;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll t; cin>>t;

    rep(aaja, t)
    {
      ll n, a; cin>>n>>a;

      if(a >= n || a > 2  || n == 1 )
      {
        cout <<1<<' ';
        rep(i, n) cout << (char)( 'a'+ (i+5*a)%a);
        cout<<end;
      }
      else if( a == 1)
      {
        cout<<n<<' ';
        rep(i, n) cout << 'a';
        cout << end;
      }
      else
      {

        if(n > 8)
        {
          cout << 4 <<' ';
          rep(i, n)
          {

            if(i%6==0) cout << 'a';
            else if(i%6==1) cout << 'b';
            else if(i%6==2) cout << 'a';
            else if(i%6==3) cout << 'a';
            else if(i%6==4) cout << 'b';
            else if(i%6==5) cout << 'b';
          }
          cout << end;
        }
        else if(n == 2) cout << "2 ab\n";
        else if(n == 3) cout << "2 abb\n";
        else if(n == 4) cout << "2 aabb\n";
        else if(n == 5) cout << "3 aaabb\n";
        else if(n == 6) cout << "3 aaabbb\n";
        else if(n == 7) cout << "3 aaababb\n";
        else if(n == 8) cout << "3 aaababbb\n";
      }
    }




    return 0;
}
