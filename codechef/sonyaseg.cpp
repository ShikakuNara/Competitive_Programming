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

const int MAX = 400009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll euclid(ll a, ll b, ll &x, ll &y) {
		if (b) { ll d = euclid(b, a % b, y, x);
					return y -= a/b * x, d; }
			return x = 1, y = 0, a;
}

ll modI(ll a, ll m=MOD){
    ll x,y;
    ll g=euclid(a,m,x,y);
    if (g!=1)cout<<"Inverse doesn't exist";
    else{
        ll res=(x%m+m)%m;
        return res;
    }
    return -1;
}

vll f,invf;

void pre(){
  f.resize(MAX+4),invf.resize(MAX+4);
  ll tmp=1;
  f[0]=1,invf[0]=1;
  repA(i,1,MAX-1)tmp=(tmp*i)%MOD,f[i]=tmp;

  invf[MAX-1]=modI(f[MAX-1]);
  repD(i,MAX-2,1)invf[i]=invf[i+1]*(i+1)%MOD;
}

ll C(ll n, ll r){
  if(r<0||r>n) return 0;
	return ((f[n]*invf[r])%MOD)*invf[n-r]%MOD;
}

pp a[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");time_p=clock();
    #endif

    pre();

    int t;cin>>t;
    rep(aa,t){
      int n,k;cin>>n>>k;
      rep(i,n)cin>>a[i].fst>>a[i].snd;
      sort(a,a+n);

      priority_queue<int > pq;

      ll ans=0;
      rep(i,n){
        while(!pq.empty()&&-pq.top()<a[i].fst)pq.pop();
        ans=(ans+C(sz(pq),k-1))%MOD;
        pq.push(-a[i].snd);
      }

      ans=(C(n,k)-ans+MOD)%MOD;
      cout<<ans<<'\n';
    }



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
