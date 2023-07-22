
#include <iostream>
// #include <bits/stdc++.h>

#include <vector>
#include <iomanip>
#include <cstring>
#include <map>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)
#define INF 1e9 + 10
#define PB push_back
#define endl '\n'

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

priority_queue<ii> q;

vector<int> dist;
struct graphStructure
{
    vector<vi> graph;
    vb graph2;
    void inicialize_graph(int n, int m)
    {
        graph.resize(n);
        graph2.resize(n, false);
        for (int i = 0; i < n; i++)
        {
            graph[i].resize(m, INF);
        }
    }
    bool verify(int x)
    {
        if (graph2[x])
            return true;
        graph2[x] = true;
        return false;
    }
    void verifyReset(int x = 100)
    {
        graph2.resize(x, false);
    }
};

void dijkstra(int s, graphStructure adj)
{
    dist[s] = 0;
    ii p = make_pair(0, s);
    q.push(p);
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (adj.verify(a))
            continue;
        for (int current = 0; current < adj.graph[a].size(); current++)
        {
            int w = adj.graph[a][current];
            int b = dist[current];
            if (dist[a] + w < b)
            {
                dist[current] = dist[a] + w;
                p = make_pair(-dist[current], current);
                q.push(p);
            }
        }
    }
}
int total = 0;
int arr[201][201];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graphStructure graph;
    int total;
    int nV;
    cin >> nV >> total;
    graph.inicialize_graph(nV, nV);
    while (total--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph.graph[a][b] != INF)
        {
            if (graph.graph[a][b] > c)
            {
                graph.graph[a][b] = c;
                graph.graph[b][a] = c;
            }
        }
        else
        {
            graph.graph[a][b] = c;
            graph.graph[b][a] = c;
        }
    }
    int size = nV;
    int minGeral = INF;
    dist.resize(100, INF);

    while (size--)
    {
        for (int i = 0; i < nV; i++)
            dist[i] = INF;
        graph.verifyReset();
        auto values = dist;

        dijkstra(size, graph);
        values = dist;
        int min = 0;
        for (int i = 0; i < nV; i++)
            if (dist[i] > min)
                min = dist[i];

        if (min < minGeral)
        {
            minGeral = min;
        }
    }
    cout << minGeral << endl;
    return 0;
}