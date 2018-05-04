#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")

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

const int MOD = 1e9+7;
const int inf = 1e9+10;

ll ans[]={1,3,15,133,2025,37851,1030367,36362925,1606008513,87656896891};
ll f[20];

void pre(){
  f[1]=1;
  repA(i,2,16)f[i]=(i*f[i-1])%MOD;
  rep(i,10)ans[i]=ans[i]%MOD;
}


const int MAX=2009;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif


    // string a="abcdefg",b="abcdefg";//,c="12";
    //
    // int c=0,p=-1;
    // do{
    //   int cnt=0;
    //   do{
    //     set<int> st;
    //     rep(i,sz(a))st.insert((a[i]+b[i]-'a'-'a')%sz(a)+1);
    //     if(sz(st)==sz(a))cnt++;
    //   }while(next_permutation(all(b)));
    //   if(cnt!=p)c++;
    //   p=cnt;
    //
    // }while(next_permutation(all(a)));
    // cout<<c<<endl;

    pre();


    int n;cin>>n;
    if(n%2==0)cout<<0<<endl;
    else cout<<(f[n]*ans[n/2])%MOD<<endl;






    return 0;
}
