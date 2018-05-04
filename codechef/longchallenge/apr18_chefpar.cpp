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

const int MAX = 20009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX],b[MAX]; vll p;
set<ll> sp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    ll n,m,k;cin>>n>>m>>k;
    rep(i,n)cin>>a[i];
    ll maxp=-1;
    rep(i,m){ll t;cin>>t;p.pb(t),sp.insert(t);}

    rep(i,n){
      b[i]=a[i]+min(k,max(p[sz(p)-1]-a[i]-1,0LL));
      if(sp.find(b[i])!=sp.end())b[i]=max(b[i]-1,a[i]);
    }

    if(n*m<=1e7)rep(i,n){
      b[i]=a[i]+min(k,max(p[sz(p)-1]-a[i]-1,0LL));

      rep(i,m)if(b[i]%p[i]==0){
        if(b[i]-a[i]==k)b[i]--;
        else b[i]=b[i]++;
      }
      if(b[i]<a[i])b[i]=a[i];
    }

    rep(i,n)cout<<b[i]<<' ';cout<<endl;




    return 0;
}
