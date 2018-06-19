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

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll cnt[30];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      string a;ll k;cin>>a>>k;ll n=sz(a);

      ll ans=0;

      repA(i,0,n-1){
        fill(cnt);ll m=0,eq=0,dis=0;
        repA(j,1,n-i){
          if(cnt[a[i+j-1]-'a']==0)dis++;
          cnt[a[i+j-1]-'a']++;

          if(m<cnt[a[i+j-1]-'a'])m=cnt[a[i+j-1]-'a'],eq=1;
          else if(m==cnt[a[i+j-1]-'a'])eq++;

          if(dis>=k&&eq==dis)ans++;
        }
      }
      cout<<ans<<endl;
    }


    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
