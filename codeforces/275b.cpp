#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
#endif
#ifndef LOCAL_TEST
  #include <bits/stdc++.h>
#endif

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef pair<ll, ll> pp;
typedef vector<pp > vpp;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) ll((a).size())
#define pb push_back
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll n, m, countB = 0;
ll vis[100][100], a[100][100];
int flag = 0; //a contradiction found


//no turn dfs
void dfs2(ll i, ll j, int dirx, int diry)
{
    if(flag == 1)
    {
      return;
    }
    else if(i >= n || i < 0 || j >= m || j < 0)
    {
      return;
    }
    else if(a[i][j] == 0)
    {

      return;
    }

    vis[i][j] = 1;

    //neighbours
    dfs2(i+dirx, j+diry, dirx, diry);

    return;
}

//one turn dfs
void dfs1(ll i, ll j, int dirx, int diry)
{

    if(flag == 1)
    {
      // cout << "a\n";
      return;
    }
    else if(i >= n || i < 0 || j >= m || j < 0)//outsid grid
    {
      // cout << "b\n";
      return;
    }
    else if(a[i][j] == 0)//on white cell
    {
      // cout << "c\n";
      return;
    }

    vis[i][j] = 2;

    //neighbours
    dfs1(i+dirx, j+diry, dirx, diry);

    if(dirx == 0)
    {
      dfs2(i+1, j, 1, 0);
      dfs2(i-1, j, -1, 0);
    }
    else if(diry == 0)
    {
      dfs2(i, j+1, 0, 1);
      dfs2(i, j-1, 0, -1);
    }

    return;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin >> n >> m;

    for (size_t i = 0; i < 100; i++) {
      for (size_t j = 0; j < 100; j++) {
        vis[i][j] = 0;
      }
    }

    for (size_t i = 0; i < n; i++) {
      string t; cin >> t;
      for (size_t j = 0; j < t.size(); j++) {
        if(t[j] == 'B')
        {
          a[i][j] = 1;
          countB++;
        }
        else
          a[i][j] = 0;
      }
    }

    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {

        if(flag == 1)
        {
          cout << "NO\n";
          return 0;
        }

        if(a[i][j] == 1) //check for black cell
        {
          vis[i][j] = 2;
          dfs1(i+1, j, 1, 0);
          dfs1(i, j+1, 0, 1);
          dfs1(i, j-1, 0, -1);
          dfs1(i-1, j, -1, 0);

          //check if all black visited
          ll viscnt = 0;
          for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
              if(vis[i][j] != 0)
              {
                viscnt++;
              }
            }
          }


          if(viscnt < countB)
          {
            flag = 1;
          }

          //reset visited
          for (size_t i = 0; i < 100; i++) {
            for (size_t j = 0; j < 100; j++) {
              vis[i][j] = 0;
            }
          }

        }

      }
    }


    if(flag == 0)
      cout << "YES\n";
    else
      cout << "NO\n";



    return 0;
}
