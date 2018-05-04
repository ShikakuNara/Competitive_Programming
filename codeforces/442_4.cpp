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
typedef queue < pp > qpp;

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

const int MAX = 1009;
const int MOD = 1e9+7;

// Functions
ll gcd(ll a, ll b){
    if (a == 0) return b;
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

bool a[MAX][MAX] = {0}; ll n, m, k;

bool inq[MAX][MAX] = {0}; ll d[MAX][MAX] = {0};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin>>n>>m>>k;

    rep(i, n)
    {
      rep(j, m)//input
      {
        char tmp; cin >> tmp;
        if(tmp == '.')
        {
          a[i][j] =0;
        }
        else
        {
          a[i][j] =1;
        }
      }
    }

    ll u, v, s, t;  cin>>u>>v>>s>>t;
    u--, v--,s--, t--;
    qpp que;

    que.push(mp(u, v));
    inq[u][v] = 1;

    if(a[u][v] == 1 || a[s][t] == 1)
    {
      cout << -1 << end;
    }
    else
    {
      while(!inq[s][t])
      {
        if(que.empty())
        {
          cout<< -1 <<end;
          return 0;
        }
        else
        {
          pp cell = que.front();
          que.pop();

          ll i = cell.X, j =cell.Y;

          repA(hh, 1, k)
          {
            if(i+hh >= n || a[i+hh][j]) break;

            if(!inq[i+ hh][j])
            {
              que.push(mp(i+hh, j));
              d[i+hh][j] =  d[i][j]+1;
              inq[i+hh][j] =1;
            }

          }
          repA(hh, 1, k)
          {

              if(j+hh >= m || a[i][j+hh]) break;

              if(!inq[i][j+hh])
              {
                que.push(mp(i, j+hh));
                d[i][j+hh] =  d[i][j]+1;
                inq[i][j+hh] = 1;
              }
          }
          repA(hh, 1, k)
          {
            if(i-hh < 0 || a[i-hh][j]) break;
            if(!inq[i-hh][j])
            {
              que.push(mp(i-hh, j));
              d[i-hh][j] =  d[i][j]+1;
              inq[i-hh][j] = 1;
            }

          }
          repA(hh, 1, k)
          {

            if(j-hh < 0 || a[i][j-hh]) break;

            if(!inq[i][j-hh])
            {
              que.push(mp(i, j-hh));
              d[i][j-hh] =  d[i][j]+1;

              inq[i][j-hh] = 1;
            }

          }
        }

      }

      cout << d[s][t] << end;
      // rep(i, n)
      // {
      //   rep(j, m)
      //   {
      //     cout<<d[i][j]<<" ";
      //   }cout<<end;
      // }
    }




    return 0;
}
