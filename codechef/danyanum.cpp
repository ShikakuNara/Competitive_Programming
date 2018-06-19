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
clock_t ptime=clock();void fin(){ptime=clock()-ptime;cerr<<(float)(ptime)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 1<<18+9;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int n,m,k,s=512;
vpp q[512];
int cnt[MAX],dp[MAX];

void sos(){
  rep(i,(1<<k))dp[i]=cnt[i];
  rep(i,k)rep(j,(1<<k)){
    if((j&(1<<i))==0)dp[j]+=dp[j|(1<<i)];
  }
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");ptime=clock();
    #endif

    cin>>n>>m>>k;
    rep(i,n){
      int x;cin>>x;cnt[x]++;
    }

    rep(i,m){
      int t,x;cin>>t>>x;
      q[i/s].pb(mp(t,x));
    }

    repA(i,0,(m-1)/s){
      sos();
      vi add,era;
      trav(it,q[i]){
        int t=it.fst,x=it.snd;

        if(t==1)cnt[x]++,add.pb(x);
        else if(t==2)cnt[x]--,era.pb(x);
        else{
          int ans=0;
          repD(i,k-1,0){
            ans|=(1<<i);
            int l=dp[ans];
            trav(it,add)if((ans&it)==ans)l++;
            trav(it,era)if((ans&it)==ans)l--;
            if(l<x)ans^=(1<<i);
          }
          cout<<ans<<'\n';
        }
      }
    }

    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
