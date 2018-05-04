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

template <class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


template <class P>
int sideOf(const P& s, const P& e, const P& p) {
	auto a = (e-s).cross(p-s);
	return (a > 0) - (a < 0);
}
template <class P>
int sideOf(const P& s, const P& e, const P& p, double eps) {
	auto a = (e-s).cross(p-s);
	double l = (e-s).dist()*eps;
	return (a > l) - (a < -l);
}

template <class P>
bool onSegment(const P& s, const P& e, const P& p) {
	P ds = p-s, de = p-e;
	return ds.cross(de) == 0 && ds.dot(de) <= 0;
}

typedef Point<ll> P;
int insideHull2(const vector<P>& H, int L, int R, const P& p) {
	int len = R - L;
	if (len == 2) {
		int sa = sideOf(H[0], H[L], p);
		int sb = sideOf(H[L], H[L+1], p);
		int sc = sideOf(H[L+1], H[0], p);
		if (sa < 0 || sb < 0 || sc < 0) return 0;
		if (sb==0 || (sa==0 && L == 1) || (sc == 0 && R == sz(H)))
			return 1;
		return 2;
	}
	int mid = L + len / 2;
	if (sideOf(H[0], H[mid], p) >= 0)
		return insideHull2(H, mid, R, p);
	return insideHull2(H, L, mid+1, p);
}

int insideHull(const vector<P>& hull, const P& p) {
	if (sz(hull) < 3) return onSegment(hull[0], hull.back(), p);
	else return insideHull2(hull, 1, sz(hull), p);
}

int dx[]={-1,-1,-1,0,0,1,1,1},
    dy[]={-1,0,1,-1,1,-1,0,1};

bool check(ll x,ll y){
  if(x>1e9||y>1e9||x<-1e9||y<-1e9)return false;
  return true;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      vector<P > poly,ans;
      int n;cin>>n;
      rep(i,n){
        ll x,y;cin>>x>>y;
        P tmp(x,y);
        poly.pb(tmp);
      }

      int cnt=n/10;

      rep(i,n){
        if(cnt==0)break;

        ll x=poly[i].x,y=poly[i].y;

        rep(i,8){
          ll xt=x+dx[i],yt=y+dy[i];
          if(!check(x,y))continue;

          P cur(xt,yt);
          if(insideHull(poly,cur)==2)cnt--,ans.pb(cur);
          if(cnt==0)break;
        }
      }

      if(cnt==0)trav(p,ans)cout<<p.x<<' '<<p.y<<endl;
      else cout<<-1<<endl;
    }

    return 0;
}
