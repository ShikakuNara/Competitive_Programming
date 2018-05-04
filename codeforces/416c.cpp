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
typedef pair<ll, pair<ll, ll> > ppp;
typedef vector<pp > vpp;
typedef vector<pair<ll, pair<ll, ll> > > vppp;
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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin >> n;

    vppp a;//number, (money, turn)
    for (size_t i = 0; i < n; i++) {
      ll x, y; cin >> x >> y;
      pp tmp = make_pair(y, i+1);
      ppp tmp2 = make_pair(x, tmp);
      a.pb(tmp2);
    }


    sortA(a);

    // for (size_t i = 0; i < a.size(); i++) {
    //   cout << a[i].first << " " << a[i].second.first << " " << a[i].second.second << "\n";
    //   /* code */
    // }

    ll m; cin >> m;

    vpp table;
    for (size_t i = 0; i < m; i++) {
      ll x; cin >> x;
      pp tmp = make_pair(x, i+1);
      table.pb(tmp);
    }
    sortA(table);
    // for (size_t i = 0; i < a.size(); i++) {
    //   cout << table[i].first << " " << table[i].second << "\n";
    //   /* code */
    // }

    ll creq = 0, cmon = 0;
    vpp goodguest; vpp answer;

    ll j = 0;
    for (size_t i = 0; i < table.size(); i++) {
      for (j += 0; j < n && a[j].first <= table[i].first; j++) {
        goodguest.pb(a[j].second);
      }

      if(!goodguest.empty())
      {
        sortA(goodguest);
        // cout << "i = " << i << " \n";
        // for (size_t i = 0; i < goodguest.size(); i++) {
        //   cout << goodguest[i].first << " " << goodguest[i].second << "\n";
        //   /* code */
        // }


        ll gnum = goodguest.back().second, tnum = table[i].second;
        pp tmp = make_pair(tnum, gnum);
        answer.pb(tmp);

        cmon += goodguest.back().first;
        creq++;

        goodguest.pop_back();
      }
    }

    cout << creq << " " << cmon << "\n";


    sortA(answer);
    for (size_t i = 0; i < answer.size(); i++) {
      cout << answer[i].second << " " << answer[i].first << "\n";
    }




    return 0;
}
