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

const int MAX = 500009;
const int MOD = 1e9+7;
ll tree1[4*MAX] = {0}, pre1[4*MAX]={0}, post1[4*MAX]={0}, a[MAX]={0}, tree2[4*MAX] = {0}, pre2[4*MAX]={0}, post2[4*MAX]={0};
ll L, R;

ll C(ll x){
  return x*(x+1)/2;
}
void updateU(ll i, ll s, ll e, ll us, ll ue, ll val)
{
    if (s>e || s>ue || e<us)
        return ;

    if (s>=us && e<=ue)
    {
      if(val > R) tree1[i]=0,pre1[i]=0,post1[i]=0;
      else tree1[i]=1,pre1[i]=1,post1[i]=1;
      return;
    }

    ll m = (s+e)/2;
    updateU(i*2+1, s, m, us, ue, val); updateU(i*2+2, m+1, e, us, ue, val);

    ll postA=post1[i<<1|1],preA=pre1[i<<1|1],postB=post1[i*2 + 2],preB=pre1[i*2 + 2];
    tree1[i] = tree1[i*2+1] + tree1[i*2+2]+
              (preB+postA+1)*(preB+postA)/2 - (postA+1)*postA/2 - (preB+1)*preB/2;

    pre1[i] = preA;
    if(preA==m-s+1) pre1[i]+= preB;
    post1[i]=postB;
    if(preB==e-m) post1[i]+=postA;
}

void update(ll us, ll ue, ll diff, ll n)
{
   updateU(0, 0, n-1, us, ue, diff);
}

ll sum1 (ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return tree1[v];

  ll tm = (tl + tr) / 2;
  ll ans = sum1 (v*2+1, tl, tm, l, min(r,tm))+sum1 (v*2+2, tm+1, tr, max(l,tm+1), r);
  ll x = min( max((ll)0,min(r,tm)-l+1),    post1[2*v+1]);
  ll y = min( max((ll)0,r-max(l,tm+1)+1),pre1[2*v+2]);
  ans+=C(x+y) - C(x) - C(y);

  return ans;
}
ll getSumU(ll s, ll e, ll qs, ll qe, ll i)
{
    if (s>e || s>qe || e<qs) return 0;
    if (s>=qs && e<=qe)return tree1[i];

    ll m=(s+e)/2;

    ll ans=getSumU(s, m, qs, min(qe,m), 2*i+1)+getSumU(m+1, e, max(m+1,qs), qe, 2*i+2);

    ll postA=min(post1[2*i+1], max((ll)0,min(qe,m)-qs+1));
    ll preB=min(pre1[2*i+2], max((ll)0,qe-max(m+1,qs)+1));
    // if(preB!=0 && postA!=0)
      ans+=C(preB+postA) - C(postA) - C(preB);

    return ans;
}

ll getSum(ll qs, ll qe, ll n)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumU(0, n-1, qs, qe, 0);
}

void buildtreeU(ll arr[], ll s, ll e, ll i)
{
    if (s > e) return;
    if (s == e)
    {
        if(arr[s] > R) tree1[i]=pre1[i]=post1[i]=0;
        else tree1[i]=1,pre1[i]=1,post1[i]=1;
        return;
    }

    ll m = (s+e)/2;
    buildtreeU(arr, s, m, i*2+1); buildtreeU(arr, m+1, e, i*2+2);

    ll postA=post1[i<<1|1],preA=pre1[i<<1|1],postB=post1[i*2 + 2],preB=pre1[i*2 + 2];

    tree1[i] = tree1[i*2+1] + tree1[i*2+2];

    if(preB!=0 && postA!=0)
      tree1[i]+=C(preB+postA) - C(postA) - C(preB);

    pre1[i] = preA;
    if(preA == m-s+1) pre1[i]+= preB;
    post1[i]=postB;
    if(preB == e-m) post1[i]+=postA;
}

void buildtree(ll a[], ll  n)
{
  buildtreeU(a, 0, n-1, 0);
  return;
}

