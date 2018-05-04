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
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX],k[MAX];
vll v;

int binary(ll i){
  ll l=0,r=sz(v)-1;
  while(l<r){
    ll m=(l+r+1)/2;
    if(v[m]<=i)l=m;
    else r=m-1;
  }
  return l;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,q;cin>>n>>q;
    rep(i,n)cin>>a[i];
    rep(i,q)cin>>k[i];

    v.pb(a[0]);
    repA(i,1,n-1)v.pb(a[i]+v[sz(v)-1]);

    // trav(it,v)cout<<it<<',';cout<<endl;

    vll ans;ll cnt=0;
    rep(i,q){
      // cout<<k[i]+cnt<<endl;
      auto t=binary(k[i]+cnt);
      // cout<<t<<","<<k[i]+cnt<<endl;
      if(t==sz(v)-1)cnt=0,ans.pb(n);
      else if(t==0&&v[0]>k[i]+cnt)ans.pb(n),cnt+=k[i];
      else if(t==0&&v[0]<=k[i]+cnt)ans.pb(n-1),cnt+=k[i];
      else{
        ans.pb(sz(v)-t-1);
        cnt+=k[i];
      }

    }

    trav(it,ans)cout<<it<<endl;





    return 0;
}
