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
typedef pair<int, pp> ppp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

char a[509][509],vis[509][509];
priority_queue<ppp > pq;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
vpp t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    int n,m,k;cin>>n>>m>>k;
    rep(i,n)rep(j,m)cin>>a[i][j];
    int ff=1;
    rep(i,n)rep(j,m)if(a[i][j]=='.'&&ff)pq.push(mp(0,mp(i,j))),vis[i][j]=1,ff=0;


    while(!pq.empty()){
        ppp c=pq.top();pq.pop();
        pp p=c.snd;int d=-c.fst;
        t.pb(p);

        rep(i,4){
          int x=p.fst+dx[i],y=p.snd+dy[i];
          if(x>=0&&x<n&&y>=0&&y<m&&
            !vis[x][y]&&a[x][y]!='#')pq.push(mp(-d-1,mp(x,y))),vis[x][y]=1;
        }
    }
    reverse(all(t));
    rep(i,k)a[t[i].fst][t[i].snd]='X';

    rep(i,n){
      rep(j,m)cout<<a[i][j];
      cout<<endl;
    }




    return 0;
}
