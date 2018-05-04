#include <bits/stdc++.h>

#ifdef LOCAL_TEST
  #pragma comment(linker, "/stack:16777216")
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

#define sz(a) (ll) ((a).size())
#define pb push_back
#define mp(a, b)       (make_pair(a, b) )
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend()))
#define fill(a)       (memset(a, 0, sizeof (a)))
#define end '\n'
#define PI 3.14159265

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}
ll abs(ll a, ll b){
  if( a > b)
    return a-b;

  return b-a;
}
double abs(double a, double b){
  if( a > b)
    return a-b;

  return b-a;
}

const int MAX = 400009;
ll tree[MAX] = {0};  // To store segment tree

ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 10000000000;

    // At this poll we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    // If a part of this segment overlaps with the given
    // range
    ll mid = (ss + se)/2;
    return min(getSumUtil(ss, mid, qs, qe, 2*si+1),
           getSumUtil(mid+1, se, qs, qe, 2*si+2));
}

// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -10000000000;
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructST(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return;

    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    // If there are more than one elements, then recur
    // for left and right subtrees and store the sum
    // of values in this node
    ll mid = (ss + se)/2;
    constructST(arr, ss, mid, si*2+1);
    constructST(arr, mid+1, se, si*2+2);

    tree[si] = min(tree[si*2 + 1], tree[si*2 + 2]);
}


// int main()
// {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
//     ifstream cin("in.txt"); ofstream cout("out.txt");
//
//     ll a[] = {1, 2, 3, 4, 5};
//     buildtree(a, 5);
//
//     for (size_t i = 0; i < 2*5; i++) {
//       cout << tree[i] << " ";
//       /* code */
//     }
//     update(1, 1, 5, 5);
//     cout << end << getSum(0, 2, 5) << end;
//
//     cout.close(); cin.close();
//     return 0;
// }


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n, k; cin >> n >> k;

    ll a[MAX];


    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
      /* code */
    }

    if(k == 1)
    {
      ll MMM = 10000000000;

      for (size_t i = 0; i < n; i++) {
        if(a[i] < MMM)
        {
          MMM = a[i];
        }
        /* code */
      }

      cout << MMM  << end;
    }
    else if(k == 2)
    {
      ll MMM = -10000000000, i, maxi = -1;

      for ( i = 0; i < n; i++) {
        if(a[i] > MMM)
        {
          MMM = a[i];
          maxi = i;
        }
      }

      if(maxi == n-1 || maxi == 0)
      {
        cout << MMM << end;
      }
      else
      {
        constructST(a, 0, n-1, 0);

        ll MM = -10000000000;

        for (size_t i = 0; i < n-1; i++) {

          ll tmp = max(getSum(n, 0, i-1), getSum(n, i, n-1));

          if(tmp > MM)
          {
            // cout << i << end;
            MM = tmp;
          }
        }

        cout << MM << end;
      }
    }
    else
    {
      ll MM = -10000000000;

      for (size_t i = 0; i < n; i++) {
        if(a[i] > MM)
        {
          MM = a[i];
        }
        /* code */
      }

      cout << MM  << end;
    }



    return 0;
}
