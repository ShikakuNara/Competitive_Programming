#include <bits/stdc++.h>
// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")

using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp(a,b) (make_pair((a),(b)) )
#define all(c)  (c).begin(),(c).end()
#define fill(a) (memset((a), 0, sizeof (a)))
#define fillA(a) (memset((a), -1, sizeof (a)))
#define trav(a,x) for(auto& (a):(x))
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=(a);i<=(n);++i)
#define repD(i,a,n) for(int i=(a);i>=(n);--i)
const long double PI = 3.141592653589793238462643383;
#define fst first
#define snd second
#define endl '\n'

typedef long long int ll;
typedef long double ld;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef pair<int, int> pp;
typedef vector<pp > vpp;

// clock_t tm=clock();void fin(){tm=clock()-tm;cerr<<(float)(tm)/CLOCKS_PER_SEC<<"\n";}
ll gcd(ll a,ll b){if (a==0) return b;return gcd(b%a,a);}
ll Ceil(ll a,ll b){if(a%b==0)return a/b;else return a/b+1;}

const int MAX = 131072;
const int MOD = 1e9+7;
const int inf = 1e9+10;

ld p[MAX];
ld eps=1e-6;

ld pw(ld v, int k){
  if(k==0)return 1;
  ld ans=pw(v,k/2);ans*=ans;
  if(k%2)ans*=v;
  return ans;
}

ld sum[2 * MAX], li[2 * MAX], ls[2 * MAX], umult[2 * MAX], uadd[2 * MAX], uset[2 * MAX];
int N, Q, QA, QB, QOP;
ld QUPD, QANS;

void PushSet(int node, ld v) {
	umult[node] = 1;
	uadd[node] = 0;
	uset[node] = v;
	sum[node] = pw(v,(ls[node] - li[node] + 1));//((ls[node] - li[node] + 1) * v);
}

void PushMult(int node, ld v) {
	umult[node] = ((ld) umult[node] * (ld) v);
	uadd[node] = ((ld) uadd[node] * (ld) v);
	sum[node] = sum[node] * pw(v,(ls[node] - li[node] + 1));
}

void PushAdd(int node, ld v) {
	uadd[node] += v;
	sum[node] = ((ld) sum[node] + (ld) (ls[node] - li[node] + 1) * (ld) v);
}

// This is the main function for all segment tree operations (updates and queries).
// QOP denotes the operation to be performed and [QA,QB] is the interval upon which the operation is applied.
void SegTreeOp(int node) {
  cout<<"her"<<node<<','<<QA<<","<<QB<<endl;
  cout<<li[node]<<","<<ls[node]<<endl;
	if (QA <= li[node] && ls[node] <= QB) {
    cout<<node<<','<<QA<<","<<QB<<endl;
		if (QOP == 1) PushAdd(node, QUPD);
		else if (QOP == 2) PushMult(node, QUPD);
		else if (QOP == 3) PushSet(node, QUPD);
		else {
			QANS *= sum[node];
		}
		return;
	}

	int lson = node<<1;
	int rson = lson + 1;

	if (uset[node]>-eps) {
		PushSet(lson, uset[node]);
		PushSet(rson, uset[node]);
		uset[node] = -1;
	}
	if (umult[node]>1+eps||umult[node]<1-eps) {
		PushMult(lson, umult[node]);
		PushMult(rson, umult[node]);
		umult[node] = 1;
	}
	if (uadd[node] != 0) {
		PushAdd(lson, uadd[node]);
		PushAdd(rson, uadd[node]);
		uadd[node] = 0;
	}

	if (QA <= ls[lson]) SegTreeOp(lson);
	if (QB >= li[rson]) SegTreeOp(rson);

	if (QOP <= 3) {
		sum[node] = sum[lson] * sum[rson];
	}
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
    ifstream cin("in.txt");ofstream cout("out.txt");//tm=clock();
    #endif

	for (int i = MAX; i < 2 * MAX; i++) li[i] = ls[i] = i - MAX + 1;
  for (int i = MAX - 1; i >= 1; i--) {
		int lson = i << 1;
		int rson = lson + 1;
		li[i] = li[lson];
		ls[i] = ls[rson];
	}
	memset(sum, 0, sizeof(sum));
	memset(uadd, 0, sizeof(uadd));



	// scanf("%d %d", &N, &Q);

	for (int i = 1; i < 2 * MAX; i++) {
		umult[i] = 1;
		uset[i] = -1;
	}
	// for (int i = 1; i <= N; i++) {
	// 	scanf("%d", &QUPD);
	// 	QUPD %= MOD;
	// 	QA = QB = i; QOP = 1;
	// 	SegTreeOp(1);
	// }

  QOP=3;QA=1,QB=4;QUPD=1;SegTreeOp(1);
  QOP=1;QA=1,QB=2;QUPD=2;SegTreeOp(1);

  QANS=0;
  QOP=4;QA=1,QB=2;QUPD=2;SegTreeOp(1);
  cout<<QANS<<endl;


	// while (Q--) {
	// 	scanf("%d", &QOP);
  //
	// 	if (QOP <= 3) {
	// 		scanf("%d %d %d", &QA, &QB, &QUPD);
	// 		SegTreeOp(1);
	// 	} else {
	// 		scanf("%d %d", &QA, &QB);
	// 		QANS = 0;
	// 		SegTreeOp(1);
	// 		printf("%d\n", QANS);
	// 	}
	// }

    cout<<fixed<<setprecision(12);
    int n,q;cin>>n>>q;
    rep(i,n)cin>>p[i];
    rep(i,q){
      int t,l,r;cin>>t>>l>>r;l--,r--;
      if(t==0){
        ld ans=1.0;
        repA(j,l,r)ans=ans*(1-p[j]);
        cout<<ans<<endl;
      }
      else{
        ld t;cin>>t;
        repA(j,l,r)p[j]*=t;
      }
    }



    return 0;
}
