#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef pair<int, pp> ppp;
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
const int MAX = 60;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int a[MAX][MAX]={0};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int mp[]={0,1,2,3};

    int n,m;cin>>n>>m;
    pp st,ds;
    rep(i,n)rep(j,m){
      char tmp;cin>>tmp;
      if(tmp=='.')a[i][j]=0;
      else if(tmp=='#')a[i][j]=1;
      else if(tmp=='S')st=mp(i,j),a[i][j]=0;
      else if(tmp=='E')ds=mp(i,j);
    }

    vi cm;
    string s;cin>>s;
    rep(i,sz(s))cm.pb(s[i]-'0');

    int cnt=0;
    do{
      pp cur=st;

      int ff=0;
      rep(i,sz(cm)){
        if(cur.X<0||cur.X>=n||cur.Y<0||cur.Y>=m||a[cur.X][cur.Y]==1)break;
        if(cur==ds){cnt++,ff=1;break;}

        if(mp[cm[i]]==0)cur.X--;
        if(mp[cm[i]]==1)cur.X++;
        if(mp[cm[i]]==2)cur.Y--;
        if(mp[cm[i]]==3)cur.Y++;
      }
      if(ff==0&&cur==ds){cnt++;}

    }while(std::next_permutation(mp,mp+4));

    cout<<cnt<<endl;

    return 0;
}
