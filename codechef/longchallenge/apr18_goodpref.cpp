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

const int MAX = 2000009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[1009];
ll nt,m=inf,M=-1,sum,ans=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      string s;cin>>s;
      ll n;cin>>n;
      nt=n,ans=0,m=inf,M=-1;

      repA(i,1,sz(s))if(s[i-1]=='a')a[i]=a[i-1]+1;else a[i]=a[i-1]-1;
      sum=a[sz(s)];
      repA(i,1,sz(s))m=min(m,a[i]),M=max(M,a[i]);


      if(sum==0){
        repA(i,1,sz(s))if(a[i]>0)ans++;
        ans*=n;
      }
      else if(sum>0){
        while(m<=0&&n>0){
          m=inf,M=-1;n--;

          repA(i,1,sz(s))if(a[i]>0)ans++;
          repA(i,1,sz(s))a[i]+=sum,m=min(m,a[i]),M=max(M,a[i]);
        }
        ll sl=sz(s);
        ans+=sl*n;
      }
      else{
        while(M>0&&n>0){
          m=inf,M=-1;n--;

          repA(i,1,sz(s))if(a[i]>0)ans++;
          repA(i,1,sz(s))a[i]+=sum,m=min(m,a[i]),M=max(M,a[i]);
        }
      }
      cout<<ans<<endl;
    }




    return 0;
}
