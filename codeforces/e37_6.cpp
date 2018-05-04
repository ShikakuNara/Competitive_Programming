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
#define X first
#define Y second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}
ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}

const int MAX = 400009;
const int MAX2 = 1000000;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll d[MAX2+9]={0},a[MAX],cnt[MAX2+9]={0};

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};


void pre(){
  repA(i,1,MAX2)for(int j=i;j<=MAX2;j+=i)d[j]++;
  cnt[1] = 0;
  cnt[2] = 0;
  repA(i,1,MAX2){cnt[i]=1+cnt[d[i]];}
}

map<ll,ll> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    pre();

    int n,q;cin>>n>>q;
    FT tree(n+1);
    rep(i,n){
      cin>>a[i],tree.update(i,a[i]);
      if(cnt[a[i]])mp[i]=cnt[a[i]];
    }

    rep(i,q){
      int t,l,r;cin>>t>>l>>r;l--,r--;
      if(t==1){
          auto it=mp.lower_bound(l);
          vi del,sub;
          while(it!=mp.end()&&it->X<=r){
            int ix=it->X;

            tree.update(ix,d[a[ix]]-a[ix]);
            a[ix]=d[a[ix]];

            if(mp[ix]>1)sub.pb(ix);
            else del.pb(ix);

            it++;
          }

          trav(it,del)mp.erase(it);
          trav(it,sub)mp[it]--;
      }
      else  cout<<tree.query(r+1)-tree.query(l)<<endl;
    }




    return 0;
}
