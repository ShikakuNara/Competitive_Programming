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


#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 1509;
const int MOD = 1e9+7;
ll p1=31,p2=37,e1[MAX],e2[MAX],k,a,b,c,cnt[MAX]={0};
string s,g;
std::set<pp > st;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    e1[0]=p1,e2[0]=p2;
    repA(i,1,MAX-1)e1[i]=e1[i-1]*p1,e2[i]=e2[i-1]*p2;
    cin>>s>>g>>k;

    rep(i,sz(s))if(g[s[i]-'a']=='0')cnt[i]=1;else cnt[i]=0;

    repA(i,0,sz(s)-1)
    {
      c=0,a=0,b=0;
      repA(j,i,sz(s)-1)
      {
        c+=cnt[j];
        if(c>k)break;
        a+=(s[j]-'a'+1)*e1[j-i+1],b+=(s[j]-'a'+1)*e2[j-i+1];
        st.insert(mp(a,b));
      }
    }
    cout<<st.size()<<end;


    // fin();
    return 0;
}
