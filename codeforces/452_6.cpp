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

const int inf = 0;

struct Node {
  Node *l = 0, *r = 0;
  int lo,hi,mset = inf,madd = 0,val = -inf;
  Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of 􀀀inf
  Node(vi& v,int lo,int hi) : lo(lo), hi(hi)
  {
    if(lo+1<hi)
    {
      int mid=lo+(hi-lo)/2;
      l=new Node(v,lo,mid);r=new Node(v,mid,hi);
      val=l->val+r->val;
    }
    else val=v[lo];
  }
  int query(int L,int R)
  {
    if(R<=lo||hi<=L)return -inf;
    if(L<=lo&&hi<=R)return val;
    push();
    return l->query(L,R)+r->query(L,R);
  }
  void set(int L,int R,int x)
  {
    if(R<=lo||hi<=L)return;
    if(L<=lo&&hi<=R)mset=val=x,madd=0;
    else
    {
      push(),l->set(L,R,x),r->set(L,R,x);
      val=l->val+r->val;
    }
  }
  void add(int L,int R,int x)
  {
    if(R<=lo||hi<=L)return;
    if(L<=lo&&hi<=R)
    {
      if(mset!=inf)mset+=x;
      else madd+=x;

      val+=x;
    }
    else
    {
      push(),l->add(L,R,x),r->add(L,R,x);
      val=l->val+r->val;
    }
  }
  void push()
  {
    if(!l)
    {
      int mid=lo+(hi-lo)/2;
      l=new Node(lo,mid);r=new Node(mid,hi);
    }
    if(mset != inf)
      l->set(lo,hi,mset),r->set(lo,hi,mset),mset=inf;
    else if(madd)
      l->add(lo,hi,madd),r->add(lo,hi,madd),madd=0;
  }
};

vi v(MAX,1); Node* t=new Node(v,1,sz(v));
int binary(int i,int r)
{
  int l=1;
  while(l<r)
  {
    ll m=(l+r)>>1;
    if(t->query(1,m+1)<i)l=m+1;
    else r=m;
  }
  return l;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,m;cin>>n>>m;

    string a;cin>>a;
    set<int> s[75];

    rep(i,n)s[a[i]-'0'].insert(i+1);

    rep(i,m)
    {
      int l,r;cin>>l>>r;
      l=binary(l,n), r=binary(r,n);

      char c;cin>>c;c-='0';
      auto it=lower_bound(all(s[c]),l),it2=upper_bound(all(s[c]),r);
      auto it3=it;

      while(it!=s[c].end()&&it!=it2)t->set(*it,*it+1,0),it++;
      s[c].erase(it3,it2);
    }
    repA(i,1,n)if(t->query(i,i+1)==1)
    {
      repA(j,0,'z'-'0')if(s[j].find(i)!=s[j].end())cout<<(char)(j+'0');
    }


    return 0;
}
