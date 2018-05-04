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


const int p = 31;
const int p2= 37;
// ll hash(string s)
// {
//   ll hash=0,p_pow=1;
//   rep(i,sz(s))
//   {
//       hash+=(s[i]-'a'+1)*p_pow;
//       p_pow*=p;
//   }
//   return hash;
// }

vi pi(const string& s) {
  vi p(sz(s));
  repA(i,1,sz(s)-1)
  {
    int g=p[i-1];
    while(g&&s[i]!=s[g])g=p[g-1];
    p[i]=g+(s[i]==s[g]);
  }
  return p;
}
int match(const string& s, const string& pat)
{
  vi p = pi(pat + '\0' + s);int cnt=0;// res;
  repA(i,sz(p)-sz(s),sz(p)-1)
  if(p[i]==sz(pat))cnt++;//res.push_back(i - 2 * sz(pat));
  return cnt;
}

ll pre[MAX]={0},suf[MAX]={0};
ll pre2[MAX]={0},suf2[MAX]={0};
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    string s;cin>>s;
    ll hash=0,p_pow=p;
    rep(i,sz(s))
    {
        hash+=(s[i]-'a'+1)*p_pow;
        p_pow*=p;
        pre[i+1]=hash;
    }

    hash=0;
    repD(i,sz(s)-1,0)
    {
      hash*=p;
      hash+=(s[i]-'a'+1)*p;
      suf[sz(s)-i]=hash;
    }

    hash=0,p_pow=p2;
    rep(i,sz(s))
    {
        hash+=(s[i]-'a'+1)*p_pow;
        p_pow*=p2;
        pre2[i+1]=hash;
    }

    hash=0;
    repD(i,sz(s)-1,0)
    {
      hash*=p2;
      hash+=(s[i]-'a'+1)*p2;
      suf2[sz(s)-i]=hash;
    }

    vpp ans;
    repA(i,1,sz(s))
    {
      if(pre[i]==suf[i]&&pre2[i]==suf2[i])
      {
        int cnt=match(s,s.substr(0,i));
        ans.pb(mp(i,cnt));
      }
    }

    cout<<sz(ans)<<endl;
    rep(i,sz(ans))
    {
      cout<<ans[i].X<<' '<<ans[i].Y<<endl;
    }






    return 0;
}
