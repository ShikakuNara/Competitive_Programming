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
#define sortD(v)      (sort(v.rbegin(), v.rend()))
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


const int MAX = 1000001;



// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree[MAX] = {0};  // To store segment tree
ll lazy[MAX] = {0};  // To store pending updates

void updateRangeUtil(ll si, ll ss, ll se, ll us,
                     ll ue, ll diff)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si] != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        tree[si] = max(tree[si], lazy[si]);

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1]   = max(lazy[si], lazy[si*2 + 1]);
            lazy[si*2 + 2]   = max(lazy[si], lazy[si*2 + 2]);
        }

        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] = max(tree[si], diff);

        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1]   = max(diff, lazy[si*2 + 1]);
            lazy[si*2 + 2]   = max(diff, lazy[si*2 + 2]);
        }
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    ll mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    // And use the result of children calls to update this
    // node
    tree[si] = max(tree[si*2+1], tree[si*2+2]);
}
void updateRange(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}


ll getMaxUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        tree[si] = max(tree[si], lazy[si]);

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2 + 1]   = max(lazy[si], lazy[si*2 + 1]);
            lazy[si*2 + 2]   = max(lazy[si], lazy[si*2 + 2]);
        }

        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // At this poll we are sure that pending lazy updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    // If a part of this segment overlaps with the given
    // range
    ll mid = (ss + se)/2;
    return max( getMaxUtil(ss, mid, qs, qe, 2*si+1), getMaxUtil(mid+1, se, qs, qe, 2*si+2));
}
ll getMax(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getMaxUtil(0, n-1, qs, qe, 0);
}



void constructST(ll arr[], ll ss, ll se, ll si)
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
    constructST(arr, ss, mid, si*2+1);
    constructST(arr, mid+1, se, si*2+2);

    tree[si] = max(tree[si*2 + 1], tree[si*2 + 2]);
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    // ll a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //
    // constructST(a, 0, 9, 0);
    //
    // cout << getMax(10,0,5);


    ll n; cin >> n;
    ll a[n];

    for (size_t i = 0; i < n; i++) {
      cin >> a[i];
    }

    constructST(a, 0, n-1, 0);



    ll m; cin >> m;
    for (size_t i = 0; i < m; i++) {
      ll w, h; cin >> w >> h;
      w--;

      ll max = getMax(n, 0, w);
      cout << max << end;
      updateRange(n, 0, w, max + h);
    }



    return 0;
}
