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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){
      int n;cin>>n;
      vi o,e;
      rep(i,n){
        int tmp;cin>>tmp;
        if(i%2)o.pb(tmp);
        else e.pb(tmp);
      }
      o.pb(inf),e.pb(inf);

      sort(all(o));sort(all(e));
      int okay=1,ii;

      rep(i,n){
        if(!okay)break;
        if(i%2){
          if(o[i/2]>e[i/2+1])okay=0,ii=i;
        }
        else{
          if(e[i/2]>o[i/2])okay=0,ii=i;
        }
      }

      cout<<"Case #"<<aa+1<<": ";
      if(!okay)cout<<ii<<endl;
      else cout<<"OK\n";
    }


    return 0;
}
