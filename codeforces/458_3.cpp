#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

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
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll ans[1009]={0};

ll count(ll i){
  ll cnt=0;
  repA(j,0,11)if(i&(1<<j))cnt++;
  return cnt;
}

ll solve(ll i){
  if(ans[i]>=0)return ans[i];
  return ans[i]=1+solve(count(i));
}

// Returns nCr % p.  In this Lucas Theorem based program,
// this function is only called for n < p and r < p.
ll nCrModpDP(ll n, ll r, ll p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    ll C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1]+p)%p;
    }
    return C[r];
}

ll Cr(ll n,ll r,ll p)
{
  if(r<0||n<r)return 0;
   if (r==0)return 1;

   // Compute last digits of n and r in base p
   ll ni = n%p, ri = r%p;
   return (Cr(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}

ll conv(string n){
  if(sz(n)>12)return 1005;
  int j=1,ans=0;
  repD(i,sz(n)-1,0){
    if(n[i]=='1')ans+=j;
    if(ans>10000)return ans;
    j*=2;
  }
  return ans;
}

ll cnt(string n){
  ll c=0;
  rep(i,sz(n))if(n[i]=='1')c++;
  return c;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    fillA(ans);ans[1]=0,ans[2]=1;
    repD(i,1000,1)if(ans[i]==-1)solve(i);

    string n;cin>>n;
    ll k;cin>>k;
    if(k>=6)cout<<0<<endl;
    else if(k==0)cout<<1<<endl;
    else if(k==1)cout<<sz(n)-1<<endl;
    else{
      ll res=0;
      ll nn=conv(n);

      repA(i,1,min(1000LL,nn))if(ans[i]==k)res++;

      if(nn<=1000){cout<<res<<endl;return 0;}
      res=0;

      int bb=0;
      repA(aa,0,sz(n)-1){

        repA(i,1,1001)if(ans[i]==k-1){
          res=(res+Cr(sz(n)-1-aa,i-bb,MOD)+MOD)%MOD;
        }

        aa++;
        while(aa<sz(n)&&n[aa]!='1')aa++;
        bb++;aa--;
      }

      if(ans[cnt(n)]==k-1)res++;


      cout<<res<<endl;
    }



    return 0;
}
