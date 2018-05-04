#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    string x,y;cin>>x>>y;
    vi a,b;
    int ca[10]={0},cca[10]={0};vi aa;
    rep(i,sz(x))ca[x[i]-'0']++,aa.pb(x[i]-'0');
    rep(i,10)cca[i]=ca[i];
    rep(i,sz(y))y[i]-='0';

    repA(i,sz(y),sz(x)-1)b.pb(0);
    rep(i,sz(y))b.pb(y[i]);
    rep(i,sz(x))b.pb(x[i]-'0');

    sort(all(aa));

    if(sz(y)>sz(x)){repD(i,sz(x)-1,0)cout<<aa[i];return 0;}

    int ff=0,gg=-2;vi ans,ans2;

    while(gg<sz(x)){
      ans.clear();gg++;rep(i,10)ca[i]=cca[i];
      repA(i,0,sz(x)-1){

        if(ff==1)repD(j,9,0){
          if(ca[j]>0){ca[j]--,ans.pb(j);break;}
        }
        else{
          if(i>gg&&ca[b[i]]>0)ca[b[i]]--,ans.pb(b[i]);
          else repD(j,b[i]-1,0)if(ca[j]>0){
            ca[j]--,ans.pb(j);ff=1;
            break;
          }
        }

      }
    }

    gg=sz(b)+1,ff=0;
    while(gg<sz(x)){
      ans2.clear();gg--;rep(i,10)ca[i]=cca[i];
      repA(i,0,sz(x)-1){

        if(ff==1)repD(j,9,0){
          if(ca[j]>0){ca[j]--,ans2.pb(j);break;}
        }
        else{
          if(i<gg&&ca[b[i]]>0)ca[b[i]]--,ans2.pb(b[i]);
          else repD(j,b[i]-1,0)if(ca[j]>0){
            ca[j]--,ans2.pb(j);ff=1;
            break;
          }
        }

      }
    }


    ll a1=0,a2=0;
    ll t=1;
    trav(i,ans)a1+=t*i,t*=10;
    t=1;
    trav(i,ans2)a2+=t*i,t*=10;
    if(a1<a2){trav(i,ans)cout<<i;cout<<endl;}
    else{trav(i,ans2)cout<<i;cout<<endl;}


    return 0;
}
