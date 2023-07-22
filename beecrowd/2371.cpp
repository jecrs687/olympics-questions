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

using namespace std;

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

map<int, int> momoize = map<int, int>();
int m, n;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
struct Graph
{
    vector< vector<char> > graph;
    void inicialize_graph(int n, int m)
    {
        graph.resize(n);
        for (int i = 0; i < n; i++)
        {
            graph[i].resize(m);
        }
    };
    bool check(int i, int j)
    {
        bool ok = true;
        vector<ii> v;
        pair<int, int> p = make_pair(i, j);
        v.push_back(p);
        while (!v.empty())
        {
            auto values = v.back();
            v.pop_back();
            auto x = values.first, y = values.second;
            char value  = graph[x][y];
            if (value == '.')
                continue;
            if (value == '#')
                ok = false;

            graph[x][y] = '.';
            for (int k = 0; k < 4; k++)
            {

                int x1 = x + dx[k];
                int y1 = y + dy[k];

                if (x1 < 1 || y1 < 1 || x1 > n || y1 > m || graph[x1][y1] == '.')
                    continue;
                v.push_back(make_pair(x1, y1));
            }
        }
        return ok;
    };
};
int total = 0;
bool visiteds[201][201];
int arr[201][201];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    Graph values;
    values.inicialize_graph(n + 1, m + 1);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            values.graph[i][j] = s[j - 1];
        }
    }
    int total = 0;
    cin >> total;
    int ant = 0;
    while (total--)
    {
        int x, y;
        cin >> x >> y;
        if (values.graph[x][y] == '.')
            continue;
        values.graph[x][y] = '$';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (values.graph[i][j] == '$')
                if (values.check(i, j))
                    ant++;
        }
    }

    cout << ant << endl;
}