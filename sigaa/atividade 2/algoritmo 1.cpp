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
#include <cmath>

using namespace std;
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define vec_has(x, y) find(ALL(x), y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)
#define max_el(x) *max_element(ALL(x))
#define min_el(x) *min_element(ALL(x))
#define remove_value(x, y) \
  if (vec_has(x, y))       \
  x.erase(find(ALL(x), y))
#define PB push_back
#define endl '\n'
#define INF 1e9 + 10

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, string> is;

typedef vector<ii> vii;
map<string, int> memoize = map<string, int>();
vector<vi> adj;

int maximum(int parent, int deep, vi visited){
    int ans = deep; // define ans como a profundidade atual
    visited[parent] = 1; // marca o nó como visitado
    for(int i = 0; i < adj[parent].size(); i++){ // para cada nó adjacente
        if(!visited[adj[parent][i]])// se o nó não foi visitado
            ans = max(ans, maximum(adj[parent][i], deep + 1, visited)); // calcula a profundidade máxima entre os filhos
    }
    return ans; // retorna a profundidade máxima
}

signed main()
{
    optimize;
    int n=7, m; // n = número de nós, m = número de arestas
    // cin >> n >> m;
    adj.resize(n+1, vi()); // redimensiona o vetor de adjacência
    adj = {
        {},
        {4,3,2},
        {1,2,5},
        {1},
        {7,1},
        {2},
        {2},
        {4}
    }; // define a árvore (grafo não direcionado)
    
    vi visiteds = vi(n+1, 0); // vetor de visitados
    // for(int i = 0; i < m; i++){
    //     int x, y;
    //     cin >> x >> y;
    //     adj[y].push_back(x);
    //     adj[x].push_back(y);
    // }
    int maxi = 0; // profundidade máxima
    for (int i = 1; i <= n; i++){ // para cada nó
        maxi = max(maxi, maximum(i, 0, visiteds)); // calcula a altura máxima
    }
    cout << maxi << endl; // imprime a altura (diâmetro) máxima
}