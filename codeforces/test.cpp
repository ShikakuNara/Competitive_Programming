#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 3000;
const int MAX2 = 14;
const Int BASE = 1000000007;
const int K = 300;

const int MOD = 1000000007;

int n, k;
Int R[MAX2][MAX];
Int S[MAX2];
Int C[MAX][MAX];


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    scanf("%d %d", &n, &k);
    FOR (i,1,n+1)
        R[0][i] = 1;
    FOR (i,0,MAX2-1)
        FOR (j,1,n+1)
            for (int t = 2; j*t <= n; ++t)
            {
                R[i+1][j*t] += R[i][j];
                R[i+1][j*t] %= MOD;
            }

    // for (size_t i = 0; i < MAX2; i++) {
    //   for (size_t j = 0; j < n+1; j++) {
    //     cout << R[i][j] << " ";
    //     /* code */
    //   } cout << endl;
    //
    //   /* code */
    // }
    FOR (i,0,MAX2)
        FOR (j,0,MAX)
        {
            S[i] += R[i][j];
            S[i] %= MOD;
        }
    FOR (i,0,MAX)
        C[i][0] = 1;
    FOR (i,1,MAX)
        FOR (j,1,i+1)
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    Int res = 0;
    FOR (i,0,min(MAX2, k))
    {
        Int a = C[k-1][i];
        Int b = S[i];
        res += a*b;
        res %= MOD;
    }
    printf("%lld\n", res);

    return 0;
}
