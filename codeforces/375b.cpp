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
struct Rcompare{bool operator()(int lhs,int rhs){return lhs>rhs;}};
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
const int MAX = 5009;
const int MOD = 1e9+7;

vi v[MAX];
int mat[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,m;
    cin>>n>>m;
    rep(i,n)
    {
      string s;cin>>s;
      rep(j,sz(s))
      {
        mat[i][j]=s[j]-'0';
      }
    }

    int ff=0,cur=0;
    rep(i,n)
    {
      cur=0,ff=0;
      rep(j,m)
      {
        if(mat[i][j]==1&&ff==0)ff=1,cur++;
        else if(mat[i][j]==1&&ff==1)cur++,mat[i][j]=cur;
        else if(mat[i][j]==0&&ff==1)cur=0;
      }
    }

    rep(i,n)rep(j,m)if(mat[i][j]!=0)v[j].pb(mat[i][j]);

    rep(i,m)sort(all(v[i]),Rcompare());

    int mm=0;
    rep(i,m)rep(j,sz(v[i]))
    {
      mm=max(mm,v[i][j]*(j+1));
    }
    cout<<mm<<endl;


    return 0;
}
