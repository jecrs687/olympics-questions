//https://xtecna.gitbook.io/solucoes-da-beecrowd/paradigmas/2243-isosceles

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
#define INF 1e9 + 10

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, string> is;

typedef vector<ii> vii;
map<string, int> memoize = map<string, int>();
signed main(){
    int N, resposta;
    int colunas[50001], esquerda[50001], direita[50001];

    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> colunas[i];
    }

    esquerda[0] = 1;
    for(int i = 1; i < N; ++i){
        esquerda[i] = min(colunas[i], esquerda[i - 1] + 1);
    }

    direita[N - 1] = 1;
    for(int i = N - 2; i > -1; --i){
        direita[i] = min(colunas[i], direita[i + 1] + 1);
    }

    resposta = 0;
    for(int i = 0; i < N; ++i){
        resposta = max(resposta, min(esquerda[i], direita[i]));
    }

    cout << resposta << endl;

    return 0;
}