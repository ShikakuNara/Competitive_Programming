#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define rall(c)  (c).rbegin(),(c).rend()
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
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 1009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll m[MAX],s[MAX],p[MAX];vll mi;
int r,b,c;

int solve(ll mm){
  mi.clear();

  rep(i,c)if(p[i]>mm)mi.pb(0); else mi.pb(min(m[i],max((mm-p[i])/s[i],0LL)));
  sort(rall(mi));

  // cout<<mm<<"->";
  // rep(i,r)cout<<mi[i]<<'.';cout<<endl;

  int rt=r,bt=b;
  rep(i,r){
    bt-=mi[i];rt--;
    if(rt==0||bt<=0)break;
  }
  // if(bt<=0)cout<<"ysy\n";
  if(bt<=0)return 1;
  return 0;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){

      cin>>r>>b>>c;
      rep(i,c)cin>>m[i]>>s[i]>>p[i];

      // rep(i,c)cout<<p[i]<<'.';cout<<endl;

      ll l=0,r=2e18,m;
      while(l<r){

        m=(l+r)/2;
        // cout<<l<<','<<r<<":"<<m;

        if(solve(m)==0)l=m+1;//cout<<"a";
        else r=m;
        // cout<<endl;
      }
      // solve(5);

      cout<<"Case #"<<aa+1<<": "<<l<<"\n";
    }




    return 0;
}
