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

#define PB push_back
#define endl '\n'
#define INF 1e9 + 10

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

map<int, int> momoize = map<int, int>();
struct Graph
{
    int V;
    vector<vi> adj;
    vi dist;
    vector<vi> matrix;
    void addEdge(int u, int v, int w)
    {
        if (adj[u][v] < w)
            return;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    void inicialize(int x)
    {
        adj.resize(x);
        matrix.resize(x);
        for (int i = 0; i < x; i++)
        {
            V = x;
            dist.resize(x, INF);
            matrix[i].resize(x);
            adj[i].resize(x, INF);
        }
    }
    void floydWarshall()
    {
        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                matrix[i][j] = adj[i][j];
        for (k = 0; k < V; k++)
            for (i = 0; i < V; i++)
                for (j = 0; j < V; j++)
                    matrix[i][j] = min(
                        matrix[i][j],
                        matrix[i][k] + matrix[k][j]);
    }
    vi dijkstra(int from)
    {
        vi dista(V, INF);
        dista[from] = 0;
        vector<bool> visited(V, false);
        ii p = make_pair(0, from);
        priority_queue<ii> q;
        q.push(p);
        while (!q.empty())
        {
            int a = q.top().second;
            q.pop();
            if (visited[a])
                continue;
            visited[a] = true;
            for (int current = 0; current < adj[a].size(); current++)
            {
                int w = adj[a][current];
                int b = dista[current];
                if (dista[a] + w < b)
                {
                    dista[current] = dista[a] + w;
                    p = make_pair(-dista[current], current);
                    q.push(p);
                }
            }
        }
        return dista;
    }

    void printMatrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == INF)
                    printf("%4s", "INF");
                else
                    printf("%4d", matrix[i][j]);
            }
            printf("\n");
        }
    }
};
// read int faster
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph graph;
    int n, m;
    cin >> n >> m;
    graph.inicialize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u - 1, v - 1, w);
    }
    int initial;
    cin >> initial;
    vi dist = graph.dijkstra(initial - 1);
    int min = INF, max = -INF;
    for (auto x : dist)
    {
        if (!(x == INF || x == 0))
        {
            if (min > x)
                min = x;

            if (max < x)
                max = x;
        }
    }
    cout << max - min << endl;
}