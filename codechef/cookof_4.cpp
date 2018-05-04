#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef int T[3][3];
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <T > vT;
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



struct Tree {
  const T LOW[3][3]={{1,0,0},{0,1,0},{0,0,1}};

  T f(T a, T b){
    T res;
    rep(i,3)rep(j,3)res[i][j]=0;
    rep(i,3)res[0][0]+=a[0][i]*b[i][0];
    rep(i,3)res[0][1]+=a[0][i]*b[i][1];
    rep(i,3)res[0][2]+=a[0][i]*b[i][2];

    rep(i,3)res[1][0]+=a[1][i]*b[i][0];
    rep(i,3)res[1][1]+=a[1][i]*b[i][1];
    rep(i,3)res[1][2]+=a[1][i]*b[i][2];

    rep(i,3)res[2][0]+=a[0][i]*b[i][0];
    rep(i,3)res[2][1]+=a[0][i]*b[i][1];
    rep(i,3)res[2][2]+=a[0][i]*b[i][2];

    return res;
  }

  ll n;vT s;

  Tree(){}
  Tree(ll m,T def=LOW){init(m, def);}

  void init(ll m, T def) {
    n=1;while(n<m)n*=2;
    s.assign(n+m,def);
    s.resize(2*n,LOW);
    for(ll i=n;i-->1;)s[i]=f(s[i*2],s[i*2+1]);
  }

  void update(ll pos, T val) {
    pos+=n;
    // s[pos]=val;
    rep(i,3)rep(j,3)s[pos][i][j]=val[i][j];
    for(pos/=2;pos>0;pos/=2)s[pos]=f(s[pos*2],s[pos*2+1]);
  }

  T query(ll l, ll r) {return que(1,l,r,0,n);}

  T que(ll pos,ll l,ll r,ll lo,ll hi) {
    if(r<=lo||hi<=l) return LOW;
    if(l<=lo&&hi<=r) return s[pos];
    ll m=(lo+hi)/2;

    return f(que(2*pos,l,r,lo,m),que(2*pos+1,l,r,m,hi));
  }
};

int x[MAX],y[MAX],a[MAX];
T s[MAX];

T calc(int x,int y,int a)
{
  T ans;
  ans[0][0]=cos(a*PI/180.0);
  ans[1][1]=cos(a*PI/180.0);

  ans[1][0]=sin(a*PI/180.0);
  ans[0][1]=-sin(a*PI/180.0);

  ans[2][0]=0;
  ans[2][0]=0;
  ans[2][2]=1;

  ans[0][2]=-x*cos(a*PI/180.0)+y*sin(a*PI/180.0);
  ans[1][2]=-x*cos(a*PI/180.0)-y*sin(a*PI/180.0);

  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n){
      cin>>x[i]>>y[i]>>a[i];
      s[i]=calc(x[i],y[i],a[i]);
    }

    Tree t(n);
    rep(i,n)t.update(i,s[i]);


    int q;cin>>q;
    rep(i,q){
      int tt;cin>>tt;
      if(tt==1){
        ll x,y,l,r;cin>>x>>y>>l>>r;
        T ans=t.query(l,r);

        ll xn=ans[0][0]*x+ans[0][1]*y+ans[0][2];
        ll yn=ans[1][0]*x+ans[1][1]*y+ans[1][2];
        cout<<xn<<' '<<yn;
      }
      else{
        ll u,x,y,b;cin>>u>>x>>y>>b;

        T tmp=calc(x,y,b);
        t.update(u, tmp);
      }
    }

    return 0;
}
