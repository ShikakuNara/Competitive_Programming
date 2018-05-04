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

const int MAX = 1000001;

// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree1[MAX] = {0};  // To store segment tree1
ll lazy1[MAX] = {0};  // To store pending updates

/*  si -> index of current node in segment tree1
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil(ll si, ll ss, ll se, ll us,
                     ll ue, ll diff)
{
    // If lazy1 value is non-zero for current node of segment
    // tree1, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy1[si] != 0)
    {
        // Make pending updates using value stored in lazy1
        // nodes
        tree1[si] += (se-ss+1)*lazy1[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy1 flags for the children
            lazy1[si*2 + 1]   += lazy1[si];
            lazy1[si*2 + 2]   += lazy1[si];
        }

        // Set the lazy1 value for current node as 0 as it
        // has been updated
        lazy1[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree1[si] += (se-ss+1)*diff;

        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy1 nodes,
            // rather than updating the segment tree1 itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy1[]
            lazy1[si*2 + 1]   += diff;
            lazy1[si*2 + 2]   += diff;
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
    tree1[si] = tree1[si*2+1] + tree1[si*2+2];
}

// Function to update a range of values in segment
// tree1
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}


/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree1.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree1[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    // If lazy1 flag is set for current node of segment tree1,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy1[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy1[si]
        tree1[si] += (se-ss+1)*lazy1[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy1 values for the children
            lazy1[si*2+1] += lazy1[si];
            lazy1[si*2+2] += lazy1[si];
        }

        // unset the lazy1 value for current node as it has
        // been updated
        lazy1[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // At this poll we are sure that pending lazy1 updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree1[si];

    // If a part of this segment overlaps with the given
    // range
    ll mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment tree1 for
//  array[ss..se]. si is index of current node in segment
// tree1 st.
void constructST(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

    // If there is one element in array, store it in
    // current node of segment tree1 and return
    if (ss == se)
    {
        tree1[si] = arr[ss];
        return;
    }

    // If there are more than one elements, then recur
    // for left and right subtree1s and store the sum
    // of values in this node
    ll mid = (ss + se)/2;
    constructST(arr, ss, mid, si*2+1);
    constructST(arr, mid+1, se, si*2+2);

    tree1[si] = tree1[si*2 + 1] + tree1[si*2 + 2];
}


// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.
ll tree2[MAX] = {0};  // To store segment tree2
ll lazy2[MAX] = {0};  // To store pending updates

/*  si -> index of current node in segment tree2
    ss and se -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
void updateRangeUtil2(ll si, ll ss, ll se, ll us,
                     ll ue, ll diff)
{
    // If lazy2 value is non-zero for current node of segment
    // tree2, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy2[si] != 0)
    {
        // Make pending updates using value stored in lazy2
        // nodes
        tree2[si] += (se-ss+1)*lazy2[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy2 flags for the children
            lazy2[si*2 + 1]   += lazy2[si];
            lazy2[si*2 + 2]   += lazy2[si];
        }

        // Set the lazy2 value for current node as 0 as it
        // has been updated
        lazy2[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree2[si] += (se-ss+1)*diff;

        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy2 nodes,
            // rather than updating the segment tree2 itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy2[]
            lazy2[si*2 + 1]   += diff;
            lazy2[si*2 + 2]   += diff;
        }
        return;
    }

    // If not completely in rang, but overlaps, recur for
    // children,
    ll mid = (ss+se)/2;
    updateRangeUtil2(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil2(si*2+2, mid+1, se, us, ue, diff);

    // And use the result of children calls to update this
    // node
    tree2[si] = tree2[si*2+1] + tree2[si*2+2];
}

// Function to update a range of values in segment
// tree2
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange2(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil2(0, 0, n-1, us, ue, diff);
}


/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree2.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree2[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
ll getSumUtil2(ll ss, ll se, ll qs, ll qe, ll si)
{
    // If lazy2 flag is set for current node of segment tree2,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy2[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy2[si]
        tree2[si] += (se-ss+1)*lazy2[si];

        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy2 values for the children
            lazy2[si*2+1] += lazy2[si];
            lazy2[si*2+2] += lazy2[si];
        }

        // unset the lazy2 value for current node as it has
        // been updated
        lazy2[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // At this poll we are sure that pending lazy2 updates
    // are done for current node. So we can return value
    // (same as it was for query in our previous post)

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree2[si];

    // If a part of this segment overlaps with the given
    // range
    ll mid = (ss + se)/2;
    return getSumUtil2(ss, mid, qs, qe, 2*si+1) +
           getSumUtil2(mid+1, se, qs, qe, 2*si+2);
}

// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum2(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return getSumUtil2(0, n-1, qs, qe, 0);
}

// A recursive function that constructs Segment tree2 for
//  array[ss..se]. si is index of current node in segment
// tree2 st.
void constructST2(ll arr[], ll ss, ll se, ll si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

    // If there is one element in array, store it in
    // current node of segment tree2 and return
    if (ss == se)
    {
        tree2[si] = arr[ss];
        return;
    }

    // If there are more than one elements, then recur
    // for left and right subtree2s and store the sum
    // of values in this node
    ll mid = (ss + se)/2;
    constructST2(arr, ss, mid, si*2+1);
    constructST2(arr, mid+1, se, si*2+2);

    tree2[si] = tree2[si*2 + 1] + tree2[si*2 + 2];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif

    ll n; cin >> n;
    ll v[n], u[n];

    for (size_t i = 0; i < n; i++) {
      cin >> v[i];
      u[i] = v[i];
    }

    sort(u, u+n);

    constructST(v, 0, n-1, 0);
    constructST2(u, 0, n-1, 0);

    ll m; cin >> m; int type = 0;
    for (size_t i = 0; i < m; i++) {
      cin >> type; ll l, r;
      if(type == 1)
      {
        cin >> l >> r; l--; r--;
        cout << getSum(n, l, r) << end;
      }
      else
      {
        cin >> l >> r; l--; r--;
        cout << getSum2(n, l, r) << end;
      }
    }


    return 0;
}
