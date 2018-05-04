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

const int MAX=4000006;
const int MOD=(ll)(1<<30)-1;
const int inf=1e9+10;

ll g[MAX],p[MAX];
vll isprime(MAX,true);
vll prime;

void pre()
{
  for(int i=2;i*i<=MAX;i++)if(!p[i]){
    for(int j=2*i;j*j<=MAX;j+=i)g[j]=i,p[j]=1;
  }

  ll s=sqrt(MAX)+1;
  for(int i=2;i*i<=MAX;i++)if(!p[i]){
      ll k=(s/i)*i;
      if(k==i)k+=i;
      if(k==0)k=2*i;

      for(;k<MAX;k+=i)if(g[k]==0&&k!=i)g[k]=i;
  }

  repA(i,2,MAX-1){
    if(g[i]==0){g[i]=1-i;continue;}

    int m=i/g[i],p=g[i];
    if(m%p!=0)g[i]=(g[m]*(1-p));
    else{
      g[i]=g[m]/(1-p);
      g[i]=(g[i]*(-p));
      m/=p;
      if(m%p==0)g[i]=0;
    }
  }

  g[0]=0;g[1]=1;
  repA(i,2,MAX-1)g[i]=(i*g[i]+g[i-1]);
}

ll ps(ll x) {
    return ((ll)x*(x+1))/2;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");clock_t tm=clock();tm=clock();
    #endif

    pre();
    int t;cin>>t;
    rep(aa,t){
      ll a,b;cin>>a>>b;
      if(a>b)swap(a,b);

      vll v;
      ll val=0;
      for(int i=1;i<=a;i=val+1){
        val=a/(a/i);
        v.pb(i);
      }val=0;
      for(int i=1;i<=a;i=val+1){
        val=b/(b/i);
        v.pb(i);
      }
      sort(all(v));
      if(v[sz(v)-1]!=a)v.pb(a);
      set<int> s(all(v));
      vll w(all(s));

      ll ans2=0,ans=0;
      repA(i,0,sz(w)-1){
        ll j=w[i];
        cout<<j<<',';
        if(i!=0)ans2+=(g[w[i]]-g[w[i-1]])*ps(a/j)*ps(b/j);
        else ans2+=(g[w[i]])*ps(a/j)*ps(b/j);
        ans2&=MOD;
      }cout<<endl;
      cout<<ans2<<endl;

      ll a1,a2;
      for(int i=1;i<=a;i=a1+1) {
          a1=a/(a/i);
          a2=b/(b/i);
          if(a1>a2)a1=a2;
          cout<<a1<<',';
          ans=(ans+(((ps(a/i)*ps(b/i)))*(g[a1]-g[i-1])))&MOD;
      }
      cout<<ans<<'\n';
    }

    #ifdef LOCAL_TEST
    tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";
    #endif

    return 0;
}
