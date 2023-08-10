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


int maximum(int parent, int deep, vi visited, int *maxi, int *longest){
    int ans = deep; // define como a profundidade atual
    visited[parent] = 1; // marca como visitado
    for(int i = 0; i < adj[parent].size(); i++) // para cada filho
        if(!visited[adj[parent][i]]) // se não foi visitado
            ans = max(ans, maximum(adj[parent][i], deep + 1, visited, maxi, longest)); // calcula a profundidade máxima entre os filhos
    if(ans > *maxi){ // se a profundidade atual for maior que a máxima
        *maxi = ans; // atualiza a profundidade máxima
        *longest = parent; // atualiza o nó mais distante
    } 
    return ans; // retorna a profundidade máxima
}

signed main()
{
    optimize;
    int n=7, m; // n = número de nós, m = número de arestas
    // cin >> n >> m;
    adj.resize(n+1, vi()); // define o tamanho do vetor de adjacência
    adj = { 
        {},
        {4,3,2},
        {1,2,5},
        {1},
        {7,1},
        {2},
        {2},
        {4}
    }; // define as arestas da árvore (grafo não direcionado)
    
    // for(int i = 0; i < m; i++){
    //     int x, y, w;
    //     cin >> x >> y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    // }
    int maxi = 0; // profundidade máxima
    int a = 1; // nó inicial
    int b = -1; // nó mais distante do nó inicial
    int c = -1; // nó mais distante do nó b
    int maxAB = -1; // profundidade máxima entre os nós a e b
    int maxBC = -1; // profundidade máxima entre os nós b e c
    vi visiteds = vi(n+1, 0);    // vetor de visitados
    maximum(a, 0, visiteds, &maxAB, &b); // calcula a profundidade máxima entre os nós a e b
    vi visiteds2 = vi(n+1, 0);    // vetor de visitados
    maximum(b, 0, visiteds2, &maxBC, &c);// calcula a profundidade máxima entre os nós b e c
    int ans = maxBC;// profundidade máxima entre os nós b e c
    cout << maxBC << endl;// profundidade máxima entre os nós b e c
}