#ifdef LOCAL_TEST
  #include "/usr/local/include/bits/stdc++.h"
  #pragma comment(linker, "/stack:16777216")
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

const int MAX = 100010;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin >> n;
    ll a[MAX] = {0};
    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }

    sort(a, a+n);
    vll ans;

    //1 num - infinite DONE
    if(n == 1)
    {
      cout << -1 << '\n';
      return 0;
    }
    //2 num - 3 answers DONE
    else if(n == 2)
    {
      ll dif = a[1] - a[0];
      if(dif % 2 == 0)
        ans.pb(a[0] + dif/2);

      ans.pb(a[0] - dif);
      ans.pb(a[1] + dif);
    }
    else
    {
      ll dif = a[1] - a[0], flag = 1;
      for (size_t i = 2; i < n; i++) {
        if(a[i] - a[i-1] != dif)
          flag = 0;
      }

      //is an AP - 2 answers DONE
      if(flag == 1)
      {
          ans.pb(a[n-1] + dif);
          ans.pb(a[0] - dif);
      }
      //3 num - 1/0 answers DONE
      else if( n == 3)
      {
        if(a[1] - a[0] == 2*(a[2] - a[1]))
        {
          ans.pb(a[0] + (a[1] - a[0])/2 );
        }
        else if(a[2] - a[1] == 2*(a[1] - a[0]))
        {
          ans.pb(a[1] + (a[2] - a[1])/2 );
        }
        else
        {
          cout << 0 << '\n';
          return 0;
        }
      }
      //is not an ap
      else
      {
        ll difa = a[1] - a[0], difb, flag = 0, flaga = 0, flagb = 0, j;

        for (size_t i = 2; i < n; i++) {
          if(a[i] - a[i-1] != difa && flag == 0)
          {
            difb = a[i] - a[i-1];
            j = i-1;
            flag = 1;
          }
          else if(a[i] - a[i-1] != difa && flag == 1)
          {
            if(a[i] - a[i-1] != difb)
            {
              cout << 0 << '\n';
              return 0;
            }
            else
            {
              flagb = 1;
            }
          }
          else
          {
            flaga = 1;
          }
        }

          //else - no answer
          if(flaga == 1 && flagb == 1)
          {
            cout << 0 << '\n';
            return 0;
          }
          //differs in 1 position - a answer
          else if(flaga == 1 && difb == 2*difa)
          {
            ans.pb(a[j] + difa);
          }
          //differs in 1 position - a answer
          else if(flagb == 1 && difa == 2*difb)
          {
            ans.pb(a[0] + difb);
          }
          //else - no answer
          else
          {
            cout << 0 << '\n';
            return 0;
          }
      }
    }

    sortA(ans);
    ll cur = ans[0]; vll b;
    b.pb(cur);

    for (size_t i = 0; i < ans.size(); i++) {
      if(ans[i] != cur)
      {
        b.pb(ans[i]);
        cur = ans[i];
      }
    }

    cout << b.size() << '\n';
    for (size_t i = 0; i < b.size(); i++) {
      cout << b[i] << " ";
    }

    return 0;
}
