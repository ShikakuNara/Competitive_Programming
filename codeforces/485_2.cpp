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

const int MAX = 400009;
const int MOD = 1e9+7;
const int inf = 1e9+10;



string name[]={"Power","Time","Space","Soul","Reality","Mind"};
string colour[]={"purple","green","blue","orange","red","yellow"};
int seen[6];

long double eps=1e-12;

ll powe(ll a,ll b){
  ll ans=1;
  while(b){
    if(b&1)ans=(ans*a)%MOD;
    a=(a*a)%MOD;
    b=b/2;
  }
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    long double x,y;cin>>x>>y;
    long double a,b; a=y*log(x);b=x*log(y);

    if(a-b>eps)cout<<">\n";
    else if(b-a>eps) cout<<"<\n";
    else cout<<"=\n";

    cout<<powe(x,y)<<","<<powe(y,x)<<endl;
    if(pow(x,1/x)==pow(y,1/y))cout<<"=\n";
    else if(pow(x,1/x)<pow(y,1/y))cout<<"<\n";
    else cout<<">\n";


    //  double a,b; a=y*log10(x)*1.0;b=x*log10(y)*1.0;
    //
    // if(a-b>0.0)cout<<">";
    // else if(b-a==0.0) cout<<"=";
    // else cout<<"<";



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
