// #include "/usr/local/include/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef stack <int>  si;
typedef stack <ll> sll;
typedef stack < pair<int, int> > sii;
typedef queue < pair<int, int> > qii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define p(a, b) ( make_pair(a, b) )

const int M = 100000;

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

    ll n;
    cin >> n;

    ll edge[M][3];

    for (size_t i = 0; i < n-1; i++) {
      cin >> edge[i][0] >> edge[i][1];
      /* code */
    }

    vll col;
    for (size_t i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      col.pb(tmp);
      /* code */
    }

    int a = -1, b = -1;

    for (size_t i = 0; (a != -2 || b != -2) && i < n-1; i++) {
      if(col[edge[i][0]-1] == col[edge[i][1]-1])
      {
          edge[i][2] = 0;
      }
      else
      {
        edge[i][2] = 1; //interesting cases

        if(a == -1)
        {
          a = edge[i][0];
          b = edge[i][1];
        }
        else
        {
          if(a != edge[i][1] && a != edge[i][0])
            a = -2;

          if(b != edge[i][1] && b != edge[i][0])
            b = -2;
        }
      }
    }

    if( a != -2)
    {
      if(a == -1)
        cout << "YES\n1\n";
      else
      cout << "YES\n" << a << "\n";
    }
    else if( b != -2)
    {
      if(b == -1)
        cout << "YES\n1\n";
      else
      cout << "YES\n" << b << "\n";
    }
    else if( a == -2 && b == -2)
      cout << "NO\n";
    //
    // cout.close();
    // cin.close();

    return 0;
}
