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
const long double PI=3.141592653589793238462643383;
#define fst first
#define snd second

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX=1000005;
const int MOD=1e9+7;
const int inf=1e9+10;

ll lp[MAX],t[MAX],mu[MAX],ans[MAX],p[MAX];
vi pr;

void pre()
{
    t[1]=1,mu[1]=1;
    repA(i,2,MAX-1){
      if(!lp[i]){
        lp[i]=i,t[i]=i-1;
        pr.push_back(i);
        mu[i]=-1;
      }
      else if(lp[i]==lp[i/lp[i]]){
        t[i]=t[i/lp[i]]*lp[i];
        mu[i]=0;
      }
      else{
        t[i]=t[i/lp[i]]*(lp[i]-1);
        mu[i]=mu[i/lp[i]]*(-1);
      }
      for (int j=0; j < (int)pr.size()&&pr[j]<=lp[i]&&i*pr[j]<=MAX-1; ++j)
        lp[i*pr[j]]=pr[j];
    }
}

void sieve2(){
  repA(i,1,MAX-1)ans[i]=2;

  repA(i,2,MAX-1){
    ans[i]+=t[i]*i;
    for(int j=2*i;j<MAX;j+=i)ans[j]+=t[i]*i,p[j]=1;
  }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();
    sieve2();
    int tt;cin>>tt;
    rep(aa,tt){
      ll n;cin>>n;
      ll ans1=ans[n]*n/2;
      cout<<ans1<<endl;
    }


    return 0;
}
