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
typedef long double ld;
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

ld v[11],d[11],p[11],c[11];
ld t1[11],t2[11];

ld eps=0.000001;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      int n;ld s,y;cin>>n>>s>>y;
      y/=s;
      rep(i,n)cin>>v[i];
      rep(i,n)cin>>d[i];
      rep(i,n)cin>>p[i];
      rep(i,n)cin>>c[i];

      rep(i,n){
        if(d[i]==1){
          if(p[i]>0)t1[i]=-1;
          else if(p[i]<=0)t1[i]=(-p[i])/v[i]-y-eps;//cout<<"cd1\n";

          if(p[i]-c[i]>0)t2[i]=0;
          else t2[i]=(c[i]-p[i])/v[i]+eps;//cout<<(c[i]-p[i])/v[i]<<"ab1\n";
        }
        else{
          if(p[i]<0)t1[i]=-1;
          else if(p[i]>=0)t1[i]=(p[i])/v[i]-y-eps;//cout<<"cd2\n";

          if(p[i]+c[i]<0)t2[i]=0;
          else t2[i]=(c[i]+p[i])/v[i]+eps;//cout<<"ab2\n";
        }
      }

      // rep(i,n)cout<<t1[i]<<" ";cout<<endl;
      // rep(i,n)cout<<t2[i]<<" ";cout<<endl;

      ld ans=0;
      rep(i,n)if(t1[i]<ans&&t2[i]>=ans)ans=t2[i]+y; else ans+=y;

      cout<<ans<<endl;
    }




    return 0;
}
