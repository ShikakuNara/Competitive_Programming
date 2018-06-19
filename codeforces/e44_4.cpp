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
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=(a);i<=(n);++i)
#define repD(i,a,n) for(ll i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'


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

ll Abs(ll i){
  if(i>0)return i;
  return -i;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif


    ll n,h;cin>>n>>h;
    ll k=sqrt(2*n)+100;
    while(k*k+k>2*n)k--;
    if(k<=h){
      if(k*k+k==2*n)cout<<k<<endl;
      else cout<<k+1<<endl;
      return 0;
    }

    ll ansa,ansb,nt=n;

    ansa=h;n-=(h*h+h)/2;
    if(n!=0)ansa+=n/h,n-=(n/h)*h;
    if(n!=0)ansa++;

    n=nt;

    ansb=-(h-1);n+=h*(h-1)/2;
    ll s=sqrt(n);
    // cout<<ansb<<endl;
    ansb+=2*s-1;n-=s*s;
    // cout<<ansb<<endl;
    if(n!=0)ansb+=n/s,n-=(n/s)*s;
    if(n!=0)ansb++;

    // cout<<ansa<<','<<ansb<<endl;
    cout<<min(ansa,ansb);


    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
