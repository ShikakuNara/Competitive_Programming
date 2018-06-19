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

ll Abs(ll i){
  if(i>0)return i;
  return -i;
}

ll a[MAX],vis[MAX];
ll n,k,l;
ll binary(ll i){
  ll l=0,r=n*k-1;
  while(l<r){
    ll m=(l+r+1)/2;
    if(a[m]<=i)l=m;
    else if(a[m]>i)r=m-1;
  }
  return l;
}

vll v;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>n>>k>>l;
    rep(i,n*k)cin>>a[i];
    sort(a,a+n*k);
    // rep(i,n*k)cout<<a[i]<<',';cout<<endl;

    int cnt=1,i=0;vis[0]=1;

    ll g=binary(a[0]+l);i=g;

    while(cnt<n&&g>0)vis[g]=1,g--,cnt++;

    rep(i,n*k)if(vis[i])v.pb(i);
    // rep(i,n*k)cout<<v[i]<<',';cout<<endl;

    if(sz(v)!=n){cout<<"0";return 0;}

    int j=0;ll ans=0;
    rep(i,n){
      int cnt=0;
      if(j<v[i])vis[v[i]]=0,v[i]=j,vis[j]=1;
      if(k==1)j++;
      while(cnt<k-1){
        if(vis[j]==0)cnt++,vis[j]=2;
        j++;
      }
    }

    rep(i,n)ans+=a[v[i]];//cout<<a[v[i]]<<':'<<v[i]<<',';cout<<endl;

    cout<<ans<<endl;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
