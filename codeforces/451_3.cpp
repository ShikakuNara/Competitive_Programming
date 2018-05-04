#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef vector <string> vs;
typedef pair<ll, ll> pp;
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

bool compare(string &s1,string &s2)
{
  // if(s1.size()!=s2.size())
    return s1.size() < s2.size();
  // else return s1.compare(s2);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n;cin>>n;
    map<string,int> mp; int k=0;
    map<int,string> inv;
    vs num[20];
    rep(i,n)
    {
      string s;cin>>s;
      if(mp.find(s)==mp.end())mp[s]=k,inv[k]=s,k++;
      int t;cin>>t;
      int c=mp[s];
      rep(i,t)
      {
        string tmp;cin>>tmp;
        num[c].pb(tmp);
      }
    }
    rep(i,k)sort(all(num[i]),compare);

    cout<<k<<endl;
    rep(i,k)
    {
      cout<<inv[i]<<' ';
      rep(j,sz(num[i]))
      {
        string u=num[i][j];
        repA(jj,j+1,sz(num[i])-1)
        {
          string v=num[i][jj];
          string tmp=v.substr(sz(v)-sz(u),sz(u));
          if(tmp==u){num[i].erase(num[i].begin()+j),j--;break;}
        }
      }
      cout<<sz(num[i])<<' ';
      rep(j,sz(num[i]))
      {
        cout<<num[i][j]<<' ';
      }
      cout<<endl;
    }

    return 0;
}
