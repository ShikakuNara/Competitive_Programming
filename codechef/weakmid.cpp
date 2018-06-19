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

#ifdef LOCAL_TEST
clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
#endif
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ll a[MAX];vpp v;int d[MAX];int n;

void upd(int j){
  int i=j+1;
  while(i<n&&a[i]>=a[i-1]&&d[i]==-1)d[i]=0,i++;
  i=j-1;
  while(i>=0&&a[i]>=a[i+1]&&d[i]==-1)d[i]=0,i--;
}

ll findl(int i){
  int j=i-1;
  while(j>=0)
    if(d[j]==-1||d[j]==0)return a[j];
    else j--;
  return -1000;
}
ll findr(int i){
  int j=i+1;
  while(j<n)
    if(d[j]==-1||d[j]==0)return a[j];
    else j++;
  return -1000;
}

void Set(int i){
  int j=i-1,m=1;
  while(j>=0)
    if(d[j]==-1)break;
    else if(d[j]==0)break;
    else m=max(m,d[j]+1),j--;

  j=i+1;
  while(j>=0)
    if(d[j]==-1)break;
    else if(d[j]==0)break;
    else m=max(m,d[j]+1),j++;

  d[i]=m;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t){
      cin>>n;
      fillA(d);v.clear();

      rep(i,n)cin>>a[i],v.pb(mp(a[i],i));
      // ,a[i]=(i<n/2)*(2*n-2*i)+(i>=n/2)*(2*i+1),
      // rep(i,n)cout<<a[i]<<',';cout<<endl;
      sort(all(v));
      d[0]=d[n-1]=0,upd(0),upd(n-1);

      rep(i,n){
        pp u=v[i];int j=u.snd;
        if(d[j]!=-1)continue;
        else if(j==0||j==n-1)d[j]=0,upd(j);
        else if(a[j]<findl(j)&&a[j]<findr(j))Set(j);
        else d[j]=0,upd(j);
      }
      rep(i,n)cout<<d[i]<<' ';cout<<endl;
    }






    #ifdef LOCAL_TEST
    fin();
    #endif

    return 0;
}
