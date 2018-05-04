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
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))

#define end '\n'

string rev(string a)
{
  int l = a.length();
  string tmp (l, 42);
  for (size_t i = 0; i < l; i++) {
    tmp[i] = a[l - i - 1];
    /* code */
  }
  return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    int t; cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        string s; cin >> s;
        int len = s.length(), flag = 0;

        //substrings of size i
        for (size_t i = 1; flag == 0 && i <= len; i++) {
            string a[len - i + 1]; //array of substrings of size i
            int vis[len - i + 1]; //number of arrays matched
            fill(vis);

            //initialise all substrings
            for (size_t j = 0; j < len - i + 1; j++) {
              string tmp (s, j, i);
              a[j] = tmp;
            }

            //match substrings
            for (size_t j = 0; flag == 0 && j < len - i + 1; j++) {
              if(vis[j] == 0)
              {
                string tmp = rev(a[j]);

                int count = 0;
                for (size_t k = 0; k < len - i + 1; k++) {
                  if( tmp.compare(a[k]) == 0)
                  {
                    count++;
                    vis[k] = 1; vis[j] = 1;
                  }
                }

                if(count == 0)
                  flag = 1; //no matching substring for jth one
              }
            }
        }

        if( flag == 0)
          cout << "YES\n";
        else
          cout << "NO\n";
    }

    // cout.close(); cin.close();
    return 0;
}
