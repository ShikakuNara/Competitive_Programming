// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef pair <int, int> pi;
typedef vector < pi > vpi;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;
typedef std::priority_queue < int > pqi;
typedef std::priority_queue < pi > pqp;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}


int main()
{
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, d;
        cin >> n >> d;

        vll sad, arri, lec;
        vll day[100000];

        for (int i = 0; i < n; ++i)
        {
            int tsad, tday, tlec;

            cin >> tday;
            tday--;
            arri.pb(tday);

            day[tday].pb(i); //adding trainer i to day tmp

            cin >> tlec;
            lec.pb(tlec);

            cin >> tsad;
            sad.pb(tsad);
        }

        //debugging
        // for (int i = 0; i < d; ++i)
        // {
        //     cout << "day " << i << ": ";
        //     for (int k = 0; k < day[i].size(); ++k)
        //     {
        //         cout << day[i][k] << ", ";
        //     }
        //     cout << '\n';
        // }


        pqp que;
        for (int i = 0; i < d; ++i)
        {

          //adding new teachers for ith day
          for (int k = 0; k < day[i].size(); ++k)
          {

              //day[i][k] - trainer number
              pi tmp = p(sad[ day[i][k] ], day[i][k]);

              que.push(tmp);
          }

          if(!que.empty())
          {
            pi tmp = que.top(); //saddest teacher sofar
            lec[ tmp.second ]--;

            //cout << "on day " << i << ", trainer " << tmp.second << " teaches, lectures left = " << lec[ tmp.second ] << '\n';

            if (lec[ tmp.second ] == 0) {
              que.pop();
            }
          }

        }

        ll ans = 0;
        for (int i = 0; i < n; ++i)
            ans += lec[i] * sad[i];

        cout << ans << '\n';
    }

    // cout.close();
    // cin.close();

    return 0;
}
