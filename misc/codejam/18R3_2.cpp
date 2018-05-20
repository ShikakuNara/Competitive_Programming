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
// #define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int sol[300];
int tot[300];

bool comp(int i, int j){
  return tot[i]>tot[j];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    // ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll t;cin>>t;
    rep(aa,t){
      rep(i,200)tot[i]=0;
      rep(i,200)sol[i]=0;
      int n;cin>>n;


      rep(i,n){
        int d;cin>>d;

        if(d==0)cout<<-1<<endl;
        else{
          int v[200];
          rep(i,d)cin>>v[i],tot[v[i]]++;
          // sort(v,v+d,comp);

          int ii=-1;
          rep(i,d){
            if(sol[v[i]])continue;
            if(ii==-1)ii=v[i];
            if(tot[ii]>tot[v[i]])ii=v[i];
          }
          cout<<ii<<endl;
          if(ii!=-1)sol[ii]=1;
        }
      }
    }
    return 0;
}
