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

ll a[40];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    // repA(k,1,32){
    //   ll tk=1,lk=0;while(tk<=k)tk*=2,lk++;
    //   cout<<k<<','<<lk<<','<<(ll)(1<<lk)<<endl;
    // }

    int t;cin>>t;
    rep(aa,t){
      fill(a);
      ll n,k;cin>>n>>k;
      if(k==1){rep(i,n)cout<<"1 ";cout<<endl;continue;}

      ll tk=1,lk=0;while(tk<=k)tk*=2,lk++;


      if(n<=lk){
        vll b;
        rep(i,n)b.pb(lk/n);
        ll tt=lk-(lk/n)*n;
        rep(i,tt)b[i]++;
        sort(all(b));
        // cout<<lk<<","<<(1<<lk)<<endl;

        // rep(i,n)cout<<b[i]<<',';cout<<endl;

        int mark[40]={0};
        rep(i,n){
          int j=lk-1;ll ans=0;

          while(b[i]&&j>=0){
            // cout<<i<<','<<k<<','<<(1LL<<j)<<','<<(k&(1LL<<j))<<","<<mark[j]<<endl;
            if((i || k&(1LL<<j) ) && mark[j]==0)
              b[i]--,mark[j]=1,ans+=(1LL<<j);//cout<<"okay\n";
            j--;
          }

          b[i+1]+=b[i];

          cout<<ans<<' ';
        }
        cout<<endl;

        continue;
      }

      if(k==2){
        rep(i,min(n,lk))a[lk-i-1]=1;
        n-=lk;
        if(n%2)a[0]++,a[1]+=(n/2)*2;
        else a[0]+=n;

        rep(i,lk)rep(j,a[i]){
          cout<<(ll)(1<<i)<<' ';
        }cout<<endl;

        continue;
      }

      rep(i,min(n,lk))a[lk-i-1]=1;
      n-=lk;
      if(n%2)a[0]++,a[1]+=(n/2)*2-1,cout<<"3 ";
      else a[0]+=n;

      rep(i,lk)rep(j,a[i]){
        cout<<(ll)(1<<i)<<' ';
      }cout<<endl;
    }



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
