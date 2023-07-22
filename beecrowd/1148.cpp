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
#define INF 1e9 + 1e9

#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)

#define PB push_back
#define endl '\n'

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

struct Graph
{
    int V;
    vector<vi> adj;
    vi dist;
    vector<vi> matrix;
    void addEdge(int u, int v, int w)
    {
        if (adj[v][u] != INF)
        {
            adj[u][v] = 0;
            adj[v][u] = 0;
        }
        else
        {
            adj[u][v] = w;
        }
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
    int dijkstra(int from, int target)
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
        return dista[target];
    }
};

int total = 0;
bool visiteds[201][201];
int arr[201][201];
int salt = 0;
struct Verify
{
    int letters;
    Graph graph;
    vii printers;
    void inicialize(int v, int y)
    {
        graph.inicialize(v + 1);
        for (int i = 0; i < y; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            graph.addEdge(a, b, c);
        }
        cin >> letters;
        // graph.floydWarshall();
        for (int i = 0; i < letters; i++)
        {
            int a, b;
            cin >> a >> b;
            printers.PB(ii(a, b));
        }
    }
    void print()
    {
        for (
            auto i : printers)
        {
            int a = i.first;
            int b = i.second;
            int minPath = graph.dijkstra(a, b);
            salt++;
            if (minPath == INF)
            {
                cout << "Nao e possivel entregar a carta" << endl;
            }
            else
            {
                cout << minPath << endl;
            }
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Verify> verify;
    int v, y;
    cin >> v >> y;
    while (!(v == 0 && y == 0))
    {
        Verify ver;
        ver.inicialize(v, y);
        verify.PB(ver);
        ver.print();
        cout << endl;
        cin >> v >> y;
    }
}