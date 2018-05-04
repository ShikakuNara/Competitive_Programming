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


const int MAX = (1<<18) + 10;

// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree[MAX] = {0};  // To store segment tree
ll lazy[MAX] = {0};  // To store pending updates


void updateRangeUtil1(ll si, ll ss, ll se, ll us, ll ue, ll diff);
void updateRangeUtil2(ll si, ll ss, ll se, ll us, ll ue, ll diff);

/*  si -> index of current node in segment tree
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil1(ll si, ll ss, ll se, ll us, ll ue, ll diff)
{
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] = diff;
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    ll mid = (ss+se)/2;
    updateRangeUtil2(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil2(si*2+2, mid+1, se, us, ue, diff);

    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] | tree[si*2+2];
}


void updateRangeUtil2(ll si, ll ss, ll se, ll us,
                     ll ue, ll diff)
{
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] = diff;
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    ll mid = (ss+se)/2;
    updateRangeUtil1(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil1(si*2+2, mid+1, se, us, ue, diff);

    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] ^ tree[si*2+2];
}

// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange1(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil1(0, 0, n-1, us, ue, diff);
}
void updateRange2(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil2(0, 0, n-1, us, ue, diff);
}

void constructST1(ll arr[], ll ss, ll se, ll si);
void constructST2(ll arr[], ll ss, ll se, ll si);
// A recursive function that constructs Segment Tree for
//  array[ss..se]. si is index of current node in segment
// tree st.
void constructST1(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

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
    constructST2(arr, ss, mid, si*2+1);
    constructST2(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] | tree[si*2 + 2];
}
void constructST2(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

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
    constructST1(arr, ss, mid, si*2+1);
    constructST1(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] ^ tree[si*2 + 2];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n, m; cin >> n >> m;

    ll a[1<<18] = {0};

    for (ll i = 0; i < (1<<(n)); i++) {
      cin >> a[i];
    }


    if( n%2 == 1)
      constructST1(a, 0, (1<<n)-1, 0);
    else
      constructST2(a, 0, (1<<n)-1, 0);


    for (size_t i = 0; i < m; i++) {
      ll p, x; cin >> p >> x; p--;



      if( n%2 == 1)
        updateRange1( 1<<n, p, p, x);
      else
        updateRange2( 1<<n, p, p, x);

      cout << tree[0] << end;
    }

    return 0;
}
