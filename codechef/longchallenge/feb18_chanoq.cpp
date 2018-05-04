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
typedef vector<pp > vp;
typedef vector<ppp > vppp;

bool comm(pp a,pp b){
  return a.snd < b.snd;
}

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 200009;
const int MAX2 = 400;
const int MOD = 1e9+7;
const int inf = 1e9+10;

vp pt,blk[MAX2];
vi ans[MAX];

void Xor(int ii,int j){
  if(ii<0||ii>=sz(pt))return;
  int i=pt[ii].snd;

  if(!ans[i].empty()&&ans[i][sz(ans[i])-1]==j)ans[i].pop_back();
  else ans[i].pb(j);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      pt.clear();
      rep(i,MAX2)blk[i].clear();
      rep(i,MAX)ans[i].clear();

      int n;cin>>n;
      rep(i,n){
        pp tmp;cin>>tmp.fst>>tmp.snd;
        blk[tmp.fst/MAX2].pb(tmp);
      }
      rep(i,MAX2)sort(all(blk[i]),comm);

      int q;cin>>q;
      rep(i,q){
        int m;cin>>m;
        rep(j,m){
          int x;cin>>x;
          pt.pb(mp(x,i));
        }
      }
      sort(all(pt));

      int x=0,y=0,cnt=-1;
      rep(i,MAX2){
        trav(it,blk[i]){
          cnt++;
          int xo=x,yo=y;
          while(x<sz(pt)&&pt[x].fst<it.fst)x++;

          if(x==sz(pt)&&pt[x-1].fst>=it.fst)x--;
          while(x<sz(pt)&&x>0&&pt[x].fst>=it.fst)x--;
          if(x<sz(pt)&&pt[x].fst<it.fst)x++;

          while(y<sz(pt)&&pt[y].fst<=it.snd)y++;

          if(y==sz(pt)&&pt[y-1].fst>it.snd)y--;
          while(y<sz(pt)&&y>0&&pt[y].fst>it.snd)y--;
          if(y<sz(pt)&&pt[y].fst<=it.snd)y++;

          if(x>xo)repA(i,xo,x-1)Xor(i,cnt);
          else if(x<xo)repA(i,x,xo-1)Xor(i,cnt);
          if(y>yo)repA(i,yo,y-1)Xor(i,cnt);
          else if(y<yo)repA(i,y,yo-1)Xor(i,cnt);
        }
      }

      rep(i,q){
        ll a=0,f=1;
        trav(it,ans[i])a+=f*(n-it),f*=-1;
        cout<<a<<endl;
      }
    }

    return 0;
}
