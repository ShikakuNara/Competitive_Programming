#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int,int> pp;
typedef vector<pp > vpp;

#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b)       (make_pair(a,b) )
#define all(c)        (c).begin(),(c).end()
#define fill(a)       (memset(a,0,sizeof (a)))
#define fillA(a)       (memset(a, -1,sizeof (a)))
#define trav(a,x) for(auto& a : x)
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
const long double PI=3.141592653589793238462643383;
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
const int MAX=100009;
const int MOD=1e9+7;

//
// string T,P;
int n,m;

char T[MAX], P[MAX];
int RA[MAX], tempRA[MAX]; // rank array and temporary rank array
int SA[MAX], tempSA[MAX]; // suffix array and temporary suffix array
int c[MAX];

void countingSort(int k) {
  int sum,maxi=max(300,n);//DONT USE IF > 300 UNIQUE CHAR.
  memset(c,0,sizeof(c));

  rep(i,n)c[i+k<n?RA[i+k]:0]++;

  sum=0;
  rep(i,maxi)
  {
    int t=c[i];c[i]=sum;sum+=t;
  }

  rep(i,n)
  tempSA[c[SA[i]+k<n ? RA[SA[i]+k] : 0]++] = SA[i];

  rep(i,n)SA[i]=tempSA[i];
}

void constructSA() {
  int k,r;

  rep(i,n)RA[i] = T[i];
  rep(i,n)SA[i] = i;
  for(k=1;k<n;k<<=1)
  {
    countingSort(k);
    countingSort(0);
    tempRA[SA[0]]=r=0;

    repA(i,1,n-1)
    tempRA[SA[i]] =
    (RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;

    rep(i,n)RA[i]=tempRA[i];

    if(RA[SA[n-1]]==n-1) break;
  }
}


pp stringMatching()
{
  int lo=0,hi=n-1,mid=lo;
  while(lo<hi)
  {
    mid=(lo+hi)>>1;
    int res=strncmp(T+SA[mid],P,m);
    if (res >= 0) hi=mid;
    else lo=mid+1;
  }
  if(strncmp(T+SA[lo],P,m) != 0)return pp(-1,-1);

  pp ans; ans.first=lo;
  lo=0; hi=n-1; mid=lo;
  while(lo<hi)
  {
    mid=(lo+hi)>>1;
    int res=strncmp(T+SA[mid],P,m);
    if (res > 0) hi=mid;
    else lo=mid+1;
  }

  if(strncmp(T+SA[hi],P,m)!=0)hi--;
  ans.second=hi;
  return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    // n = (int)strlen(gets(T));
    cin>>T;n=0;
    rep(i,MAX)
    {
      if(T[i]=='\0')break; else n++;
    }
    T[n++]='$';

    constructSA();
    rep(i,n)
    {
      if(SA[i]<10)cout<<' ';
      cout<<SA[i]<<"\t"<<T+SA[i]<<endl;
    }

    while(cin>>P)//(m = (int)strlen(gets(P)), m)
    {
      m=0;
      rep(i,MAX)
      {
        if(P[i]=='\0')break; else m++;
      }

      pp pos=stringMatching();

      if(pos.first!=-1&&pos.second!=-1)
      {
        cout<<P<< " found,SA["<<pos.X<<".."<<pos.Y<<']'<<endl;
        cout<<"They are:\n";
        repA(i,pos.X,pos.Y)cout<<" "<<T+SA[i]<<endl;
      }
      else cout<<P<<" is not found in "<<T<<endl;
    }


    return 0;
}
