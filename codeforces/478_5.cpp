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
	explicit Point(T x=0.00000000000000, T y=0.00000000000000) : x(x), y(y) {}
	bool operator<(P p) const { return mp(x,y) < mp(p.x,p.y); }
	bool operator==(P p) const { return mp(x,y)==mp(p.x,p.y); }
	bool operator!=(P p) const { return mp(x,y)!=mp(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	long double dist() const { return sqrt((long double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	long double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(long double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


typedef Point< long double > P;
P linearTransformation(const P& p0, const P& p1,
		const P& q0, const P& q1, const P& r) {
	P dp = p1-p0, dq = q1-q0, num(dp.cross(dq), dp.dot(dq));
	return q0 + P((r-p0).cross(num), (r-p0).dot(num))/dp.dist2();
}

Point<long double> polygonCenter(vector<P>& v) {
	auto i = v.begin(), end = v.end(), j = end-1;
	Point<long double> res(0.0000000000,0.0000000000) ; long double A = 0.0000000;
	for (; i != end; j=i++) {
		res = res + (*i + *j) * j->cross(*i);
		A += j->cross(*i);
	}
	return res / A / 3;
}

vector<P > poly;
P cmo,ori,cur,cm;

void rot(int i){
	P a;
	cout<<fixed<<setprecision(12);
	// cout<<"ori: "<<ori.x<<','<<ori.y<<endl;
	// cout<<"cmo: "<<cmo.x<<','<<cmo.y<<endl;
	// cout<<"cur: "<<cur.x<<','<<cur.y<<endl;
	// cout<<"cm: "<<cm.x<<','<<cm.y<<endl;
	if(abs(ori.x-cmo.x)<1e-5&&
		 abs(ori.y-cmo.y)<1e-5&&
		 abs(cur.x-cm.x)<1e-5&&abs(cur.y-cm.y)<1e-5)
		 a=a+cur-ori;
	else a=linearTransformation(ori,cmo,cur,cm,poly[i]);//polygon vertex
	// else

  long double dist=(cm.x-a.x)*(cm.x-a.x)+(cm.y-a.y)*(cm.y-a.y);
  dist=sqrt((long double)dist);

	P old=cm;
	P tmp(a.x,a.y-dist);cm=tmp;
	// cout<<"a: "<<a.x<<','<<a.y<<endl;
	// cout<<"old: "<<old.x<<','<<old.y<<endl;
	// cout<<"cm: "<<cm.x<<','<<cm.y<<endl;
	if(old!=cm)cur=linearTransformation(a,old,a,cm,cur);//new origin
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    ll n,q;cin>>n>>q;
    cout<<fixed<<setprecision(12);
    rep(i,n){
      long double x,y;cin>>x>>y;
      P pt(x,y);
      poly.pb(pt);
    }

		P tmp(0,0);
		ori=cur=tmp;
		long double tx=0,ty=0;

		rep(i,n)tx+=poly[i].x/n,ty+=poly[i].y/n;
		rep(i,n)poly[i].x-=tx,poly[i].y-=ty;
		cmo=cm=polygonCenter(poly);

		cmo.x+=tx,cmo.y+=ty,cm.x+=tx,cm.y+=ty;
		rep(i,n)poly[i].x+=tx,poly[i].y+=ty;

    int a=0,b=1;

    rep(i,q){
      int t;cin>>t;
      if(t==1){
        int f,t;cin>>f>>t;f--,t--;
        if(a==f)rot(b),a=t;
        else rot(a),b=t;
      }
      else{
        int v;cin>>v,v--;
				P tmp=linearTransformation(ori,cmo,cur,cm,poly[v]);
				// cout<<"ori: "<<ori.x<<','<<ori.y<<endl;
				// cout<<"cmo: "<<cmo.x<<','<<cmo.y<<endl;
				// cout<<"cur: "<<cur.x<<','<<cur.y<<endl;
				// cout<<"cm: "<<cm.x<<','<<cm.y<<endl;
				if(ori==cmo&&cur==cm)
					cout<<(long double)poly[v].x+cur.x-ori.x<<' '<<(long double)poly[v].y+cur.y-ori.y<<endl;
        else cout<<(long double)tmp.x<<' '<<(long double)tmp.y<<endl;
      }
    }






    return 0;
}
