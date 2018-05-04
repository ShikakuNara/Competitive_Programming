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

const int MAX = 109;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int a[MAX][MAX];
int prey[MAX],prex[MAX][MAX],pre[MAX][MAX];
int r,c,v,h;
vi vy,vx;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int t;cin>>t;
    rep(aa,t){
      fill(a),fill(prey),fill(prex),vy.clear(),vx.clear();
      cin>>r>>c>>h>>v;

      rep(i,r)rep(j,c){
        char tmp;cin>>tmp;
        if(tmp=='@')a[i][j]=1;
        else a[i][j]=0;
      }

      rep(j,c)rep(i,r)prey[j]+=a[i][j];
      repA(j,1,c-1)prey[j]+=prey[j-1];

      rep(j,c)rep(i,r)prex[i][j]=a[i][j];
      rep(j,c)repA(i,1,r-1)prex[i][j]+=prex[i-1][j];

      // rep(j,c)cout<<prex[r-1][j]<<'.';cout<<endl;

      int cnt=0;
      rep(i,c)cnt+=prex[r-1][i];
      if(cnt%((v+1)*(h+1))!=0){cout<<"Case #"<<aa+1<<": IMPOSSIBLE\n";continue;}

      int yy=cnt/(v+1),ff=0;
      // vy.pb(0);
      while(sz(vy)<v){
        int i=lower_bound(prey,prey+c,yy)-prey;
        if(prey[i]==yy)vy.pb(i);
        else {cout<<"Case #"<<aa+1<<": IMPOSSIBLE\n",ff=1;break;}

        yy=yy+cnt/(v+1);
      }
      if(ff==1)continue;
      vy.pb(c);

      // trav(it,vy)cout<<it<<endl;
      // rep(i,sz(vy))cout<<vy[i]<<',';cout<<endl;

      fill(pre);
      int l_=-1,r_=-1;
      rep(i,v+1){
        l_=r_+1,r_=vy[i];
        // cout<<l_<<"<->"<<r_<<endl;
        // cout<<r<<'.';

        rep(ii,r){
          // cout<<i<<','<<ii<<endl;
          repA(j,l_,r_)pre[i][ii]+=prex[ii][j];//cout<<"("<<ii<<','<<j<<"),";
          //cout<<endl;
        }

      }//cout<<endl;

      // rep(j,r){
      //   rep(i,v+1)cout<<pre[i][j]<<',';
      //   cout<<endl;
      // }

      int xx=cnt/(h+1)/(v+1);ff=0;
      while(sz(vx)<h){
        int mm=-1;
        rep(i,v+1){
          int ii=lower_bound(pre[i],pre[i]+r,xx)-pre[i];
          mm=max(mm,ii);
          if(pre[i][mm]!=xx){cout<<"Case #"<<aa+1<<": IMPOSSIBLE\n",ff=1;break;}
        }
        if(ff==1)break;
        // cout<<"mm:"<<mm<<","<<xx<<"->";
        // rep(i,v+1)cout<<pre[i][mm]<<',';cout<<endl;
        rep(i,v+1)if(pre[i][mm]!=xx){cout<<"Case #"<<aa+1<<": IMPOSSIBLE\n",ff=1;break;}

        if(ff==1){break;}

        vx.pb(mm);
        xx=xx+cnt/(h+1)/(v+1);
      }
      if(ff==1)continue;
      // trav(it,vx)cout<<it<<",";cout<<endl;




      cout<<"Case #"<<aa+1<<": POSSIBLE\n";


    }




    return 0;
}
