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


int printInOrder(int parent, vi visited){
    visited[parent] = 1; // marca como visitado
    vi aux; // vetor auxiliar
    for(int i = 0; i < adj[parent].size(); i++) // para cada nó adjacente
        if(!visited[adj[parent][i]]) // se o nó não foi visitado
            aux.push_back(adj[parent][i]); // adiciona o nó no vetor auxiliar
    if(aux.size()>0) printInOrder(aux[0], visited); // se existir um nó na posição 0(esquerda) do vetor auxiliar, chama a função recursivamente
    cout << parent << " "; // imprime o nó atual
    if(aux.size()>1) printInOrder(aux[1], visited); // se existir um nó na posição 1(direita) do vetor auxiliar, chama a função recursivamente
}
int printPreOrder(int parent, vi visited){
    visited[parent] = 1; // marca como visitado
    vi aux; // vetor auxiliar
    for(int i = 0; i < adj[parent].size(); i++) // para cada nó adjacente
        if(!visited[adj[parent][i]]) // se o nó não foi visitado
            aux.push_back(adj[parent][i]); // adiciona o nó no vetor auxiliar
    cout << parent << " "; // imprime o nó atual
    if(aux.size()>0) printPreOrder(aux[0], visited); // se existir um nó na posição 0(esquerda) do vetor auxiliar, chama a função recursivamente
    if(aux.size()>1) printPreOrder(aux[1], visited); // se existir um nó na posição 1(direita) do vetor auxiliar, chama a função recursivamente
}
int printPosOrder(int parent, vi visited){
    visited[parent] = 1; // marca como visitado
    vi aux; // vetor auxiliar
    for(int i = 0; i < adj[parent].size(); i++) // para cada nó adjacente
        if(!visited[adj[parent][i]]) // se o nó não foi visitado
            aux.push_back(adj[parent][i]); // adiciona o nó no vetor auxiliar
    if(aux.size()>0) printPosOrder(aux[0], visited); // se existir um nó na posição 0(esquerda) do vetor auxiliar, chama a função recursivamente
    if(aux.size()>1) printPosOrder(aux[1], visited); // se existir um nó na posição 1(direita) do vetor auxiliar, chama a função recursivamente
    cout << parent << " "; // imprime o nó atual
}
signed main()
{
    optimize;
    int n=7, m;  // n = número de nós, m = número de arestas
    // cin >> n >> m; 
    adj.resize(n+1, vi()); // redimensiona a árvore
    adj = { 
        {},
        {4,3,2},
        {1,2,5},
        {1},
        {7,1},
        {2},
        {2},
        {4}
    }; // árvore
    
    // for(int i = 0; i < m; i++){
    //     int x, y;
    //     cin >> x >> y;
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    // }

    vi visiteds = vi(n+1, 0); // vetor de visitados
    printInOrder(4, visiteds); // printa a travessia em ordem
    cout << endl; // pula uma linha
    visiteds = vi(n+1, 0); // zera o vetor de visitados
    printPreOrder(4, visiteds); // printa a travessia em pré-ordem
    cout << endl;  // pula uma linha
    visiteds = vi(n+1, 0); // zera o vetor de visitados
    printPosOrder(4, visiteds);// printa a travessia em pós-ordem
    cout << endl;// pula uma linha
    return 0;
}