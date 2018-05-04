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
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll C(int n, int k) {
	ll c = 1, to = min(k, n-k);
	if (to < 0) return 0;
	repA(i,0,to-1) c = c * (n - i) / (i + 1);
	return c;
}

int a[10];

ll pw(ll a,ll b){
  // if(a<=0)return 1;
  if(b<=0)return 1;
  if(b==1)return a;

  ll res=pw(a,b/2);
  res*=res;
  if(b%2)res*=a;
  return res;
}
int b=0;int bc;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    rep(i,10)cin>>a[i],b+=1-a[i];

    string n;cin>>n;

    ll ans=0;
    stringstream geek(n);

    ll x = 0;
    geek >> x;


    repD(i,sz(n)-1,0){
      int t=0;
      rep(j,n[i]-'0')if(!a[j])t++;
      int ff=1;
      rep(j,i)if(a[n[j]-'0'])ff=0;
      ans+=ff*t*pw(b,sz(n)-1-i);
    }
    // cout<<ans<<endl;

    string nn=n;
    if(a[0]&&sz(nn)>1){
      nn=nn.substr(1,sz(nn)-1);
      repD(i,sz(nn)-1,0){
        ans+=pw(b,sz(nn)-i);
        // cout<<ans<<endl;
      }
      // cout<<nn<<":"<<ans<<endl;
    }
    cout<<ans<<endl;



    return 0;
}
