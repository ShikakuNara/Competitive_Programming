#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef pair<double, pp> ppp;
typedef vector<pp > vpp;

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
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 400009;
const int MOD = 1e9+7;

ll dx[]={-1,1,2,1,-1,-2},
   dy[]={-2,-2,0,2,2,0};
int n;

bool chk(pp a)
{
  if(a.X<0||a.X>=n||a.Y<0||a.Y>=n)return false;
  return true;
}
string stp(pp a, pp p)
{
  pp tmp=mp(a.X-p.X,a.Y-p.Y);
  rep(i,6)if(tmp==mp(dx[i],dy[i]))
  {
    if(i==0)return "UL";//LL
    else if(i==1)return "UR";//LR
    else if(i==2)return "R";
    else if(i==3)return "LR";//UR
    else if(i==4)return "LL";//UL
    else if(i==5)return "L";
  }
  return "VOID";
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n;
    ll a,b,x,y;cin>>b>>a>>y>>x;
    pp dst=mp(x,y);

    priority_queue<ppp > pq;bool vis[210][210]={0};
    ppp p[210][210];//parent


    pp cur=mp(a,b); ppp tmp=mp(0,cur);pq.push(tmp);

    rep(i,210)rep(j,210)p[i][j]=mp(1e7,mp(-1LL,-1LL));
    p[a][b]=mp(0,mp(-1LL,-1LL));

    ll ff=0;
    while(!pq.empty())
    {
      ppp u=pq.top();pq.pop();
      ll d=-u.X;pp cur=u.Y;

      if(vis[cur.X][cur.Y])continue;
      else vis[cur.X][cur.Y]=true;

      if(cur==dst){ff=1,cout<<d<<endl;break;}

      rep(i,6)
      {
        pp tmp=mp(cur.X+dx[i],cur.Y+dy[i]);

        if(!vis[tmp.X][tmp.Y]&&chk(tmp))
        {
          pq.push(mp(-d-1-0.1*(8-i),tmp));
          if(d+1+0.1*(8-i)<p[tmp.X][tmp.Y].X)p[tmp.X][tmp.Y]=mp(d+1+0.1*(8-i),cur);
        }
      }
    }

    if(!ff)cout<<"Impossible\n";
    else
    {
      stack<string> stk;
      for(;p[dst.X][dst.Y].Y!=mp(-1LL,-1LL);dst=p[dst.X][dst.Y].Y)
      {
        stk.push(stp(dst,p[dst.X][dst.Y].Y));
      }

      while(!stk.empty())cout<<stk.top()<<' ',stk.pop();
    }



    return 0;
}
