#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  // #pragma comment(linker, "/stack:16777216")
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
// #define end '\n'

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

vll adj[200006];
ll subgrp[2006][2006];
ll n, vis[200006];

void dfs(ll i)
{

    vis[i] = 1;


    for (size_t j = 0; j < adj[i].size(); j++) {
      if(vis[adj[i][j]] == 0)
      {
          dfs(adj[i][j]);
      }
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    cin >> n;

    fill(vis);

    for (size_t i = 0; i < n; i++) {
      ll a; cin >> a; a--;
      if(a != -2)
        adj[i].pb(a);
    }

    for (size_t i = 0; i < n; i++) {
      dfs(i);
      //add unvisited elements to group of a, set their subgrp == 1
      for (size_t j = 0; j < n; j++) {
        if(vis[j] == 0)
        {
          subgrp[i][j] = 1;;
        }
      }
      fill(vis);
    }

    fill(vis);

    ll count = 0;
    for (ll i = 0; i < n; i++) {

      ll test[20000] = {0};
      vll t;
      t.pb(i);
      for (size_t j = 0; j < n; j++) {
        test[j] = subgrp[i][j];
        /* code */
      }

      if( vis[i] == 0)
      {
        vis[i] = 1; count++;

        for (size_t j = i+1; j < n; j++) {

          if(vis[j] == 0 && test[j] == 1)
          {
            //check reverse
            int flag = 1;
            for (size_t k = 0; k < t.size(); k++) {
              if(subgrp[j][t[k]] == 0)
                flag = 0;
              /* code */
            }

            if(flag == 1)
            {
              vis[j] = 1;
              for (size_t k = 0; k < n; k++) {
                test[k] = subgrp[j][k] & test[k];
                /* code */
              }
              t.pb(j);
            }
          }
        }


      }

    }

    cout << count << "\n";


    return 0;
}
