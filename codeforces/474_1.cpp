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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    string s;cin>>s;
    int i=0;
    int a=0,b=0,c=0;
    if(s[i]!='a'){cout<<"NO\n";return 0;}
    while(i<sz(s)&&s[i]=='a')i++,a++;

    if(i==sz(s)){cout<<"NO\n";return 0;}

    if(s[i]!='b'){cout<<"NO\n";return 0;}
    while(i<sz(s)&&s[i]=='b')i++,b++;

    if(i==sz(s)){cout<<"NO\n";return 0;}

    if(s[i]!='c'){cout<<"NO\n";return 0;}
    while(i<sz(s)&&s[i]=='c')i++,c++;

    if(i!=sz(s)){cout<<"NO\n";return 0;}

    if(c!=a&&c!=b){cout<<"NO\n";return 0;}

    cout<<"YES\n";



    return 0;
}
