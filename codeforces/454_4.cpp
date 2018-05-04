#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

vi a[MAX];
deque<int> b[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,m;cin>>n>>m;
    rep(i,n)rep(j,m){int tmp;tmp=(i)*m+j+1;a[i].pb(tmp);}


    // rep(i,n)
    // {
    //   rep(j,m)cout<<a[i][j]<<' ';
    //   cout<<endl;
    // }
    // cout<<endl<<endl;

    if(n==1&&m==1)cout<<"YES\n1"<<endl;
    else if(n==1&&m==2)cout<<"NO\n"<<endl;
    else if(n==1&&m==3)cout<<"NO\n"<<endl;
    else if(n==3&&m==1)cout<<"NO\n"<<endl;
    else if(n==2&&m==1)cout<<"NO\n"<<endl;
    else if(n==2&&m==2)cout<<"NO\n"<<endl;
    else if(n==2&&m==3)cout<<"NO\n"<<endl;
    else if(n==3&&m==2)cout<<"NO\n"<<endl;
    else if(n==3&&m==3)
    {
      cout<<"YES\n";
      cout<<a[0][0]<<' '<<a[2][2]<<' '<<a[1][1]<<' '<<endl
          <<a[1][2]<<' '<<a[0][1]<<' '<<a[2][0]<<' '<<endl
          <<a[2][1]<<' '<<a[1][0]<<' '<<a[0][2]<<' '<<endl;
    }
    else if(m==1)
    {
      b[0].pb(a[1][0]),
      b[0].pb(a[3][0]),
      b[0].pb(a[0][0]),
      b[0].pb(a[2][0]);

      cout<<"YES\n";
      repA(j,4,n-1)
      {
        if(j%2==1)b[0].pb(a[j][0]);
        if(j%2==0)b[0].push_front(a[j][0]);
      }

      rep(i,n)cout<<b[0][i]<<endl;
    }
    else if(m==2)
    {
      b[0].pb(a[1][0]),
      b[0].pb(a[3][0]),
      b[0].pb(a[0][0]),
      b[0].pb(a[2][0]);

      repA(j,5,n-1)b[0].pb(a[j][0]),j++;
      repA(j,4,n-1)b[0].pb(a[j][0]),j++;

      b[1].pb(a[2][1]),
      b[1].pb(a[0][1]),
      b[1].pb(a[3][1]),
      b[1].pb(a[1][1]);

      repA(j,4,n-1)b[1].pb(a[j][1]),j++;
      repA(j,5,n-1)b[1].pb(a[j][1]),j++;

      cout<<"YES\n";
      rep(i,n)cout<<b[0][i]<<' '<<b[1][i]<<endl;
    }
    else if(m==3)
    {

      b[0].pb(a[1][0]),
      b[0].pb(a[3][0]),
      b[0].pb(a[0][0]),
      b[0].pb(a[2][0]);

      repA(j,5,n-1)b[0].pb(a[j][0]),j++;
      repA(j,4,n-1)b[0].pb(a[j][0]),j++;

      b[1].pb(a[2][1]),
      b[1].pb(a[0][1]),
      b[1].pb(a[3][1]),
      b[1].pb(a[1][1]);

      repA(j,4,n-1)b[1].pb(a[j][1]),j++;
      repA(j,5,n-1)b[1].pb(a[j][1]),j++;

      b[2].pb(a[1][2]),
      b[2].pb(a[3][2]),
      b[2].pb(a[0][2]),
      b[2].pb(a[2][2]);

      repA(j,5,n-1)b[2].pb(a[j][2]),j++;
      repA(j,4,n-1)b[2].pb(a[j][2]),j++;

      cout<<"YES\n";
      rep(i,n)cout<<b[0][i]<<' '<<b[1][i]<<' '<<b[2][i]<<endl;
    }
    else
    {
      rep(i,n)
      {
        if(i%2==0)
        b[i].pb(a[i][1]),
        b[i].pb(a[i][3]),
        b[i].pb(a[i][0]),
        b[i].pb(a[i][2]);
        else
        b[i].pb(a[i][2]),
        b[i].pb(a[i][0]),
        b[i].pb(a[i][3]),
        b[i].pb(a[i][1]);
        if(i%2==0)
        {
          repA(j,5,m-1)b[i].pb(a[i][j]),j++;
          repA(j,4,m-1)b[i].pb(a[i][j]),j++;
        }
        if(i%2==1)
        {
          repA(j,4,m-1)b[i].pb(a[i][j]),j++;
          repA(j,5,m-1)b[i].pb(a[i][j]),j++;
        }

      }

      cout<<"YES\n";
      rep(i,n)
      {
        rep(j,m)cout<<b[i][j]<<' ';
        cout<<endl;
      }
    }



    return 0;
}
