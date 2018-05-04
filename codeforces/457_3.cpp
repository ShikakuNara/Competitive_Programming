#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

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
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef pair<int, pp > ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

bool prime[MAX];
void SieveOfEratosthenes(ll n)
{
    memset(prime, true, sizeof(prime));

    for (ll p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

vppp ans;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    SieveOfEratosthenes(MAX-1);
    // cout<<prime[7]<<endl;
    vi pr;
    repA(i,2,MAX-1)if(prime[i])pr.pb(i);

    // (prime, prime+sizeof(prime)/sizeof(int));

    int n,m;cin>>n>>m;
    auto i=upper_bound(all(pr),n);
    cout<<2<<' ';
    if(n==2)cout<<2<<endl;
    else cout<<*i<<endl;

    ans.pb(mp(1,mp(n,2)));

    int t=*i-2,mm=10;
    repA(i,2,n-1){
      ans.pb(mp(1,mp(i,Ceil(t,n-i))));
      t-=Ceil(t,n-i);
    }

    m-=n-1;
    repA(i,2,n){
      repA(j,i+1,n){
      if(m==0)break;
      ans.pb(mp(i,mp(j,mm)));m--;
    }

      if(m==0)break;
    }

    trav(i,ans)cout<<i.X<<' '<<i.Y.X<<' '<<i.Y.Y<<endl;

    return 0;
}
