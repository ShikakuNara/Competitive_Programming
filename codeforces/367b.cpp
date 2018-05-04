#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <ll> vi;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(ll i=0;i<(n);++(i))
#define repA(i,a,n) for(ll i=(a);i<=(n);++(i))
#define repD(i,a,n) for(ll i=(a);i>=(n);--(i))
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

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
const int MAX = 200010;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX],b[MAX];
map<ll,ll>mp;
set<pp > st;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

	ll n,m,p;cin>>n>>m>>p;
	rep(i,n)cin>>a[i];

	rep(i,m)
	{
		cin>>b[i];
		if(mp.find(b[i])==mp.end())mp[b[i]]=1;
		else mp[b[i]]++;
	}

	if(n<m){cout<<0<<endl;return 0;}

	int cnt=0;vi ans;
	auto it=st.lower_bound(mp(-inf,-inf));

	st.clear();

  trav(it,mp)st.insert(mp(it.X,it.Y));

  queue<ll > que;

  repA(i,0,min(p-1,n-1))if(i+(m-1)*p>=n)continue;
  else
	{
    //first window
		for(ll j=i;j<n&&j<=i+(m-1)*p;j+=p)
		{
			it=st.lower_bound(mp(a[j],-inf));
			if(it!=st.end()&&it->X==a[j])
			{
				pp tmp=*it;tmp.Y--;
				st.erase(it);
				if(tmp.Y!=0)st.insert(tmp);
			}
			else st.insert(mp(a[j],-1));
			que.push(a[j]);
		}

    //sliding window
		for(ll j=i+(m-1)*p;j<n;j+=p)
		{
			ll k=j-(m-1)*p-p;if(k>n)continue;

			if(k>=i)
			{
				auto it=st.lower_bound(mp(a[k],-inf));
				if(it!=st.end()&&it->X==a[k])
				{
					pp tmp=*it;tmp.Y++;
					st.erase(it);
					if(tmp.Y!=0)st.insert(tmp);
				}
				else st.insert(mp(a[k],1));
        que.pop();

				it=st.lower_bound(mp(a[j],-inf));
				if(it!=st.end()&&it->X==a[j])
				{
					pp tmp=*it;tmp.Y--;
					st.erase(it);
					if(tmp.Y!=0)st.insert(tmp);
				}
				else st.insert(mp(a[j],-1));
        que.push(a[j]);
			}

			if(st.empty())cnt++,ans.pb(k+1+p);
		}

    //reset
		while(!que.empty())
		{
			ll ii=que.front();que.pop();
			auto it=st.lower_bound(mp(ii,-inf));
			 if(it!=st.end()&&it->X==ii)
			 {
				 pp tmp=*it;tmp.Y++;
				 st.erase(it);
				 if(tmp.Y!=0)st.insert(tmp);
			 }
			 else st.insert(mp(ii,1));
		}
	}

	cout<<cnt<<endl;
	sort(all(ans));
	trav(it,ans)cout<<it<<' ';cout<<endl;
    return 0;
}
