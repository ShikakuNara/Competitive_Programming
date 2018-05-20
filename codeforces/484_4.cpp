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

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;


struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

ll n,a[MAX],vis[MAX];
UF uf(MAX);
set<pp > st;
map<ll,ll> mp,mp2;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    cin>>n;
    rep(i,n)cin>>a[i],st.insert(mp(a[i],i));

    ll ans=0,ma=0,prev=-1,ii,v,pv;
    trav(it,st){
      v=it.fst;
      ii=it.snd;
      vis[ii]=1;

      if(v!=prev){
        // if(sz(mp)==1)cout<<v<<"lol\n";
        if(sz(mp)==1&&mp.begin()->snd>ma)ans=pv+1,ma=mp.begin()->snd;
        if(sz(mp)==1&&mp.begin()->snd==ma)ans=min(ans,pv+1);
        prev=v;
      }

      mp[uf.size(ii)]++;vis[ii]=1;

      if(ii!=0&&vis[ii-1]){
        mp[uf.size(ii-1)]--;
        if(mp[uf.size(ii-1)]==0)mp.erase(uf.size(ii-1));

        mp[uf.size(ii)]--;
        if(mp[uf.size(ii)]==0)mp.erase(uf.size(ii));

        uf.join(ii,ii-1);
        mp[uf.size(ii)]++;
      }

      if(ii<n-1&&vis[ii+1]){
        mp[uf.size(ii+1)]--;
        if(mp[uf.size(ii+1)]==0)mp.erase(uf.size(ii+1));

        mp[uf.size(ii)]--;
        if(mp[uf.size(ii)]==0)mp.erase(uf.size(ii));

        uf.join(ii,ii+1);
        mp[uf.size(ii)]++;
      }

      pv=a[ii];
    }

    if(sz(mp)==1&&mp.begin()->snd>ma)ans=a[ii]+1,ma=mp.begin()->snd;
    if(sz(mp)==1&&mp.begin()->snd==ma)ans=min(ans,a[ii]+1);

    cout<<ans<<endl;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
