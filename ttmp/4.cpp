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

int cnt[MAX];

set<pp > a;
priority_queue<pp > pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int w,l;cin>>w>>l;
    rep(i,w-1){int tmp;cin>>tmp;if(tmp)a.insert(mp(i+1,tmp));}

    ll ans=0;
    vpp era;
    trav(it,a){
      if(it.fst>l)break;
      else pq.push(it),era.pb(it);
    }
    rep(i,sz(era))a.erase(era[i]);


    while(!pq.empty()){
      pp cur=pq.top();pq.pop();
      if(w-cur.fst<=l){
        cout<<cur.fst<<','<<cur.snd<<endl;
        ans+=cur.snd;continue;}

      auto it=lower_bound(all(a),mp(cur.fst+l,cnt[cur.fst]));
      vpp era,add;
      while(it!=a.end()&&it!=a.begin()&&cur.snd>0){
        if(it->fst-cur.fst>l)break;
        cout<<"a"<<cur.fst<<','<<cur.snd<<endl;
        cout<<"b"<<it->fst<<','<<min(it->snd,cur.snd)<<endl;
        pq.push(mp(it->fst,min(it->snd,cur.snd)));

        cnt[it->fst]=min(it->snd,cur.snd);
        // era.pb(*it);
        // add.pb(mp(it->fst,));

        cur.snd-=min(it->snd,cur.snd);

        a.erase(*it);
        if(it->snd-min(it->snd,cur.snd))a.insert(mp(it->fst,it->snd-min(it->snd,cur.snd)));
        it=lower_bound(all(a),mp(cur.fst+l,cnt[cur.fst]));
      }

      rep(i,sz(era))a.erase(era[i]);
      rep(i,sz(add))if(add[i].snd)a.insert(add[i]);
    }
    cout<<ans<<endl;


    return 0;
}
