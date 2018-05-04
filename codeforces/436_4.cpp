// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

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
ll used[200009] = {0};
ll done[200009] = {0};
ll rep[200009] = {0};
ll n;

ll umax = 1;
ll fused()
{
  for (size_t i = umax; i <= n; i++) {
    if(used[i] == 0)
    {
      umax = i;
      return i;
    }
    /* code */
  }

  return -1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    cin >> n;

    vll a;
    for (size_t i = 0; i < n; i++) {
      ll tmp; cin >> tmp;
      a.pb(tmp);

      if(used[tmp] == 0)
        used[tmp] = 1;
      else
      {
        rep[tmp]++;
        done[tmp] = -1;
      }
      /* code */
    }

    ll sum = 0;
    for (size_t i = 0; i <= n; i++) {
      sum += rep[i];
      /* code */
    }

    for (size_t i = 0; i < n; i++) {
      if(rep[a[i]] > 0)
      {
        ll tmp = a[i];
        if(done[a[i]] == -1)
        {
          if(a[i] < fused())
          {
            done[a[i]] = 1;
            rep[tmp]++;
          }
          else
          {
            a[i] = fused();
            used[fused()] = 1;
          }
        }
        else
        {
          a[i] = fused();
          used[fused()] = 1;
        }

        rep[tmp]--;
      }
    }

    cout << sum << end;
    for (size_t i = 0; i < n; i++) {
      cout << a[i] << " ";
      /* code */
    }



    // cout.close(); cin.close();
    return 0;
}
