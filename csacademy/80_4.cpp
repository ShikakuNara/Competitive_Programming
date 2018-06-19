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
typedef long double ld;
typedef pair<ld, ld> pp;
typedef pair<ld, pp> ppp;
// typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

priority_queue < pp > pq,pq2;
ld d[MAX],t[MAX];

ld e1(int i){
  return d[i]/t[i]-d[i]/(t[i]+1);
}

const ld CST=7;

ld e2(int i){
  return d[i]/t[i]-d[i]/(t[i]+CST);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif

    ll n,x;cin>>n>>x;
    rep(i,n)cin>>d[i];
    rep(i,n)cin>>t[i],pq.push(mp(e2(i),i));

    while(x>10*n){
      pp c=pq.top();pq.pop();
      int i=c.snd;
      pp cc=pq.top();

      while(x>0&&e2(i)>=cc.fst)
        t[i]+=CST,x-=CST;

      pq.push(mp(e2(i),i));
    }

    rep(i,n)pq2.push(mp(e1(i),i));

    while(x>0){
      pp c=pq2.top();pq2.pop();
      int i=c.snd;
      pp cc=pq2.top();

      while(x>0&&e1(i)>=cc.fst)
        t[i]++,x--;

      pq2.push(mp(e1(i),i));
    }

    ld ans=0;
    while(!pq2.empty()){
      pp c=pq2.top();pq2.pop();int i=c.snd;
      ans+=d[i]/t[i];
    }
    cout<<fixed<<setprecision(12);
    cout<<ans<<endl;


    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
