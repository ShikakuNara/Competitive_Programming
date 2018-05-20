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

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

char a[1009][1009];
int ans[1009][1009],vis[1009][1009];
int n,m;

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(int x,int y){
  if(x<0||x>=n||y<0||y>=m||vis[x][y])return false;
  return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    fillA(ans);

    int k;cin>>n>>m>>k;
    rep(i,n){
      string s;cin>>s;
      rep(j,m)a[i][j]=s[j];
    }

    int tim=1;

    rep(i,k){
      int x,y;cin>>x>>y;x--,y--;
      if(ans[x][y]!=-1){cout<<ans[x][y]<<endl;continue;}
      tim++;

      //bfs
      priority_queue< ppp> pq;
      pq.push(mp(0,mp(x,y)));vis[x][y]=tim;

      int cnt=0;vpp arr;
      while(!pq.empty()){
        ppp c=pq.top();pq.pop();
        int d=-c.fst,xc=c.snd.fst,yc=c.snd.snd;
        arr.pb(mp(xc,yc));

        rep(i,4){
          int x=xc+dx[i],y=yc+dy[i];
          if(!check(x,y))continue;
          if(a[x][y]=='*')cnt++;
          else pq.push(mp(-d-1,mp(x,y))),vis[x][y]=tim;
        }
      }

      ans[x][y]=cnt;
      cout<<cnt<<endl;

      rep(i,sz(arr)){
        int x=arr[i].fst,y=arr[i].snd;
        ans[x][y]=cnt;
      }
    }





    return 0;
}
