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
    return a * b / gcd(a, b);
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

const int MAX = 100009;
const int MOD = 1e9+7;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a[3][3] = {0}, cnt1 = 0, cnt2 = 0;

    rep(i, 3)
    {
      string b; cin>>b;
      rep(j, 3)
      {
        char c; c = b[j];// cout << c << ' ';
        if(c == 'X')
        {
          a[i][j] = 1; cnt1++;
        }
        else if(c == '0') {a[i][j] = 2; cnt2++;}
        else a[i][j] = 0;
      }
      // cout << end;
    }

    // rep(i, 3)
    // {
    //   rep(j, 3)
    //   {
    //     cout << a[i][j] << ' ';
    //   }
    //   cout << end;
    // }

    if( cnt1 - cnt2 > 1 || cnt2 > cnt1)
    {
      cout << "illegal\n";
      return 0;
    }

    ll win = 0, d = 0, f = 0, w[9]= {0};

    // cout << a[0][0] <<", "<< a[1][0]<< ", " << a[2][0] << end;

    if(a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][2] != 0) win++, w[1] = a[0][0], d++;
    if(a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][2] != 0) win++, w[2] = a[1][1], d++;
    if(a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][2] != 0) win++, w[3] = a[2][2], d++;
    if(a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] != 0) win++, w[4] = a[0][0], f++;
    if(a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] != 0) win++, w[5] = a[1][1], f++;
    if(a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] != 0) win++, w[6] = a[2][2], f++;

    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] != 0) win++, w[7] = a[0][0];
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] != 0) win++, w[8] = a[1][1];


    if(d > 1 && f > 1)
    {
      cout << "illegal\n";return 0;
    }
    else if(win > 0)
    {
      ll flag = 1, cur = -1;
      rep(i, 9)
      {
        if(w[i] != 0)
        {
          if(cur == -1) cur = w[i];
          else if(cur != w[i]) flag = 0;
        }
      }
      if(flag == 0)
      {
        cout << "illegal\n";return 0;
      }

      if(cur == 1 && cnt1 > cnt2)
      {   cout << "the first player won\n";
            return 0;
      }
      else if(cur == 2 && cnt1 == cnt2)
      {
          cout << "the second player won\n";
          return 0;
      }
      else
      {
        cout << "illegal\n";
        return 0;
      }
    }

    if(cnt1+cnt2 == 9)
    {
      cout << "draw\n";
      return 0;
    }

    if(cnt1 > cnt2)
    {
      cout << "second\n";
        return 0;
    }
    else
    {
      cout << "first\n";
      return 0;
    }

    return 0;
}
