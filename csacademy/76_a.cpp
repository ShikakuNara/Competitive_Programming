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

const int MAX = 1009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

int a[MAX][MAX],b[MAX][MAX];
int h,w,x,y;

int find(int i,int j){
  // cout<<i<<','<<j<<endl;
  if(a[i][j]!=-1)return a[i][j];

  if((i<x&&j<w)||(j<y&&i<h))return b[i][j];
  // cout<<"a"<<endl;

  // if(i>=x&&i<h+x&&j>=y&&j<w+y)
    if(i>=h-x||j>=w-y)return b[i+x][j+y];
  // cout<<"b"<<endl;

  a[i-x][j-y]=find(i-x,j-y);
  return b[i][j]-a[i-x][j-y];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    cin>>h>>w>>x>>y;

    rep(i,h+x)rep(j,w+y)cin>>b[i][j];

    fillA(a);
    rep(i,h)rep(j,w)if(a[i][j]==-1)a[i][j]=find(i,j);

    rep(i,h){
      rep(j,w)cout<<a[i][j]<<' ';cout<<endl;
    }




    return 0;
}
