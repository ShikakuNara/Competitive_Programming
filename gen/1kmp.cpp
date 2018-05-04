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
const int MAX = 400009;
const int MOD = 1e9+7;

//generates reset table for key
vi pi(const string& s) {
  vi b(sz(s));
  repA(i,1,sz(s)-1)
  {
    int g=b[i-1];
    while (g && s[i] != s[g]) g = b[g-1];
    b[i] = g+(s[i]==s[g]);
  }
  return b;
}
//could make a general reset table, for different texts
vi match(const string& s, const string& pat)
{
  vi p = pi(pat+'\0'+s), res;
  repA(i,sz(p)-sz(s),sz(p)-1)
  if(p[i]==sz(pat))res.push_back(i-2*sz(pat));
  return res;
}

int b[MAX]={0};
string p,t;
void kmpPreprocess()
{
  int i=0,j=-1;b[0]=-1;
  while(i<sz(p))
  {
    while(j>=0&&p[i]!=p[j])j=b[j];
    i++,j++;
    b[i]=j;
  }
}

//general search with a backup table
void kmpSearch() {
  int i=0,j=0;

  while(i<sz(t))
  {
    cout<<j<<','<<i<<endl;
    while(j>=0&&t[i]!=p[j])j=b[j],cout<<j<<','<<i<<"ww\n";
    i++,j++;
    if(j==sz(p))
    {
      printf("p is found at index %d in t\n", i - j);
      j=b[j];
    }
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    p="a";
    t="aaaaa";
    kmpPreprocess();
    rep(i,sz(p)+1)cout<<b[i]<<' ';cout<<endl;
    rep(i,sz(p)+1)cout<<i%10<<' ';cout<<endl;
    kmpSearch();



    return 0;
}