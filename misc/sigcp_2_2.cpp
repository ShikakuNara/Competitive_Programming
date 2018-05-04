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

set<int> a[210*210],unvis;
vi ans[210];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int n;cin>>n;
    rep(i,n*(n-1)/2){
      int k;cin>>k;
      rep(j,k){
        int t;cin>>t;
        unvis.insert(t);
        a[i].insert(t);
      }
    }

    if(n==2){
      cout<<1<<' '<<*a[0].begin()<<endl;
      a[0].erase(a[0].begin());
      cout<<sz(a[0])<<' ';
      trav(it,a[0])cout<<it<<' ';cout<<endl;
      return 0;
    }

    int ii=0;

    while(!unvis.empty()){
      int ix=*unvis.begin();//ans[ii].pb(ix);

      unvis.erase(unvis.begin());

      set<int> itn;
      int x=-1,y=-1;

      repA(i,0,n*(n-1)/2-1)if(a[i].find(ix)!=a[i].end()){x=i;break;}
      repA(i,x+1,n*(n-1)/2-1)if(a[i].find(ix)!=a[i].end()){y=i;break;}

      set_intersection(all(a[x]),all(a[y]),inserter(itn,itn.begin()));
      if(itn.find(ix)==itn.end())itn.insert(ix);
      trav(it,itn)unvis.erase(it),ans[ii].pb(it);

      ii++;
    }

    if(ii!=n)cout<<-1<<endl;

    rep(i,ii){
      cout<<sz(ans[i])<<' ';
      trav(it,ans[i])cout<<it<<' ';cout<<endl;
    }





    return 0;
}
