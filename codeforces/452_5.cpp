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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
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
const int MAX = 200009;
const int MOD = 1e9+7;

int a[MAX];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n;cin>>n;
    int s=0,cur=0,ff=0;
    set<pp > s1,s2;
    rep(i,n)cin>>a[i];

    rep(i,n)
    {
      if(i<n-1)
      {
        if(a[i]==a[i+1]&&ff==0)ff=1,cur++,s=i;
        else if(a[i]==a[i+1]&&ff==1)cur++;
        else if(a[i]!=a[i+1]&&ff==1)cur++,s1.insert(mp(-cur,s)),s2.insert(mp(s,cur)),cur=0,ff=0;
        else if(a[i]!=a[i+1]&&ff==0)cur++,s=i,s1.insert(mp(-cur,i)),s2.insert(mp(i,cur)),cur=0;
      }
      else
      {
        if(ff==1)cur++,s1.insert(mp(-cur,s)),s2.insert(mp(s,cur)),cur=0,ff=0;
        else if(ff==0)cur++,s=i,s1.insert(mp(-cur,i)),s2.insert(mp(i,cur)),cur=0;
      }
    }

    int step=0;
    while(!s1.empty())
    {
      step++;

      pp cur=*s1.begin();s1.erase(s1.begin());

      int tmp=cur.X;cur.X=cur.Y,cur.Y=-tmp;
      auto aa=lower_bound(all(s2),cur,compare()),bb=upper_bound(all(s2),cur);

      if(aa==s2.begin()||bb==s2.end()||aa==bb)continue;
      aa--;

      if(a[aa->X]==a[bb->X])
      {
        pp nw=mp(-aa->Y-bb->Y,aa->X);
        pp n1=mp(-aa->Y,aa->X),n2=mp(-bb->Y,bb->X);

        s1.erase(n1),s1.erase(n2);
        s1.insert(nw);

        s2.erase(lower_bound(all(s2),cur));
        s2.erase(upper_bound(all(s2),cur));

        pp z=nw;nw.X=z.Y,nw.Y=-z.X;
        s2.insert(nw);
      }
    }
    cout<<step<<endl;


    return 0;
}
