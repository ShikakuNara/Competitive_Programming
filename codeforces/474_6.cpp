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
typedef pair<int, pp> ppp;
typedef pair<pp, int> ppp2;
typedef pair<pp, pp> pppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

struct FT {
	map <int, int> s;
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < MAX; pos |= pos + 1) s[pos] = max(dif,s[pos]);
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(s[pos-1],res);
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};


FT t[MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int n,m;cin>>n>>m;

    int mm=-1;
    rep(i,m){
      int u,v,w;cin>>u>>v>>w;

      int a=t[u].query(w);
      t[v].update(w,a+1);
      mm=max(mm,a+1);
    }
    cout<<mm<<endl;


    // fin();
    return 0;
}
