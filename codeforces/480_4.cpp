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

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[5009];
vll sq;
map<ll ,ll> mp;
int ans[5009],found[5009];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll tmp=2;
    while(tmp<10009){
      sq.pb(tmp*tmp);
      tmp++;
    }

    ll n;cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)repD(j,sz(sq)-1,0)while(a[i]%sq[j]==0&&a[i]!=0)a[i]/=sq[j];
    int t=1;
    rep(i,n)if(mp.find(a[i])==mp.end())mp[a[i]]=t++;
    rep(i,n)a[i]=mp[a[i]];

    int zero=mp[0];

    rep(i,n){
      ll cnt=0;fill(found);

      repA(j,i,n-1)
        if(!found[a[j]]&&a[j]!=zero)found[a[j]]=1,ans[++cnt]++;
        else if(!found[a[j]])found[a[j]]=1,ans[cnt]++;
        else ans[cnt]++;
    }

    ans[1]+=ans[0];
    repA(i,1,n)cout<<ans[i]<<' ';

    // fin();

    return 0;
}
