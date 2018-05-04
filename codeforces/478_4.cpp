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
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

map<ll, pp > mp;
set<pp > s;
vpp tmp,pt;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    ll n,a,b;cin>>n>>a>>b;
    rep(i,n){
      ll t,x,y;cin>>t>>x>>y;
      tmp.pb(mp(x,y));
    }
    sort(all(tmp));

    // trav(it,tmp)cout<<it.fst<<' '<<it.snd<<endl;
    // cout<<"######\n";


    pp cur;ll cnt=0;int ff=0,gg=1;
    rep(i,n){
      // cout<<tmp[i].fst<<','<<tmp[i].snd;
      if(ff==0)cur=tmp[i],ff=1,cnt=1;
      else if(tmp[i]==cur)cnt++;
      else pt.pb(mp(cur.snd-cur.fst*a,cnt)),cnt=1,cur=tmp[i];
    }
    pt.pb(mp(cur.snd-cur.fst*a,cnt)),cnt=1;

    // trav(it,pt)cout<<it.fst<<' '<<it.snd<<endl;

    rep(i,sz(pt)){
      ll v,cnt;v=pt[i].fst,cnt=pt[i].snd;

        if(mp.find(v)==mp.end()){
          pp a=mp(0,0);
          mp[v]=mp(a.fst+cnt,a.snd+cnt*a.fst);
        }
        else{
          pp a=mp[v];
          mp[v]=mp(a.fst+cnt,a.snd+cnt*a.fst);
        }
    }

    ll ans=0;
    trav(it,mp)ans+=(it.snd.snd);
    cout<<2*ans<<endl;









    return 0;
}
