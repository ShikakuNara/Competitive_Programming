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
clock_t time_p=clock();void fin(){time_p=clock()-time_p;cerr<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX],skip[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");time_p=clock();
    #endif

    ll n,k;cin>>n>>k;
    rep(i,n)cin>>a[i];

    repA(i,0,n-2)if(a[i+1]==1){
      int c=1,j=i;i++;
      while(i<n&&a[i]==1)i++,c++;
      skip[j]=c;
      while(j<i)skip[j++]=--c;
      i--;
    }

    ll ans=0;
    rep(i,n){
      ll sum=0,p=1;
      repA(j,i,n-1){
        if(p*a[j]>1e9)break;

        sum+=a[j],p*=a[j];
        if(p==k*sum)ans++;

        if(skip[j]){
          if(p%k==0&&p<=(sum+skip[j])*k&&p>sum*k)ans++;

          sum+=skip[j];
          j+=skip[j];
        }
      }
    }

    cout<<ans<<endl;




    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
