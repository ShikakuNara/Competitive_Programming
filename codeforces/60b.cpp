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

char a[20][20][20],vis[20][20][20];
int n,m,k,cnt=0;

bool check(int i,int j,int kk){
  if(i<0||j<0||kk<0||i>=n||j>=m||kk>=k)return false;
  if(vis[i][j][kk]||a[i][j][kk]=='#')return false;
  return true;
}

int dx[]={-1,0,0,0,0,1};
int dy[]={0,-1,0,0,1,0};
int dz[]={0,0,-1,1,0,0};


void dfs(int i,int j,int k){
  vis[i][j][k]=1;

  cnt++;

  rep(l,6){
    if(check(i+dx[l],j+dy[l],k+dz[l]))
    dfs(i+dx[l],j+dy[l],k+dz[l]);
  }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    cin>>k>>n>>m;

    rep(kk,k)rep(i,n){
      string s;cin>>s;
      rep(j,m)a[i][j][kk]=s[j];
    }

    int x,y;cin>>x>>y;
    dfs(x-1,y-1,0);

    cout<<cnt<<endl;




    return 0;
}
