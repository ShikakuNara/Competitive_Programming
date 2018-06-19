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

const int MAX = 400009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

char s[MAX],t[MAX],b[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int n;cin>>n;
    rep(i,n)cin>>t[i]>>s[i];
    rep(i,n){
      if(t[i]=='A')t[i]=1;
      else t[i]=-1;
    }
    int cnt=0,i=0,ff=0,sum=0,gg=0;
    ll mval=-inf,mpt=-1;

    while(i<n){
      sum+=t[i];
      if(ff==0&&s[i]=='L'){
        ff=1;
        mval=sum,mpt=i;
        if(sum>=0)gg=1;
        else gg=0;
      }
      else if(s[i]=='L'){
        b[mpt]=1,ff=0,i=mpt+1,sum=0;
        continue;
      }

      if(ff&&sum<=mval){
        if(sum>=0)mval=sum,mpt=i;
        else if(gg==0)mval=sum,mpt=i;
      }
      if(ff&&gg==0){
        if(sum>=0)gg=1,mval=sum,mpt=i;
      }


      i++;
    }
    b[n-1]=1;

    sum=0;
    rep(i,n){
      sum+=t[i];
      if(b[i])cnt+=(sum>=0),sum=0;
    }
    cout<<cnt<<endl;





    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