void updateU2(ll i, ll s, ll e, ll us, ll ue, ll val)
{
    if (s>e || s>ue || e<us)
        return ;

    if (s>=us && e<=ue)
    {
      if(val > L-1) tree2[i]=0,pre2[i]=0,post2[i]=0;
      else tree2[i]=1,pre2[i]=1,post2[i]=1;
      return;
    }

    ll m = (s+e)/2;
    updateU2(i*2+1, s, m, us, ue, val); updateU2(i*2+2, m+1, e, us, ue, val);

    ll postA=post2[i<<1|1],preA=pre2[i<<1|1],postB=post2[i*2 + 2],preB=pre2[i*2 + 2];
    tree2[i] = tree2[i*2+1] + tree2[i*2+2]+
              (preB+postA+1)*(preB+postA)/2 - (postA+1)*postA/2 - (preB+1)*preB/2;

    pre2[i] = preA;
    if(preA==m-s+1) pre2[i]+= preB;
    post2[i]=postB;
    if(preB==e-m) post2[i]+=postA;
}

void update2(ll us, ll ue, ll diff, ll n)
{
   updateU2(0, 0, n-1, us, ue, diff);
}


ll sum2 (ll v, ll tl, ll tr, ll l, ll r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return tree2[v];

  ll tm = (tl + tr) / 2;
  ll ans = sum2 (v*2+1, tl, tm, l, min(r,tm))+sum2 (v*2+2, tm+1, tr, max(l,tm+1), r);
  ll x = min(max((ll)0 ,min(r,tm)-l+1),post2[2*v+1]);
  ll y = min(max((ll)0 ,r-max(l,tm+1)+1),pre2[2*v+2]);
  ans+=C(x+y) - C(x) - C(y);

  return ans;
}
ll getSumU2(ll s, ll e, ll qs, ll qe, ll i)
{
    if (s>e || s>qe || e<qs) return 0;
    if (s>=qs && e<=qe)return tree2[i];

    ll m=(s+e)/2;

    ll ans1=getSumU2(s, m, qs, min(qe,m), 2*i+1),ans2=getSumU2(m+1, e, max(m+1,qs), qe, 2*i+2);
    ll ans=ans1+ans2;

    ll postA=min(post2[2*i+1], max((ll)0,min(qe,m)-qs+1));
    ll preB=min(pre2[2*i+2], max((ll)0,qe-max(m+1,qs)+1));
    // if(preB!=0&&postA!=0)
      ans+=C(preB+postA) - C(postA) - C(preB);
    return ans;
}
ll getSum2(ll qs, ll qe, ll n)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumU2(0, n-1, qs, qe, 0);
}

void buildtreeU2(ll arr[], ll s, ll e, ll i)
{
    if (s > e) return;
    if (s == e)
    {
        if(arr[s] > L-1) tree2[i]=pre2[i]=post2[i]=0;
        else tree2[i]=1,pre2[i]=1,post2[i]=1;
        return;
    }

    ll m = (s+e)/2;
    buildtreeU2(arr, s, m, i*2+1); buildtreeU2(arr, m+1, e, i*2+2);

    ll postA=post2[i<<1|1],preA=pre2[i<<1|1],postB=post2[i*2 + 2],preB=pre2[i*2 + 2];

    tree2[i] = tree2[i*2+1] + tree2[i*2+2];

    if(preB!=0 && postA!=0)
      tree2[i]+=C(preB+postA) - C(postA) - C(preB);

    pre2[i] = preA;
    if(preA == m-s+1) pre2[i]+= preB;
    post2[i]=postB;
    if(preB == e-m) post2[i]+=postA;
}

void buildtree2(ll a[], ll  n)
{
  buildtreeU2(a, 0, n-1, 0);
  return;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n,q;cin>>n>>q>>L>>R;

    buildtree(a, n);
    buildtree2(a, n);

    // rep(i,40)cout<<tree1[i]<<' '; cout<<end;
    // rep(i,40)cout<<pre1[i]<<' '; cout<<end;
    // rep(i,40)cout<<post1[i]<<' '; cout<<end;

    rep(i,q)
    {
      ll tmp,x,y;cin>>tmp>>x>>y; x--;
      if(tmp==1) update(x,x,y,n), update2(x,x,y,n);
      else
      {
        y--;
        // cout<<sum1(0,0,n-1,x,y)<<' '<<sum2(0,0,n-1,x,y)<<"\n";
        cout<<getSum(x,y,n)-getSum2(x,y,n)<<end;
      }
    }


    return 0;
}
