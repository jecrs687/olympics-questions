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
int maximum(int target, int current, int value, vector<ii> &values, vector <vi> &memo)
{
    if (target == 0) // se o peso possível a colocar na mochila naquele momento for 0, retorna o valor
        return value;
    
     if (target < 0) // se o peso possível a colocar na mochila naquele momento for negativo, retorna infinito
        return INF;
        
    if (current == limit) // se já tiver passado por todos os objetos,
        return value;

    if (memo[current][target] != -1) // se já tiver calculado esse valor, retorna ele
        return memo[current][target] + value; // se já tiver calculado esse valor, retorna ele

    int a = maximum(target - values[current].second,
                    current + 1,
                    value + values[current].first,
                    values, memo); // coloca o objeto na mochila
    int b = maximum(target,
                    current+1,
                    value,
                    values, memo); // não coloca o objeto na mochila

    int maxi = max(a, b); // pega o maior valor entre os dois
    memo[current][target] = maxi - value; // salva o valor calculado
    return maxi; // retorna o maior valor
}

signed main()
{
    optimize;
    int n = 3, c = 12; // n é a quantidade de objetos e c é o máximo que a mochila suporta
    vector<ii> values = {{100, 10}, {55, 6}, {50, 6}}; // {valor, peso}
    vector<vi> memo;
    memo.resize(n + 100, vi(c + 100, -1)); // -1 significa que não foi calculado ainda
    limit = n; // limite de objetos
    int maxi = maximum(c, 0, 0, values, memo); // c é o peso máximo que a mochila suporta
    cout << (maxi == INF? 0: maxi) << endl << endl; // se o valor for INF, significa que não foi possível colocar nada na mochila
}