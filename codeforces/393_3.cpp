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

    vll p;


    for (size_t i = 0; i < n; i++) {
      ll tmp;
      cin >> tmp;
      p.pb(tmp-1);
      /* code */
    }

    ll b = 0;
    for (size_t i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      b += tmp;
      /* code */
    }
    b = b%2;

    //visited
    int arr[n];
    for (size_t i = 0; i < n; i++) {
      arr[i] = 0;
      /* code */
    }

    ll cycle = 0;

    for (size_t i = 0; i < n; i++) {
      if(arr[i] == 0)
      {
        cycle++;
        int j = i;
        do
        {
          arr[j] = 1;
          j = p[j];
        }while(j != i);
      }
    }

    if(cycle == 1)
      cycle = 0;

    if(b==1)
      b = 0;
    else
      b = 1;

    cout << cycle + b << "\n";

    // cout.close();
    // cin.close();

    return 0;
}
