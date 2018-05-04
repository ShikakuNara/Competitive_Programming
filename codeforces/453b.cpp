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

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
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

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 400009;
const int MOD = 1e9+7;

int fac[65]={0};
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int inv[1<<17]={0};
int dp[110][1<<17]={0},pre[110][1<<17]={0},cur[110][1<<17]={0};

void ini()
{
  repA(i,1,59)
  {
    rep(j,17)if(i%prime[j]==0)fac[i]+=1<<j;
    inv[fac[i]]=i;
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifdef LOCAL_TEST
  ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
  #endif

  ini();

  int n;cin>>n;
  int a[110];
  rep(i,n)cin>>a[i];

  rep(i,110)rep(j,1<<17)dp[i][j]=1e9;
  repA(i,1,59)if(dp[0][fac[i]]>Abs(a[0]-i))dp[0][fac[i]]=Abs(a[0]-i),cur[0][fac[i]]=i;


  repA(i,1,n-1)
  {
  	repA(k,1,59)
  	{
  		int x=(~fac[k])&((1<<17)-1);
  		for(int s=x; ;s=(s-1)&x)
  		{
  			if(dp[i-1][s]+Abs(a[i]-k)<dp[i][s|fac[k]])
  				dp[i][s|fac[k]]=dp[i-1][s]+Abs(a[i]-k),cur[i][s|fac[k]]=k,pre[i][s|fac[k]]=s;
        if(s==0)break;
  		}
  	}
  }

  int m=1e9,ind=-1;
  rep(i,1<<17)
  {
    if(dp[n-1][i]<m)m=dp[n-1][i],ind=i;
  }
  // cout<<dp[0][fac[6]]<<','<<ind<<endl;
  stack<int> stk;stk.push(ind);
  repD(i,n-1,1)ind=pre[i][ind],stk.push(ind);
  rep(i,n)
  {
  	int tmp=stk.top();stk.pop();
  	cout<<cur[i][tmp]<<' ';
  }cout<<endl;

    return 0;
}
