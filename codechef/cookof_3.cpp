#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define trav(a, x) for(auto& a : x)
#define rep(i,n)     for(ll i=0;i<(n);++i)
#define repA(i,a,n) for(ll i=a;i<=(n);++i)
#define repD(i,a,n) for(ll i=a;i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define X first
#define Y second
#define endl '\n'

// Functions
struct Rcompare{bool operator()(pp lhs,pp rhs){return lhs.X>rhs.X;}};
struct compare{bool operator()(pp lhs,pp rhs){return lhs.X<rhs.X;}};
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll lcm(ll a,ll b){return a*(b/gcd(a,b));}
ll Abs(ll a){if(a>0)return a;return -a;}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}
double Abs(double a){if(a>0)return a;return -a;}

ll pow(ll x,ll y)
{
  if(y==0)return 1;
  ll tmp=pow(x,y/2);
  if(y%2==1)return ((tmp*tmp)*x);
  return (tmp*tmp);
}
const int MAX = 100009;
const int MOD = 1e9+7;
const int inf = 1e9+10;

// O(n) solution for finding smallest subarray with sum
// greater than x
#include <iostream>
using namespace std;

ll arr[MAX];

// Returns length of smallest subarray with sum greater than x.
// If there is no subarray with given sum, then returns n+1
ll smallestSubWithSum(ll n, ll x)
{
    ll cur=0,len=n+1;

    ll s=0,e=0;
    while(e<n)
    {
        while(cur<x&&e<n)
        {
            if(cur<=0&&x>0)s=e,cur=0;
            cur+=arr[e++];
        }
        while(s<n&&cur>=x)
        {
            if(cur>=x)len=min(len,e-s);
            cur-=arr[s];s++;
        }
    }
    return len;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    int t;cin>>t;
    rep(aa,t)
    {
      ll n,d;cin>>n>>d;

      ll pre[MAX]={0};
      vpp s;

      rep(i,n)cin>>arr[i],pre[i]=arr[i];
      repA(i,1,n)pre[i]+=pre[i-1];

      if(d<=0){
        int ff=0;
        rep(i,n)if(arr[i]>=d)ff=1;

        if(ff==1)cout<<1<<endl;
        else cout<<-1<<endl;;

        continue;
      }

      ll ans=n+5;
      s.pb(mp(0,-1));

      repA(i,0,n-1)
      {
        // cout<<pre[i]<<',';

        pp tmp=mp(pre[i]-d,inf);
        auto it=upper_bound(s.begin(),s.end(),tmp);

        if(it!=s.begin())
        {
          // cout<<"here\n";
          // cout<<"tmp:"<<tmp.X<<','<<tmp.Y<<endl;
          // cout<<"it:"<<it->X<<","<<it->Y<<endl;
          it--;
          ans=min(i-it->Y,ans);
        }

        while(!s.empty()){
          pp tt=s[sz(s)-1];
          if(tt.X<=pre[i])break;
          else s.pop_back();
        }
        s.pb(mp(pre[i],i));
      }

      if(ans<=n)cout<<ans<<endl;
      else cout<<-1<<endl;

      // cout<<endl<<endl;


      // ll res=smallestSubWithSum(n,d);
      // if(res<=n)cout<<res<<endl;
      // else cout<<-1<<endl;
    }



    return 0;
}
