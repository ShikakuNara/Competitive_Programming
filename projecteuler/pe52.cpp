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
#define rep(i, n)     for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(ll i = a; i <= (n); ++i)
#define repD(i, a, n) for(ll i = a; i >= (n); --i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
#define X first
#define Y second
#define end '\n'

// Functions
struct Rcompare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X>rhs.X;
  }
}; struct compare{
  bool operator()(pp lhs,pp rhs){
    return lhs.X<rhs.X;
  }
};


ll gcd(ll a, ll b){
  if (a == 0) return b;
  return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * (b / gcd(a, b));
}
ll Abs(ll a){
  if( a > 0)
    return a;

  return -a;
}
double Abs(double a){
  if( a > 0)
    return a;

  return -a;
}
ll power(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=power(x,y/2);
  if(y%2==1)return tmp*tmp*x;
  return tmp*tmp;
}
const int MAX = 400009;
const int MOD = 1e9+7;

void dig(ll i,ll a[])
{
  while(i>0)a[i%10]++,i/=10;
}
int comp(ll a[],ll b[])
{
  rep(i,10)if(a[i]!=b[i])return 0; return 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    repA(i,1,1000000)
    {
      ll a1[10]={0},a2[10]={0},a3[10]={0},a4[10]={0},a5[10]={0},a6[10]={0};
      dig(i,a1),dig(2*i,a2),dig(3*i,a3),dig(4*i,a4),dig(5*i,a5),dig(6*i,a6);
      if(comp(a1,a2)&&comp(a1,a3)&&comp(a1,a4)&&comp(a1,a5)&&comp(a1,a6)){cout<<i;break;}
    }

    return 0;
}
