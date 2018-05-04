#include<bits/stdc++.h>
#define fr(i,m,n) for(i=m;i<n;i++)
#define ifr(i,m,n) for(i=m;i>n;i--)
#define ll long long
#define sc scanf
#define pf printf
#define var(x) x i=0,j=0,k=0,tmp1=0,tmp2=0,tmp3=0,tmp=0,tmp4=0,tmp5=0,flag=0,T=0,N=0,Q=0
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int> >
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define sz 10000000
using namespace std;
int prm[sz+1];

void seive_fun() {
    int i,j,k,limit;
    prm[0]=1;
    prm[1]=1;
    limit=sqrt(sz);
    for(i=2;i<=limit;i++) {
        if(prm[i]==0) {
            k=sz/i;
            for(j=2;j<=k;j++)
                prm[i*j]=1;
        }
    }
}
int main() {

  ios_base::sync_with_stdio(false); cin.tie(NULL);
  #ifdef LOCAL_TEST
    ifstream cin("in.txt"); ofstream cout("out.txt");
  #endif


    var(int);
    seive_fun();
    vector<int> vec;
    vector<int>::iterator it1,it2;

    fr(i,2,sz+1) {
        if(prm[i]==0)
            vec.pb(i);
    }
    cin >> N;

    while(N--) {
        cin >> tmp4 >> tmp5;
        tmp4 = tmp4 * 2 + 1;
        tmp5 = 2*tmp5 -1;
        it1=lower_bound(vec.begin(),vec.end(),tmp5);
        it2=upper_bound(vec.begin(),vec.end(),tmp4);
        
        tmp=it1-it2;
        cout << tmp << '\n';
    }
    return 0;
}
