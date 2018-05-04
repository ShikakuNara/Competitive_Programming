
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
#define all(c)        (c).begin(),(c).end()
#define tr(c,i)       for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)  ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mp(a, b)       (make_pair(a, b) )
#define sortA(v)      (sort(v.begin(), v.end()))
#define sortD(v)      (sort(v.rbegin(), v.rend())
#define fill(a)       (memset(a, 0, sizeof (a)))

#define end '\n'

//****************************************************

const ll MAX = 300000;
// Ideally, we should not use global variables and large
// constant-sized arrays, we have done it here for simplicity.

ll *a_tree = (ll *) calloc(MAX, sizeof(ll));
ll *a_lazy = (ll *) calloc(MAX, sizeof(ll));
ll *ite_tree = (ll *) calloc(MAX, sizeof(ll));
ll *ite_lazy = (ll *) calloc(MAX, sizeof(ll));

void updateRangeUtilA(ll si, ll ss, ll se, ll us,
                 ll ue, ll diff)
{

  if (a_lazy[si] != 0)
  {
      // Make pending updates using value stored in lazy
      // nodes
      a_tree[si] += (se-ss+1)*a_lazy[si];

      // checking if it is not leaf node because if
      // it is leaf node then we cannot go further
      if (ss != se)
      {
          // We can postpone updating children we don't
          // need their new values now.
          // Since we are not yet updating children of si,
          // we need to set lazy flags for the children
          a_lazy[si*2 + 1]   += a_lazy[si];
          a_lazy[si*2 + 2]   += a_lazy[si];
      }

      // Set the lazy value for current node as 0 as it
      // has been updated
      a_lazy[si] = 0;
  }

  // out of range
  if (ss>se || ss>ue || se<us)
      return ;

  // Current segment is fully in range
  if (ss>=us && se<=ue)
  {
      // Add the difference to current node
      a_tree[si] += (se-ss+1)*diff;

      // same logic for checking leaf node or not
      if (ss != se)
      {
          // This is where we store values in lazy nodes,
          // rather than updating the segment tree itelf
          // Since we don't need these updated values now
          // we postpone updates by storing values in lazy[]
          a_lazy[si*2 + 1]   += diff;
          a_lazy[si*2 + 2]   += diff;
      }
      return;
  }

  // If not completely in rang, but overlaps, recur for
  // children,
  ll mid = (ss+se)/2;
  updateRangeUtilA(si*2+1, ss, mid, us, ue, diff);
  updateRangeUtilA(si*2+2, mid+1, se, us, ue, diff);

  // And use the result of children calls to update this
  // node
  a_tree[si] = a_tree[si*2+1] + a_tree[si*2+2];
}
void updateRangeA(ll n, ll us, ll ue, ll diff)
{
  updateRangeUtilA(0, 0, n-1, us, ue, diff);
}
void updateRangeUtil_ite(ll si, ll ss, ll se, ll us,
                 ll ue, ll diff)
{

  if (ite_lazy[si] != 0)
  {
      // Make pending updates using value stored in lazy
      // nodes
      ite_tree[si] += (se-ss+1)*ite_lazy[si];

      // checking if it is not leaf node because if
      // it is leaf node then we cannot go further
      if (ss != se)
      {
          // We can postpone updating children we don't
          // need their new values now.
          // Since we are not yet updating children of si,
          // we need to set lazy flags for the children
          ite_lazy[si*2 + 1]   += ite_lazy[si];
          ite_lazy[si*2 + 2]   += ite_lazy[si];
      }

      // Set the lazy value for current node as 0 as it
      // has been updated
      ite_lazy[si] = 0;
  }

  // out of range
  if (ss>se || ss>ue || se<us)
      return ;

  // Current segment is fully in range
  if (ss>=us && se<=ue)
  {
      // Add the difference to current node
      ite_tree[si] += (se-ss+1)*diff;

      // same logic for checking leaf node or not
      if (ss != se)
      {
          // This is where we store values in lazy nodes,
          // rather than updating the segment tree itelf
          // Since we don't need these updated values now
          // we postpone updates by storing values in lazy[]
          ite_lazy[si*2 + 1]   += diff;
          ite_lazy[si*2 + 2]   += diff;
      }
      return;
  }

  // If not completely in rang, but overlaps, recur for
  // children,
  ll mid = (ss+se)/2;
  updateRangeUtil_ite(si*2+1, ss, mid, us, ue, diff);
  updateRangeUtil_ite(si*2+2, mid+1, se, us, ue, diff);

  // And use the result of children calls to update this
  // node
  ite_tree[si] = ite_tree[si*2+1] + ite_tree[si*2+2];
}
void updateRange_ite(ll n, ll us, ll ue, ll diff)
{
  updateRangeUtil_ite(0, 0, n-1, us, ue, diff);
}



