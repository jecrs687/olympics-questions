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
#include <algorithm>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define vec_has(x, y) find(ALL(x), y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)
#define max_el(x) *max_element(ALL(x))
#define min_el(x) *min_element(ALL(x))
#define remove_value(x, y) \
    if (vec_has(x, y))     \
    x.erase(find(ALL(x), y))
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
    vector<vi> adjInverse;

    vi dist;
    vector<vi> matrix;
    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adjInverse[v][u] = w;
    }
    void inicialize(int x)
    {
        adj.resize(x);
        adjInverse.resize(x);
        matrix.resize(x);
        V = x;
        for (int i = 0; i < x; i++)
        {
            dist.resize(x, INF);
            matrix[i].resize(x);
            adj[i].resize(x, INF);
            adjInverse[i].resize(x, INF);
        }
    }

    void floydWarshall(bool reverse = false)
    {
        vector<vi> grap = (reverse) ? adjInverse : adj;
        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                matrix[i][j] = grap[i][j];
        for (k = 0; k < V; k++)
            for (i = 0; i < V; i++)
                for (j = 0; j < V; j++)
                    matrix[i][j] = min(
                        matrix[i][j],
                        matrix[i][k] + matrix[k][j]);
    }
    vi dijkstra(int from, bool reverse = false)
    {
        vi dista(V, INF);
        dista[from] = 0;
        vector<bool> visited(V, false);
        ii p = make_pair(0, from);
        priority_queue<ii> q;
        q.push(p);
        vector<vi> grap = (reverse) ? adjInverse : adj;
        while (!q.empty())
        {
            int a = q.top().second;
            q.pop();
            if (visited[a])
                continue;
            visited[a] = true;
            for (int current = 0; current < grap[a].size(); current++)
            {
                int w = grap[a][current];
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
        cout << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == INF)
                    cout << "INF"
                         << " ";
                else
                    cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vi> adj;
    adj.resize(101);
    for (int i = 0; i < 101; i++)
    {
        adj[i].resize(101, 0);
    }
    int max = 0;
    while (m--)
    {
        int a, b;
        cin >> a >> b;

        for (int x = 0; a - x >= 0 && x <= n; x++)
        {
            for (int y = 0; b - y >= 0 && y <= n; y++)
            {
                adj[a - x][b - y] += 1;
                if (adj[a - x][b - y] > max)
                {
                    max = adj[a - x][b - y];
                }
            }
        }
    }
    cout << max << endl;
}