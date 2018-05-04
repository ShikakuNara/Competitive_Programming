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
typedef vector<double > vdd;
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
#define PI 3.14159265359

// Functions
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

const ll MOD = 1e9 + 7;
#define _  %  MOD
#define __ %= MOD


ll weight[100010] = {0}, cost = 0, ways = 1;
vll comp;

class Graph
{
    ll V;    // No. of vertices
    list<ll> *adj;    // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(ll v, bool visited[], stack<ll> &Stack);

    // A recursive function to prll DFS starting from v
    void DFSUtil(ll v, bool visited[]);
public:
    Graph(ll V);
    void addEdge(ll v, ll w);

    // The main function that finds and prlls strongly connected
    // components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(ll V)
{
    this->V = V;
    adj = new list<ll>[V];
}

// A recursive function to prll DFS starting from v
void Graph::DFSUtil(ll v, bool visited[])
{
    // Mark the current node as visited and prll it
    visited[v] = true;
    comp.pb(v);

    // Recur for all the vertices adjacent to this vertex
    list<ll>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (ll v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<ll>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(ll v, ll w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(ll v, bool visited[], stack<ll> &Stack)////
{
    // Mark the current node as visited and prll it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<ll>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prlls all strongly connected
// components
void Graph::printSCCs()
{
    stack<ll> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for(ll i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for(ll i = 0; i < V; i++)
        if(visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for(ll i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        ll v = Stack.top();
        Stack.pop();

        // Prll Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);

            ll min = 100000000000, mincount = 0;
            for (size_t i = 0; i < comp.size(); i++) {
              if(weight[comp[i]] < min)
              {
                min = weight[comp[i]];
              }
            }

            for (size_t i = 0; i < comp.size(); i++) {
              if(weight[comp[i]] == min)
              {
                mincount++;
              }
            }

            ways *= mincount;
            ways __;
            cost += min;
            comp.clear();
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifdef LOCAL_TEST
		  ifstream cin("in.txt"); ofstream cout("out.txt");
    #endif


    ll n; cin >> n;

    for (ll i = 1; i <= n; i++) {
      cin >> weight[i];
    }

    ll m; cin >> m;
    Graph g(n+1);

    for (ll i = 0; i < m; i++) {
      ll a, b; cin >> a >> b;
      g.addEdge(a, b);
    }

    g.printSCCs();

    cout << cost << " " << ways << '\n';

    return 0;
}
