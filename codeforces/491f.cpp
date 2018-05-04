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

const int MAX = 300009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll p[MAX],f[MAX],mu[MAX];
vll pr;

void pre()
{
    repA(i,2,MAX-1)if(!p[i]){
      pr.pb(i);
      for(int j=2*i;j<MAX;j+=i)p[j]=1;
    }
    repA(i,1,MAX-1)f[i]=1;
    trav(it,pr){
      for(int j=it;j<MAX;j+=it)f[j]*=(it+1);
    }
    rep(i,MAX)f[i]-=1;
    // repA(i,2,MAX-1)f[i]+=f[i-1];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();
    repA(i,1,10)cout<<f[i]<<',';cout<<endl;
    int n,k;cin>>n>>k;

    // while(k!=0){
    //   int ii=lower_bound(t+1,t+n,k)-t;
    //   cout<<t[ii]<<','<<k<<endl;
    //   k-=t[ii];
    // }
    cout<<endl;



    return 0;
}
