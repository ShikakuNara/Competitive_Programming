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

string si;

int solve(vi& t, vi& f){
  int res=1e9;

  trav(i,t)trav(j,f){
    if(i==j)continue;

    int ans=0;int a=i,b=j;
    if(a<b)ans++,swap(a,b);

    if(a==sz(si)-1&&sz(si)>1&&si[1]=='0'){
      int i=1;
      while(i<sz(si)&&si[i]=='0')ans++,i++;
    }
    ans+=a-1+b;
    res=min(res,ans);
  }

  return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>si;

    vi t,f,s,z;
    rep(i,sz(si))if(si[i]=='2')t.pb(sz(si)-i-1);
    rep(i,sz(si))if(si[i]=='5')f.pb(sz(si)-i-1);
    rep(i,sz(si))if(si[i]=='7')s.pb(sz(si)-i-1);
    rep(i,sz(si))if(si[i]=='0')z.pb(sz(si)-i-1);

    int ans=1e9;
    ans=min(ans,solve(t,f));
    ans=min(ans,solve3(f,z));
    ans=min(ans,solve(s,f));
    ans=min(ans,solve2(z,z));

    if(ans==1e9)ans=-1;
    cout<<ans;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
