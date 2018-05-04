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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll a[25] = {0};

    rep(i, 24)
    {
      cin >> a[i+1];
    }


    if(a[1]==a[2] && a[2]==a[3]  && a[3]==a[4] && a[9]==a[10] && a[10]==a[11]  && a[11]==a[12])
    {
        if(a[5] == a[6] && a[5] == a[15] && a[5] == a[16])
        {
          if(a[17] == a[18] && a[17] == a[7] && a[17] == a[8])
          {
            if(a[21] == a[22] && a[22] == a[19] && a[22] == a[20])
            {
              if(a[13] == a[14] && a[13] == a[23] && a[13] == a[24])
              {
                cout << "YES\n"; return 0;
              }
            }
          }
        }
        else if(a[5] == a[6] && a[5] == a[19] && a[5] == a[20])
        {
            if(a[13] == a[14] && a[13] == a[7] && a[13] == a[8])
            {
              if(a[21] == a[22] && a[22] == a[15] && a[22] == a[16])
              {
                if(a[17] == a[18] && a[17] == a[23] && a[17] == a[24])
                {
                  cout << "YES\n"; return 0;
                }
              }
            }
    }
  }


    if(a[13]==a[14] && a[13]==a[15] && a[13]==a[16]  && a[17]==a[18] && a[18]==a[19] && a[19]==a[20])
    {
        if(a[5] == a[7] && a[5] == a[10] && a[5] == a[12])
        {
          if(a[1] == a[3] && a[1] == a[6] && a[1] == a[8])
          {
            if(a[22] == a[24] && a[22] == a[2] && a[22] == a[4])
            {
              if(a[9] == a[11] && a[9] == a[21] && a[9] == a[23])
              {
                cout << "YES\n"; return 0;
              }
            }
          }
        }
        else if(a[5] == a[7] && a[5] == a[2] && a[5] == a[4])
        {
          if(a[1] == a[3] && a[1] == a[21] && a[1] == a[23])
          {
            if(a[22] == a[24] && a[22] == a[10] && a[22] == a[12])
            {
              if(a[9] == a[11] && a[9] == a[6] && a[9] == a[8])
              {
                cout << "YES\n"; return 0;
              }
            }
          }
        }
    }

    if(a[5]==a[6] && a[6]==a[7]  && a[7]==a[8] && a[21]==a[22] && a[22]==a[23]  && a[23]==a[24])
    {
        if(a[14] == a[16] && a[14] == a[11] && a[16] == a[12])
        {
          if(a[9] == a[10] && a[9] == a[18] && a[9] == a[20])
          {
            if(a[17] == a[19] && a[17] == a[1] && a[17] == a[2])
            {
              if(a[3] == a[4] && a[3] == a[13] && a[3] == a[15])
              {
                cout << "YES\n"; return 0;
              }
            }
          }
        }
        else if(a[14] == a[16] && a[14] == a[1] && a[16] == a[2])
        {
          if(a[9] == a[10] && a[9] == a[13] && a[9] == a[15])
          {
            if(a[17] == a[19] && a[17] == a[11] && a[17] == a[12])
            {
              if(a[3] == a[4] && a[3] == a[18] && a[3] == a[20])
              {
                cout << "YES\n"; return 0;
              }
            }
          }
        }
    }

    cout << "NO\n";

    return 0;
}
