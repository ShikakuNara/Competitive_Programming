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

int a[109][109];int n,m;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1, 0, 1,-1,1,-1,0,1};

bool check(int x,int y){
  if(x<n&&x>=0&&y<m&&y>=0&&a[x][y]=='*')return true;
  return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    cin>>n>>m;
    rep(i,n){
      string s;cin>>s;
      rep(j,m){
        a[i][j]=s[j];
        if(a[i][j]=='.')a[i][j]='0';
      }
    }

    int ff=1;

    rep(i,n)rep(j,m){
      if(a[i][j]=='*')continue;
      else{
        int cnt=0;
        // cout<<"ne\n";
        // cout<<i<<','<<j<<"kk\n";
        rep(k,8){
          // cout<<i+dx[k]<<','<<j+dy[k]<<','<<(char)a[i+dx[k]][j+dy[k]]<<endl;
          if(check(i+dx[k],j+dy[k]))cnt++;//cout<<i+dx[k]<<':'<<j+dy[k]<<endl;
        }
        if(a[i][j]!='0'+cnt)ff=0;//cout<<cnt<<':'<<(char)a[i][j]<<':'<<i<<','<<j<<endl;
      }
    }

    if(ff)cout<<"YES\n";
    else cout<<"NO\n";



    return 0;
}
