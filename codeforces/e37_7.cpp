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
const int MAX2 = 1000000;
const int MOD = 1e9+7;
const int inf = 1e9+10;

vi prime(MAX2+9,true);
vi divi[MAX2+9];
void pre(){
  repA(i,2,MAX2)
  {
    if(!prime[i])continue;
    for(int j=i;j<=MAX2;j+=i)divi[j].pb(i),prime[j]=false;
    prime[i]=true;
  }
}

int lunc(int x,int p){

  int s=sz(divi[p]),tot=(1<<s)-1;
  int ans=x-1;

  repA(i,1,tot){
    int cnt=0,mul=1;
    rep(j,s)if(i&(1<<j))cnt++,mul*=divi[p][j];

    if(cnt%2)ans-=x/mul;
    else ans+=x/mul;
  }

  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    int t;cin>>t;
    rep(aa,t){
      int x,p,k;cin>>x>>p>>k;
      k+=lunc(x,p);

      int l=1,r=MAX2*10+9;
      while(l<r){
        int m=(l+r)/2;
        
        if(lunc(m,p)>=k)r=m;
        else l=m+1;
      }
      cout<<l<<endl;
    }









    return 0;
}
