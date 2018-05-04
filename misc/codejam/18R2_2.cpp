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

const int MAX = 1009;
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
      int d[MAX],a[MAX],b[MAX];
      int s;cin>>s;
      rep(i,s)cin>>d[i]>>a[i]>>b[i];

      int M=-1,m,n,cnt;
      set<pp > st;

      // rep(i,s){
      //   m=d[i]+a[i];
      //   n=d[i]-b[i];
      //   cout<<m<<','<<n<<endl;
      // }

      rep(i,s)rep(j,s){
        m=d[i]+a[i];
        n=d[j]-b[j];



        int k=0;
        while(k<s){
          int tmp=0,ff=0,gg=0,ci,cj;
          for( ;k<=s-1;k++){
            if(ff==0&&(m==d[k]+a[k]||n==d[k]-b[k]))ci=k;
            if(m==d[k]+a[k]||n==d[k]-b[k])tmp++,ff=1;
            else if(ff==1) {cj=k,gg=1;break;}
          }
          if(gg==0){cj=s;}

          if(tmp>M)M=tmp,cnt=1,st.clear(),st.insert(mp(ci,cj));
          else if(tmp==M&&st.find(mp(ci,cj))==st.end())cnt++,st.insert(mp(ci,cj));
        }

      }

      cout<<"Case #"<<aa+1<<": "<<M<<' '<<cnt<<endl;
    }






    return 0;
}
