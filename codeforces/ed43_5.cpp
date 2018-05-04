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
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

bool comp(pp a,pp b){
  return (a.fst-a.snd)>(b.fst-b.snd);
}
vpp v;ll po=0;int n=0,a=0,b=0;

ll improve(ll sum,ll i){
  if(i<min(b,n)){
    sum=sum-max(v[i].fst,v[i].snd)+po*v[i].fst;
    return sum;
  }
  if(b>0)sum=sum-v[i].snd+po*v[i].fst-max(v[b-1].fst,v[b-1].snd)+v[b-1].snd;

  return sum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n>>a>>b;
    po=pow(2,a);

    rep(i,n){
      ll h,d;cin>>h>>d;
      v.pb(mp(h,d));
    }

    sort(all(v),comp);

    ll sum=0;
    rep(i,min(b,n))sum+=max(v[i].fst,v[i].snd);
    repA(i,min(b,n),n-1)sum+=v[i].snd;

    ll maxi=sum;
    rep(i,n)maxi=max(maxi,improve(sum,i));

    cout<<maxi<<endl;

    return 0;
}
