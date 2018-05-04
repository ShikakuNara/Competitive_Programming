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

ll dp[1009][10009];
ll c[1009],cst[1009],x,b,w;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    fillA(dp);
    rep(i,1005)rep(j,10005)dp[i][j]=-inf*(ll)inf;

    ll n,s=0;cin>>n>>w>>b>>x;
    rep(i,n)cin>>c[i],s+=c[i];
    repA(i,1,n-1)c[i]+=c[i-1];
    rep(i,n)cin>>cst[i];

    int m=-1;
    rep(i,c[0]+1)if(w>=cst[0]*i)dp[0][i]=w-cst[0]*i;

    repA(i,0,n-1){
      repA(j,0,c[i])if(dp[i][j]>=0){
        repA(k,0,c[i+1]-c[i])dp[i+1][j+k]=max(dp[i+1][j+k],min(dp[i][j]+x,w+b*j)-k*cst[i+1]);
      }
    }

    repA(i,0,s){
      if(dp[n-1][i]>=0)m=i;
    }
    cout<<m<<endl;

    return 0;
}