ll getSumUtilA(ll ss, ll se, ll qs, ll qe, ll si)
{

  if (a_lazy[si] != 0)
  {
      // Make pending updates to this node. Note that this
      // node represents sum of elements in arr[ss..se] and
      // all these elements must be increased by lazy[si]
      a_tree[si] += (se-ss+1)*a_lazy[si];

      // checking if it is not leaf node because if
      // it is leaf node then we cannot go further
      if (ss != se)
      {
          // Since we are not yet updating children os si,
          // we need to set lazy values for the children
          a_lazy[si*2+1] += a_lazy[si];
          a_lazy[si*2+2] += a_lazy[si];
      }

      // unset the lazy value for current node as it has
      // been updated
      a_lazy[si] = 0;
  }

  // Out of range
  if (ss>se || ss>qe || se<qs)
      return 0;

  // At this poll we are sure that pending lazy updates
  // are done for current node. So we can return value
  // (same as it was for query in our previous post)

  // If this segment lies in range
  if (ss>=qs && se<=qe)
      return a_tree[si];

  // If a part of this segment overlaps with the given
  // range
  ll mid = ss + (se - ss)/2;
  return getSumUtilA(ss, mid, qs, qe, 2*si+1) +
         getSumUtilA(mid+1, se, qs, qe, 2*si+2);
}
ll getSumA(ll n, ll qs, ll qe)
{
  // Check for erroneous input values
  if (qs < 0 || qe > n-1 || qs > qe)
  {
      printf("Invalid Input");
      return -1;
  }

  return getSumUtilA(0, n-1, qs, qe, 0);
}
ll getSumUtil_ite(ll ss, ll se, ll qs, ll qe, ll si)
{

  if (ite_lazy[si] != 0)
  {
      // Make pending updates to this node. Note that this
      // node represents sum of elements in arr[ss..se] and
      // all these elements must be increased by lazy[si]
      ite_tree[si] += (se-ss+1)*ite_lazy[si];

      // checking if it is not leaf node because if
      // it is leaf node then we cannot go further
      if (ss != se)
      {
          // Since we are not yet updating children os si,
          // we need to set lazy values for the children
          ite_lazy[si*2+1] += ite_lazy[si];
          ite_lazy[si*2+2] += ite_lazy[si];
      }

      // unset the lazy value for current node as it has
      // been updated
      ite_lazy[si] = 0;
  }

  // Out of range
  if (ss>se || ss>qe || se<qs)
      return 0;

  // At this point we are sure that pending lazy updates
  // are done for current node. So we can return value
  // (same as it was for query in our previous post)

  // If this segment lies in range
  if (ss>=qs && se<=qe)
      return ite_tree[si];

  // If a part of this segment overlaps with the given
  // range
  ll mid = ss + (se - ss)/2;
  return getSumUtil_ite(ss, mid, qs, qe, 2*si+1) +
         getSumUtil_ite(mid+1, se, qs, qe, 2*si+2);
}
ll getSum_ite(ll n, ll qs, ll qe)
{
  // Check for erroneous input values
  if (qs < 0 || qe > n-1 || qs > qe)
  {
      printf("Invalid Input");
      return -1;
  }

  return getSumUtil_ite(0, n-1, qs, qe, 0);
}


void constructSTA(ll arr[], ll ss, ll se, ll si)
{

  if (ss > se)
      return ;

  if (ss == se)
  {
      a_tree[si] = arr[ss];
      return;
  }

  ll mid = (ss + se)/2;
  constructSTA(arr, ss, mid, si*2+1);
  constructSTA(arr, mid+1, se, si*2+2);

  a_tree[si] = a_tree[si*2 + 1] + a_tree[si*2 + 2];
}
void constructST_ite(ll arr[], ll ss, ll se, ll si)
{

  if (ss > se)
      return ;

  if (ss == se)
  {
      ite_tree[si] = arr[ss];
      return;
  }

  ll mid = (ss + se)/2;
  constructST_ite(arr, ss, mid, si*2+1);
  constructST_ite(arr, mid+1, se, si*2+2);

  ite_tree[si] = ite_tree[si*2 + 1] + ite_tree[si*2 + 2];
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // ifstream cin("in.txt"); ofstream cout("out.txt");

    ll n, m ,k;
    cin >> n >> m >> k;

    ll ope[3][MAX];
    ll a[MAX] = {0}, ite[MAX] = {0};

    for (ll i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (ll i = 0; i < m; i++) {
      ll tmp; cin >> tmp; tmp--;
      ope[0][i] = tmp;

      cin >> tmp; tmp--;
      ope[1][i] = tmp;

      cin >> tmp;
      ope[2][i] = tmp;
    }

    constructSTA(a, 0, n-1, 0);
    constructST_ite(ite, 0, n-1, 0);

    for (ll i = 0; i < k; i++) {
      ll x, y; cin >> x >> y;
      x--; y--;


      updateRange_ite(m, x, y, 1);
    }


    for (ll i = 0; i < m; i++) {
      if(getSum_ite(m, i, i) != 0)
        updateRangeA(n, ope[0][i], ope[1][i], ope[2][i] * getSum_ite(m, i, i));
    }


    for (ll i = 0; i < n; i++) {
      cout << getSumA(n, i, i) << " ";
    } cout << end;


    // cout.close(); cin.close();
    return 0;
}
