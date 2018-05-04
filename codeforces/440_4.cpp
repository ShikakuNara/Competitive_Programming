#include <bits/stdc++.h>

#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
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

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define PI 3.14159265

const int MAX = 100009;

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}
ll x[5010][5010];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin >> n;

    fill(x);

    for (ll i = 0; i < n; i++) {
      cout << "? " << 0 << " " << i << endl;
      fflush(stdout);
      cin >> x[0][i];
      if(x[0][i] == -1)
      {exit(0);}
    }


    for (ll i = 1; i < n; i++) {
      cout << "? " << i << " " << 0 << endl;
      fflush(stdout);

      cin >> x[i][0];
      if(x[i][0] == -1)
      {exit(0);}
    }

    ll nsol = 0, sol[5010] = {0};

    for (ll i = 1; i < n; i++) {
      for (ll j = 1; j < n; j++) {
        x[i][j] = x[i][0] ^ x[0][j] ^ x[0][0];
      }
    }

    // for (ll i = 0; i < n; i++) {
    //   for (ll j = 0; j < n; j++) {
    //     x[i][j] = (n-i-1)^(n-j-1);
    //   }
    // }

    // for (size_t i = 0; i < n; i++) {
    //   for (size_t j = 0; j <  n; j++) {
    //     cout << x[i][j] << " ";
    //     /* code */
    //   }cout << end;
    //   /* code */
    // }

    ll tmp[5010] = {0}, tt[5010] = {0}, tinv[5010] = {0};
    for (ll i = 0; i < n; i++) {
      ll flag = 0, cnt = 0;
      fill(tmp);

      for (ll j = 0; flag == 0 && j < n; j++) {
        if(x[j][i] < n && x[j][i] >= 0)
        { if(tmp[x[j][i]] == 0)
          {
            cnt++; tmp[x[j][i]] = 1;
          }
        }
        else
        {
          flag = -1;
        }
      }

      if(cnt == n && flag == 0)
      {
        ll fg = 1;
        for (ll j = 0; j < n; j++) {
          tt[j] = x[j][i];
          tinv[tt[j]] = j;
        }

        for (ll j = 0; j < n; j++) {
            if(x[j][0] != (tt[j]^tinv[0]))
            {
              fg = -1;
            }
        }
        for (ll j = 0; j < n; j++) {
            if(x[0][j] != (tt[0]^tinv[j]))
            {
              fg = -1;
            }
        }

        if(fg == 1)
        {
          nsol++;
          if(nsol == 1)
          {
            for (ll j = 0; j < n; j++) {
              sol[j] = x[j][i];
            }
          }
        }
      }
    }

    cout << "!" << endl;
    fflush(stdout);
    cout << nsol << endl;
    fflush(stdout);
    for (ll i = 0; i < n; i++) {
      cout << sol[i];
      if(i != n-1) cout << " ";
    }

    cout << endl;
    fflush(stdout);


    return 0;
}
