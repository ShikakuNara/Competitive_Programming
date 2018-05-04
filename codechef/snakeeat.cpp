#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector <ll> vll;
typedef vector <int> vii;

ll n;

int binarySearch(vll &l, ll k, ll start, ll end , ll max)
{
    int i;
    for(i = 0; i < n; i++)
        if(l[i] >= k)
            return i-1;
 
    return i-1;
    
    // ll mid = (start + end + 1) / 2;
    
    // if(start == end)
    // {
    //     if(l[mid] < k)
    //         if(mid > max)
    //             max = mid;
    //     return max;
    // }
    
    // if(l[mid] >= k)
    // {
    //     binarySearch(l, k, start, mid-1, max);
    // }
    // else
    // {
    //     if(mid > max)
    //         max = mid;
    //     binarySearch(l, k, mid, end , max);
    // }
}

int main()
{
    int t;
    cin >> t;
    
    for(; t > 0; t--)
    {
        ll q;
        cin >> n >> q;

        vll l;
        for (int i = 0; i < n; ++i)
        {
            ll tmp;
            cin >> tmp;
            l.push_back(tmp);
        }

        vll k;
        for (int i = 0; i < q; ++i)
        {
            ll tmp;
            cin >> tmp;
            k.push_back(tmp);
        }

        sort(l.begin(), l.end());
        
        for (int i = 0; i < q; ++i)
        {
            int spare = 1 + binarySearch(l, k[i], 0, n-1, -1);
            // cout << "spare = " << spare << "\n";
            int otherS = n - spare;
            // cout << "other s = " << otherS << "\n";
            int j = spare - 1;

            int count = 0;

            while(spare > 0 && j >= n-otherS-spare)
            {
                spare -= k[i] - l[j] + 1; //k[i] - l[j] killed
                j--;//-1
                count++;//1
            }
            if(spare < 0)
                count--; //last snake cant be killed

            cout << count + otherS << "\n";
        }
        
    }
    
    return 0;
}