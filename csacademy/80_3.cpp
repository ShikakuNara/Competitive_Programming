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
typedef pair<ll, pp > ppp;
typedef pair<ll, pp> ppp;
typedef vector<pp > vpp;
typedef vector<ppp > vppp;

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

bool comp(ll a,ll b){return a>b;}

ll q[MAX],vis[MAX];
priority_queue<pp > pq;
set< ppp > st;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");tm=clock();
    #endif


    ll n,x;cin>>n>>x;ll sum=0;
    rep(i,n)cin>>q[i],sum+=q[i];
    sort(q,q+n,comp);
    cout<<(sum+x-1)/x<<' ';

    ll y=(sum+x-1)/x;

    rep(i,y)pq.push(mp(0,x-q[i]));
    repA(i,y,n-1)st.insert(mp(-q[i],mp(0,i)));
    // cout<<sz(st)<<endl;

    ll m=0;
    while(sz(st)!=0&&!pq.empty()){
      pp c=pq.top();pq.pop();
      // cout<<-c.fst<<','<<c.snd<<endl;
     m=max(m,-c.fst);
     vppp ins,era;

      trav(it,st){
        ll t=it.snd.fst,q=-it.fst;m=max(m,t);ll x=it.snd.snd;
        ll ft=max(-c.fst,t)+min(q,c.snd);

        // cout<<ft<<','<<t<<':'<<-c.fst<<','<<q<<endl;

        if(q>c.snd)ins.pb(mp(-q+c.snd,mp(ft,x))),era.pb(it);
        else pq.push(mp(-ft,c.snd-q)),era.pb(it);
        break;
      }
      rep(i,sz(ins))st.insert(ins[i]);//,cout<<"ins:"<<ins[i].fst<<endl;
      rep(i,sz(era))st.erase(era[i]);//,cout<<"era:"<<era[i].fst<<endl;
      // cout<<sz(st)<<endl;
      // cout<<"...\n";
    }

    while(!pq.empty())
    {
      // cout<<"***\n";
      pp it=pq.top();pq.pop();
      // cout<<it.fst<<endl;
      m=max(m,-it.fst);
    }
    cout<<m<<endl;



    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
