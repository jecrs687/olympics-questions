
/*
Cada elemento terá três estados e eles seguem as variáveis x, y, z, que podem ser 0, 1 ou 2.
0 significa que o elemento ainda não foi utilizado
1 significa que ele está sendo utilizado
2 significa que ele não pode mais ser utilizado

A ideia é que, para cada elemento, você pode escolher se ele será utilizado ou não. 
O objetivo do algorítmo é maximizar a quantidade de tarefas que serão realizadas.
O algorítmo segue apenas 3 regras:
1. Se o elemento x já tiver sido utilizado (2), então o algorítmo não irá acrescer o valor daquela recursão, 
pois o elemento não pode ser utilizado.
2. Se o elemento x estiver sendo utilizado (1), então o algorítmo irá acrescer o valor daquela recursão,
já que no momento, aquele item do vetor está sendo utilizado.
3. Se o elemento x não tiver sido utilizado (0), então o algorítmo irá escolher entre duas opções:
    3.1. Não utilizar o elemento x, e continuar a recursão com o próximo elemento.
    3.2. Utilizar o elemento x, e continuar a recursão com o próximo elemento, porém, 
    agora o elemento x estará sendo utilizado (1) e o que anteriormente estava sendo utilizado (1) 
    agora não poderá mais ser utilizado (2).
*/

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
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<ll, ll> ii;
typedef pair<ll, string> is;


int a;
const int N = 3e5 + 10;
int memo[N][3][3][3];
int v[N];


void resetMemo()
{
    memset(memo, -1, sizeof(memo));
}

int solve(int index, int x, int y, int z)
{
    if (index == a) return 0;

    int &inMemory = memo[index][x][y][z];
    if (inMemory != -1) return inMemory;

    int thisValue = v[index];
    int test = solve(index + 1, x, y, z);
    if (thisValue == 0)
    {
        if (y == 1) y = 2;
        if (z == 1) z = 2;
        if (x == 2) return test;
        if (x == 1) inMemory = test + 1;
        else inMemory = max(test, 1 + solve(index + 1, 1, y, z));
    }

    if (thisValue == 1)
    {
        if (x == 1) x = 2;
        if (z == 1) z = 2;
        if (y == 2) return test;
        if (y == 1) inMemory = test + 1;
        else inMemory = max(test, 1 + solve(index + 1, x, 1, z));
    }
    
    if (thisValue == 2)
    {
        if (x == 1) x = 2;
        if (y == 1) y = 2;
        if (z == 2) return test;
        if (z == 1) inMemory = test + 1;
        else inMemory = max(test, 1 + solve(index + 1, x, y, 1));
    }

    return inMemory;
}
signed main()
{

    cin >> a;

    for (int i = 0; i < a; i++)
        cin >> v[i];        
    
    resetMemo();
    int value = solve(0, 0, 0, 0);

    int ans = value;
    cout << ans << endl;
}