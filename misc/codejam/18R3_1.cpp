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
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

set<char> c[20];
std::vector<char> d[20];
ll N=1,n,l;
map<string, ll> mp;
vi v;ll cnt=0;
ll ff=0; string ans;

void func(int i){
  cnt++;
  // rep(i,l)cout<<v[i]<<',';cout<<endl;
  if(cnt==N+1000)return;
  if(ff)return;


  string tmp="";
  rep(i,l){
    tmp=tmp+d[i][v[i]];
  }
  if(mp.find(tmp)==mp.end()){ff=1,ans=tmp;return;}

  // cout<<tmp<<endl;

  int gg=0;
  // cout<<i<<','<<sz(c[i])<<endl;
  while(i<l&&gg==0){
    if(v[i]<sz(c[i])-1)v[i]++,gg=1;//cout<<"hh\n";
    else{v[i]=0;i++;}
  }
  // cout<<endl;
  // cout<<tmp<<endl;
  // rep(i,l)cout<<v[i]<<',';cout<<endl;
  // printf("heee\n");
  func(0);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    rep(i,20)v.pb(0);

    int t;cin>>t;
    rep(aa,t){
      mp.clear();N=1;
      ff=0,ans="";cnt=0;
      rep(i,20)v[i]=0;
      rep(i,20)c[i].clear();
      rep(i,20)d[i].clear();


      cin>>n>>l;
      // printf("here\n" );

      rep(i,n){
        string s;cin>>s;mp[s]=1;
        rep(j,l)if(c[j].find(s[j])==c[j].end())c[j].insert(s[j]),d[j].pb(s[j]);
      }

      // printf("here2\n" );

      N=1;
      rep(i,l)N*=sz(c[i]);
      // rep(i,l)printf("%d,",sz(c[i]) );;cout<<endl;

      // printf("here3\n" );
      // printf("%d\n",N);

      func(0);
      if(ff)cout<<"Case #"<<aa+1<<": "<<ans<<endl;
      else cout<<"Case #"<<aa+1<<": "<<"-"<<endl;
    }




    return 0;
}
