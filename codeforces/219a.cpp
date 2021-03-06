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

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    int n; cin >> n;
    string s; cin >> s;

    if(s.size() % n != 0)
    {
      cout << -1 << end;
      return 0;
    }
    else
    {
      char ch[s.size()/n];
      int count[26] = {0};

      for (size_t i = 0; i < s.size(); i++) {
        count[s[i] - 'a']++;
        /* code */
      }

      int j = 0;
      for (size_t i = 0; i < 26; i++) {
        if( count[i] % n != 0)
        {
          cout << -1 << end;
          return 0;
        }

        count[i] /= n;

        while(count[i] != 0)
        {
          ch[j] = (char)(i +'a');
          j++;
          count[i]--;
        }
      }



      for (size_t i = 0; i < n; i++) {
        for (size_t i = 0; i < s.size()/n; i++) {
          cout << ch[i];
        }
      }
    }

    #ifdef LOCAL_TEST
      cout.close(); cin.close();
    #endif
    return 0;
}
