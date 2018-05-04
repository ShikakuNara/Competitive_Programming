#include <bits/stdc++.h>
#include <valarray>
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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pii;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}

int p;

typedef valarray<complex<double> > carray;
void fft(carray& x, carray& roots) {
	int N = sz(x);
	if (N <= 1) return;
	carray even = x[slice(0, N/2, 2)];
	carray odd = x[slice(1, N/2, 2)];
	carray rs = roots[slice(0, N/2, 2)];
	fft(even, rs);
	fft(odd, rs);
	rep(k,0,N/2) {
		auto t = roots[k] * odd[k];
		x[k    ] = even[k] + t;
		x[k+N/2] = even[k] - t;
	}
}

typedef vector<double> vd;
vd conv(const vd& a, const vd& b) {
	int s = sz(a) + sz(b) - 1, L = 32-__builtin_clz(s), n = 1<<L;
	if (s <= 0){ vd a;return a;}
	carray av(n), bv(n), roots(n);
	rep(i,0,n) roots[i] = polar(1.0, -2 * M_PI * i / n);
	copy(all(a), begin(av)); fft(av, roots);
	copy(all(b), begin(bv)); fft(bv, roots);
	roots = roots.apply(conj);
	carray cv = av * bv; fft(cv, roots);
	vd c(s); rep(i,0,s) c[i] = ((ll)round(cv[i].real()/n)%p + p)%p;
	return c;
}

void mod(vd &a){
  rep(i,0,sz(a)){
    int ii=round(a[i]);
    a[i]=(double)((ii%p+p)%p);
  }
}

vd solve(ll l,ll r){
  if(l==r){
    double t[]={1.0,(l%p+p)%p};
    vd a(t,t+sizeof(t)/sizeof(double));
    return a;
  }

  int m=(l+r)/2;
  return conv(solve(l,m),solve(m+1,r));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,0,t){
      int n;cin>>n>>p;
      n++;

      vd ans=solve(1,n-1);mod(ans);
			int cnt=0;
      trav(i,ans)if(round(i)!=0)cnt++;
      cout<<cnt<<endl;
    }

    return 0;
}
