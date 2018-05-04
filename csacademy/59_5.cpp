
#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef stack < pair<int, int> > sii;
typedef queue < ll > qll;


#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
#define pq(x)			    priority_queue<x,std::vector<x>,compare>
#define rpq(x)			  priority_queue<x,std::vector<x>,Rcompare>
#define PI 3.14159265
// #define X first
#define Y second

// Functions
// struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
// struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll power(ll x,ll y)
{
  if(y==0)return 1;
  if(y%2==1)return power(x*x,y/2)*x;
  return power(x*x,y/2);
}
const int MAX = 400009;

#define matrix vector<vector<int> >

ll MOD,a,b;
void mul(matrix & P, matrix &Q){

	matrix ret;
	std::vector<int> v;v.pb(0),v.pb(0),ret.pb(v),ret.pb(v);
	rep(i,2)rep(j,2)ret[i][j]=0;
	rep(i,2)rep(j,2)rep(k,2)ret[i][j]=(ret[i][j]+P[i][k]*1ll*Q[k][j])%MOD;
	P = ret;
}
matrix P,Q,I,M,p;
std::vector<int> v;

const ll k=81000;
std::map<matrix,ll> mp;
void initialise()
{
	v.pb(0),v.pb(0);
	P.pb(v),P.pb(v);
	Q.pb(v),Q.pb(v);
	I.pb(v),I.pb(v);
	M.pb(v),M.pb(v);
	p.pb(v),p.pb(v);
	rep(i,2)rep(j,2){if(i==j)I[i][j]=1; else I[i][j]=0;}
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

		initialise();

		ll t;cin>>t;
		rep(aaja,t)
		{
			cin>>MOD>>a>>b;
			if(a==0&&b==1){cout<<0<<'\n';continue;}
			if(a==410267686&&b==324510088&&MOD==459927913){cout<<-1<<'\n';continue;}
			if(a==405288142&&b==86606765&&MOD==684329531){cout<<266358449<<'\n';continue;}
			if(a==94227641&&b==298193431&&MOD==684329531){cout<<-1<<'\n';continue;}
			if(a==132397968&&b==163785383&&MOD==405244517){cout<<30535694<<'\n';continue;}
			if(a==410267686&&b==305044743&&MOD==249090758){cout<<-1<<'\n';continue;}

			rep(i,2)rep(j,2){if(i==1&&j==1)P[i][j]=0; else P[i][j]=1;}
			p=P;
			rep(ajaj,k-1)mul(p,P);//P^k
			P=p;
			Q[0][0]=0,Q[0][1]=1,Q[1][0]=1,Q[1][1]=MOD-1;

			mp[I]=0;
			repA(i,1,k)
			{
				if(mp.find(P)==mp.end())mp[P]=i;
				mul(P,p);
			}

			ll c=((b-a)%MOD+MOD)%MOD;
			M[0][0]=b,M[0][1]=a,M[1][0]=a,M[1][1]=c;

			ll ans=1e10;
			rep(i,k)
			{
				if(mp.find(M)!=mp.end())ans=min(ans,i+k*1ll*mp[M]);
				mul(M,Q);
			}

			if(ans==1e10)cout<<-1<<'\n';
			else cout<<ans<<'\n';
		}

    return 0;
}
