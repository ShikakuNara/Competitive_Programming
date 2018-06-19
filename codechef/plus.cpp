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

const int MAX = 1009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int kk;

struct Tree {
	typedef int T;
	const T LOW = -1234567890;
	T f(T a, T b) { return max(a, b); }

	int n;
	vi s;
	Tree() {init(kk, 0);}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	}
};

int a[MAX][MAX],ar[MAX][MAX],ac[MAX][MAX],ar2[MAX][MAX],ac2[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      int n,m;cin>>n>>m;kk=max(n,m);
      rep(i,n)rep(j,m)cin>>a[i][j],ar[i][j]=ac[i][j]=a[i][j];
      rep(i,n)repA(j,1,m-1)ar[i][j]+=ar[i][j-1];
      rep(j,m)repA(i,1,n-1)ac[i][j]+=ac[i-1][j];

      rep(i,n)rep(j,m)ar2[i][j]=ac2[i][j]=a[i][j];
      rep(i,n)repD(j,m-2,0)ar2[i][j]+=ar2[i][j+1];
      rep(j,m)repD(i,n-2,0)ac2[i][j]+=ac2[i+1][j];


      Tree H[n],V[m],H2[n],V2[m];

      rep(i,n)rep(j,m)H[i].update(j,ar[i][j]);
      rep(i,n)rep(j,m)V[j].update(i,ac[i][j]);

      rep(i,n)rep(j,m)H2[i].update(j,ar2[i][j]);
      rep(i,n)rep(j,m)V2[j].update(i,ac2[i][j]);

      ll mm=-1e15;
      repA(i,1,n-2)repA(j,1,m-2){
        ll tmp=a[i][j];
        tmp+=H[i].query(j+1,m)-ar[i][j];
        tmp+=H2[i].query(0,j)-ar2[i][j];
        tmp+=V[j].query(i+1,n)-ac[i][j];
        tmp+=V2[j].query(0,i)-ac2[i][j];

        mm=max(mm,tmp);
      }

      cout<<mm<<endl;
    }




    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
