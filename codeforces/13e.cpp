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

int a[MAX],p[MAX],n[MAX];
int sq=500;
int N;

void update(int i,int v){
  a[i]=v;
  repD(j,i,sq*(i/sq)){
    if(j+a[j]>=N)n[j]=j,p[j]=1;
    else if(j+a[j]>=sq*(i/sq)+sq)n[j]=j,p[j]=1;
    else n[j]=n[j+a[j]],p[j]=1+p[j+a[j]];
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int m;cin>>N>>m;
    rep(i,N)cin>>a[i];

    repD(i,N-1,0)update(i,a[i]);

    rep(i,m){
      int t;cin>>t;
      if(!t){
        int i,b;cin>>i>>b;i--;
        update(i,b);
      }
      else{
        int i,ni,ans=0;cin>>i;i--;
        while(i<N){
          ans+=p[i],ni=i,i=n[i]+a[n[i]];
        }
        ans+=p[i];
        cout<<n[ni]+1<<' '<<ans<<endl;
      }
    }

    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
