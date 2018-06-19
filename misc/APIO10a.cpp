#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// using namespace __gnu_pbds;
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

const int MAX = 1000009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


class ConvexHullDynamic
{
    typedef long long coef_t;
    typedef long long coord_t;
    typedef long long val_t;

    /*
     * Line 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * and 'xLeft' which is intersection with previous line in hull(first line has -INF)
     */
private:
    struct Line
    {
        coef_t a, b;
        double xLeft;

        enum Type {line, maxQuery, minQuery} type;
        coord_t val;

        explicit Line(coef_t aa=0, coef_t bb=0) : a(aa), b(bb), xLeft(-INFINITY), type(Type::line), val(0) {}
        val_t valueAt(coord_t x) const { return a*x+b; }
        friend bool areParallel(const Line& l1, const Line& l2) { return l1.a==l2.a; }
        friend double intersectX(const Line& l1, const Line& l2) { return areParallel(l1,l2)?INFINITY:1.0*(l2.b-l1.b)/(l1.a-l2.a); }
        bool operator<(const Line& l2) const
        {
            if (l2.type == line)
                return this->a     < l2.a;
            if (l2.type == maxQuery)
                return this->xLeft < l2.val;
            if (l2.type == minQuery)
                return this->xLeft > l2.val;
            return false;//To remove warning
        }
    };

public:
    bool            isMax; //whether or not saved envelope is top(search of max value)
    std::set<Line>  hull;  //envelope itself

private:
    /*
     * INFO:        Check position in hull by iterator
     * COMPLEXITY:  O(1)
     */
    bool hasPrev(std::set<Line>::iterator it) { return it!=hull.begin(); }
    bool hasNext(std::set<Line>::iterator it) { return it!=hull.end() && std::next(it)!=hull.end(); }

    /*
     * INFO:        Check whether line l2 is irrelevant
     * NOTE:        Following positioning in hull must be true
     *              l1 is next left to l2
     *              l2 is right between l1 and l3
     *              l3 is next right to l2
     * COMPLEXITY:  O(1)
     */
    bool irrelevant(const Line& l1, const Line& l2, const Line& l3) { return intersectX(l1,l3) <= intersectX(l1,l2); }
    bool irrelevant(std::set<Line>::iterator it)
    {
        return hasPrev(it) && hasNext(it)
               && ( isMax && irrelevant(*std::prev(it), *it, *std::next(it))
                       || !isMax && irrelevant(*std::next(it), *it, *std::prev(it)) );
    }

    /*
     * INFO:        Updates 'xValue' of line pointed by iterator 'it'
     * COMPLEXITY:  O(1)
     */
    std::set<Line>::iterator updateLeftBorder(std::set<Line>::iterator it)
    {
        if (isMax && !hasPrev(it) || !isMax && !hasNext(it))
            return it;

        double val = intersectX(*it, isMax?*std::prev(it):*std::next(it));
        Line buf(*it);
        it = hull.erase(it);
        buf.xLeft = val;
        it = hull.insert(it, buf);
        return it;
    }

public:
    explicit ConvexHullDynamic(bool isMax): isMax(isMax) {}

    /*
     * INFO:        Adding line to the envelope
     *              Line is of type 'y=a*x+b' represented by 2 coefficients 'a' and 'b'
     * COMPLEXITY:  Adding N lines(N calls of function) takes O(N*log N) time
     */
    void addLine(coef_t a, coef_t b)
    {
        //find the place where line will be inserted in set
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);

        //if parallel line is already in set, one of them becomes irrelevant
        if (it!=hull.end() && areParallel(*it, l3))
        {
            if (isMax && it->b < b || !isMax && it->b > b)
                it = hull.erase(it);
            else
                return;
        }

        //try to insert
        it = hull.insert(it, l3);
        if (irrelevant(it)) { hull.erase(it); return; }

        //remove lines which became irrelevant after inserting line
        while (hasPrev(it) && irrelevant(std::prev(it))) hull.erase(std::prev(it));
        while (hasNext(it) && irrelevant(std::next(it))) hull.erase(std::next(it));

        //refresh 'xLine'
        it = updateLeftBorder(it);
        if (hasPrev(it))
            updateLeftBorder(std::prev(it));
        if (hasNext(it))
            updateLeftBorder(std::next(it));
    }
    /*
     * INFO:        Query, which returns max/min(depends on hull type - see more info above) value in point with abscissa 'x'
     * COMPLEXITY:  O(log N), N-amount of lines in hull
     */
    val_t getBest(coord_t x) const
    {
        Line q;
        q.val = x;
        q.type = isMax ? Line::Type::maxQuery : Line::Type::minQuery;

        auto bestLine = hull.lower_bound(q);
        if (isMax) --bestLine;
        return bestLine->valueAt(x);
    }
};

typedef ConvexHullDynamic chd;

const ll is_query = -(1LL<<62);
struct Line {
	    ll m, b;
		    mutable function<const Line*()> succ;
			    bool operator<(const Line& rhs) const {
					        if (rhs.b != is_query) return m < rhs.m;
							        const Line* s = succ();
									        if (!s) return 0;
											        ll x = rhs.m;
													        return b - s->b < (s->m - m) * x;
															    }
};
struct HullDynamic : multiset<Line> { // will maintain upper hull for maximum
	    bool bad(iterator y) {
			        auto z = next(y);
					        if (y == begin()) {
								            if (z == end()) return 0;
											            return y->m == z->m && y->b <= z->b;
														        }
							        auto x = prev(y);
									        if (z == end()) return y->m == x->m && y->b <= x->b;
											        return (x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m);
													    }
		    void addLine(ll m, ll b) {
				        auto y = insert({ m, b });
						        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
								        if (bad(y)) { erase(y); return; }
										        while (next(y) != end() && bad(next(y))) erase(next(y));
												        while (y != begin() && bad(prev(y))) erase(prev(y));
					        auto l = upper_bound((Line) { 1000000000, is_query });
							if(l!=end()) erase(l);
														    }
			    ll getBest(ll x) {
					        auto l = *lower_bound((Line) { x, is_query });
							        return l.m * x + l.b;
									    }
};

ll s[MAX],dp[MAX];


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){

      int n;cin>>n;
      ll a,b,c;cin>>a>>b>>c;

      rep(i,n)cin>>s[i];
      repA(i,1,n-1)s[i]+=s[i-1];

      chd tr(true);
      tr.addLine(0,0);

      repA(i,0,n-1){
        dp[i]=a*s[i]*s[i]+b*s[i]+c+tr.getBest(2*a*s[i]+b);
        tr.addLine(-s[i],dp[i]+a*s[i]*s[i]);
      }

      cout<<dp[n-1]<<endl;
    }

    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
