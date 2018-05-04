#include <bits/stdc++.h>
#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;


#define sz(a) (ll) ((a).size())
#define pb push_back
#define fill(a)       (memset(a, 0, sizeof (a)))
#define fillA(a)       (memset(a, -1, sizeof (a)))
#define rep(i,n)     for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define end '\n'

// Functions
int Ceil(int a,int b){if(a%b==0)return a/b;else return a/b+1;}
int Min(int a,int b){if(a>b)return b;return a;}
// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}


const int MAX=100009;//elements
const int MAX2=1<<20;//max xor value
const int k=320;

int n,m,q,a[MAX],pre[400]={0},arr[400][MAX2]={0},siz[400]={0},x[MAX];//400 just to be sure

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

    cin>>n>>q;m=Ceil(n,k);int sum=0;
    rep(i,n)
    {
    cin>>a[i];//sum++;
    // if(a[i]==2)break;
  }
    // cout<<sum<<end;
    rep(i,m-1)siz[i]=k;siz[m-1]=n-k*(n/k);

    pre[0]=0;
    rep(i,m)
    {
      int cur=0;
      rep(j,siz[i])cur^=a[j+i*k],arr[i][cur]++,x[i]=cur;
      pre[i+1]=cur^pre[i];//next group
    }

    rep(aaja,q)
    {
      int t;cin>>t;
      if(t==2)
      {
        int x,b,ans=0;cin>>x>>b;x--;

        rep(i,m)
        {
          if((i+1)*k-1<=x)//complete groups
          {
            ans+=arr[i][b^pre[i]];
          }
          else//incomplete groups
          {
            int tmp=0;
            rep(j,Min(siz[i],x-i*k+1))
            {
              tmp^=a[j+i*k];
              if(tmp==(b^pre[i]))ans++;
            }
          }
        }
        cout<<ans<<end;
      }
      else
      {
        int x,b,i=0,cur=0,old=0;cin>>x>>b;x--;
        //finding incomplete group
        for(;i<m;i++)if(x>=i*k&&x<(i+1)*k)break;

        // rep(j,MAX2)arr[i][j]=0;       //reset
        rep(j,siz[i])old^=a[j+i*k],arr[i][old]=0;
        a[x]=b;
        rep(j,siz[i])cur^=a[j+i*k],arr[i][cur]++;//this group
        repA(j,i+1,m-1)pre[j]^=(old^cur);//groups after

      }
    }

    // fin();
    return 0;
}
