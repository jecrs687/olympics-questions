#include <bits/stdc++.h>
#include <queue>

using namespace std;

const int inf = 1e9 + 10;

vector<pair<int, int>> adj[6]; // Para armazenar o grafo. Por que o tamanho 6 se o grafo tem 5 nós?
                               // Poderia ser de tamanho 5, mas teríamos que lidar que
                               // o nó 1 corresponde ao índice 0, o 2, ao índice 1...
                               //  Para facilitar, foi colocado o tamanho 6, assim:
                               // o nó 1 corresponde ao índice 1, o 2, ao índice 2... e o 1ª elemento do vetor, o que
                               // correspoderia ao índice 0, ficou sem nada. (um pouquinho de desperdício de espaço ;)

priority_queue<pair<int, int>> q;

array<bool, 6> processed; // tamanho 6 pq...

int dist[6]; // tamanho 6 pq...

void dijkstra(int s)
{
    for (int i = 1; i <= 5; i++)
        dist[i] = inf;
    dist[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (processed[a])
            continue;
        processed[a] = true;
        for (auto u : adj[a])
        {
            int b = u.first, w = u.second;
            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    adj[1].push_back({2, 5}); // vertice, peso
    adj[1].push_back({4, 9});
    adj[1].push_back({5, 1});
    adj[2].push_back({1, 5});
    adj[2].push_back({3, 2});
    adj[3].push_back({2, 2});
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});
    adj[4].push_back({1, 9});
    adj[4].push_back({5, 2});
    adj[5].push_back({1, 1});
    adj[5].push_back({4, 2});

    cout << "Dijkstra" << endl;
    dijkstra(1);
    for (int i = 1; i <= 5; i++)
    { // para cada nó adjacente a s
        cout << i << " " << dist[i] << endl;
    }

    cout << endl;
    return 0;
}
