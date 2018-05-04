#include "/usr/local/include/bits/stdc++.h"
// #include <bits/stdc++.h>

/* C program for Merge Sort */
#include<stdlib.h>
#include<stdio.h>

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

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;

#define _  %  MOD
#define __ %= MOD
#define end '\n'

// Function to return gcd of a and b
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}

ll sum = 0;

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(ll A[], ll size)
{
    ll i;
    for (i=0; i < size; i++)
        printf("%lld ", A[i]);
    printf("\n");
}
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;

    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            sum += n1 - i;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ifstream cin("in.txt"); ofstream cout("out.txt");


    ll n, q; cin >> n >> q;



    ll arr[n], aa[n];
    for (size_t i = 0; i < n; i++) {
      aa[i] = i+1;
      /* code */
    }
    ll arr_size = sizeof(arr)/sizeof(arr[0]);


    for (size_t i = 0; i < q; i++) {
      ll a, b; cin >> a >> b;
      a--; b--;

      if(a != b)
      {
        ll tmp = aa[a]; aa[a] = aa[b]; aa[b] = tmp;

        for (size_t i = 0; i < n; i++) {
          arr[i] = aa[i];
          /* code */
        }

        ll tsum = sum; sum = 0;
        mergeSort(arr, 0, arr_size-1);
        //sum += tsum;
      }

      cout << sum << end;

      /* code */
    }

    // printf("Given array is \n");
    // printArray(arr, arr_size);
    //
    // mergeSort(arr+2, 0, 6 - 2);
    //
    // printf("\nSorted array is \n");
    // printArray(arr, arr_size);

    cout.close(); cin.close();
    return 0;
}
