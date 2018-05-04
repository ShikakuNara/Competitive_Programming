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
const long double PI=3.141592653589793238462643383;
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
const int MAX=1009;
const int MOD=1e9+7;

int msb(int n)
{
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    // n|=n>>32;
    n=n+1;
    return(n>>1);
}

bool adj[MAX][MAX]={0};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n;cin>>n;

    int tmp=msb(n),k=0,t=1;
    for(;t<tmp;t*=2,k++);

    if(k==0)
    {
      cout<<"2\nNY\nYN\n";return 0;
    }
	
    adj[1][3]=adj[1][4]=adj[3][1]=adj[4][1]=1;
    repA(i,1,k)
    {
      if(i!=k)
      {
        adj[3*i][2+3*i]=adj[3*i+1][2+3*i]=1;
          adj[3*i+2][3*i]=adj[3*i+2][3*i+1]=1;
        adj[3*i+2][3+3*i]=adj[3*i+2][4+3*i]=1;
          adj[3*i+3][2+3*i]=adj[3*i+4][2+3*i]=1;
      }
      else
      {
        adj[3*i][2]=adj[3*i+1][2]=1;
          adj[2][3*i]=adj[2][3*i+1]=1;
      }
    }
	int u=3*k+2;
  
	repA(i,0,k-1)if(n&(1<<i))
	{
		//connect 2.u.u+1....u+2*k-2*i-1.1
		if(i!=0)
		{
		  repA(j,1,2*k-2*i-1-1)
		  {
			  if(j==1)adj[2][u]=adj[u][u+1]=adj[u][2]=adj[u+1][u]=1;
			  else
			  {
				adj[u][u+1]=adj[u+1][u]=1;
			  }
			u++;
		  }
		  if(k==i+1)adj[u][2]=adj[2][u]=1;
		  adj[u][2+3*i]=adj[2+3*i][u]=1;u++;
		}
		else
		{
		  repA(j,1,2*k-1-1)
		  {
			if(j==1)adj[2][u]=adj[u][u+1]=adj[u][2]=adj[u+1][u]=1;
			else
			{
				adj[u][u+1]=adj[u+1][u]=1;
			}
			u++;
		  }
		  adj[u][1]=1,adj[1][u]=1;u++;
		}
    }

	cout<<u-1<<endl;
	repA(i,1,u-1)
	{
		//if(i==1){repA(j,1,u-1)cout<<j%10;cout<<endl;}
		repA(j,1,u-1)
		{
			if(adj[i][j]==1)cout<<'Y';
			else cout<<'N';
		}
		cout<<endl;
	}


    return 0;
}
