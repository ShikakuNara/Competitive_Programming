#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// using namespace __gnu_pbds;
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
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


pp a[30],b[30];
int n,m;

set<int> da[30],db[30];

int chk(pp a,pp b){
  if(a.fst==a.snd)return false;
  if(b.fst==b.snd)return false;
  if(a==b)return false;
  if(a.fst==b.snd&&a.snd==b.fst)return false;
  if(a.fst==b.snd||a.fst==b.fst)return a.fst;
  if(a.snd==b.snd||a.snd==b.fst)return a.snd;
  return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>n>>m;
    rep(i,n)cin>>a[i].fst>>a[i].snd;
    rep(i,m)cin>>b[i].fst>>b[i].snd;

    rep(i,n)rep(j,m)if(chk(b[j],a[i]))
        da[i].insert(chk(b[j],a[i])),db[j].insert(chk(b[j],a[i]));

    int ff=0,hh=0;int l=-1;
    rep(i,n)if(sz(da[i])==1){
      ff++;

      int t;
      trav(it,da[i])t=it;
      if(l!=-1&&t!=l)hh=1;
      l=t;
    }
    rep(i,m)if(sz(db[i])==1){
      ff++;int t;
      trav(it,db[i])t=it;
      if(l!=-1&&t!=l)hh=1;
      l=t;
    }


    int gg=0;
    rep(i,n)if(sz(da[i])>1)gg=1;
    rep(i,m)if(sz(db[i])>1)gg=1;

    if(gg)cout<<-1;
    else if(hh)cout<<0;
    else cout<<l;









    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
