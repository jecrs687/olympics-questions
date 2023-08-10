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
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
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
#define INF -(1e9 + 10)

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, string> is;

typedef vector<ii> vii;
int maxlocal = 0;
int limit;
void maximum( int current, int value, vector<int> &values,set<int> &list)
{
    list.insert(value); // adiciona a soma atual na lista de somas possíveis
    if (current == values.size()) // se chegou no final da lista de valores
        return; // para a recursão
    maximum(current + 1, // chama a função com o próximo valor
                    value + values[current], // soma o valor atual com o valor da posição atual
                    values, list); // passa a lista de valores e a lista de somas possíveis
    maximum(current+1, // chama a função com o próximo valor
                    value, // não soma o valor atual com o valor da posição atual
                    values, list); // passa a lista de valores e a lista de somas possíveis
  
}

signed main()
{
    optimize;
    vector<int> values = {1,3,3,5}; // lista de valores
    set<int> list;                // lista de somas possíveis
    maximum(0, 0, values, list); // função recursiva
    for (auto i : list) // printa a lista de somas possíveis
        cout << i << " "; 
}