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

const int MAX = 109;
const int MOD = 1e9+7;
const int inf = 1e9+10;

char a[MAX][MAX];
pp pt[109];
map<char,int> mp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    for(char a='0';a<='9';a++)mp[a]=a-'0';
    for(char a='a';a<='z';a++)mp[a]=a-'a'+10;
    for(char a='A';a<='Z';a++)mp[a]=a-'A'+36;

    rep(i,1000){

      int r=0,c=0,m=-1;
      string s;getline(cin,s);c=sz(s);
      pp st;

      while(!s.empty()){
        rep(i,sz(s)){
          a[r][i]=s[i];
          if(s[i]!='.')pt[mp[s[i]]]=mp(r,i),m=max(m,mp[s[i]]);
        }
        r++;getline(cin,s);
      }
      repA(i,0,m-1){
        if(pt[i+1].snd>pt[i].snd){
          repA(j,pt[i].snd+1,pt[i+1].snd-1)
            if(a[pt[i].fst][j]=='|')a[pt[i].fst][j]='+';
            else if(a[pt[i].fst][j]=='.') a[pt[i].fst][j]='-';
        }
        else if(pt[i+1].snd<pt[i].snd){
          repD(j,pt[i].snd-1,pt[i+1].snd+1)
            if(a[pt[i].fst][j]=='|')a[pt[i].fst][j]='+';
            else if(a[pt[i].fst][j]=='.') a[pt[i].fst][j]='-';
        }
        else if(pt[i+1].fst>pt[i].fst){
          repA(j,pt[i].fst+1,pt[i+1].fst-1)
            if(a[j][pt[i].snd]=='-')a[j][pt[i].snd]='+';
            else if(a[j][pt[i].snd]=='.') a[j][pt[i].snd]='|';
        }
        else if(pt[i+1].fst<pt[i].fst){
          repD(j,pt[i].fst-1,pt[i+1].fst+1)
            if(a[j][pt[i].snd]=='-')a[j][pt[i].snd]='+';
            else if(a[j][pt[i].snd]=='.') a[j][pt[i].snd]='|';
        }
      }

      if(r&&c)if(i)cout<<endl;
      if(r&&c)rep(i,r){rep(j,c)cout<<a[i][j];cout<<endl;}
    }






    return 0;
}
