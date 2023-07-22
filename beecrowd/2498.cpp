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
map<string, int> memoize = map<string, int>();
vector<ii> values;
int maxlocal = 0;
int limit;
int maximum(int target, int current, int value, vector<ii> &values, vector <vi> &memo)
{
    if (target == 0)
    {
        return value;
    } else if (target < 0)
        return INF;
    if (current == limit)
        return value;

    if (memo[current][target] != -1)
        return memo[current][target] + value;

    int a = maximum(
                    target - values[current].first,
                    current + 1,
                    value + values[current].second,
                    values, memo);
    int b = maximum(target, current + 1, value, values, memo);

    int maxi = max(a, b);
    memo[current][target] = maxi - value;
    return maxi;
}

signed main()
{
    optimize;

    int n, c;
    cin >> n >> c;
    int i = 1;
    while (c != 0 || n != 0)
    {
        values.resize(n, ii(0, 0));
        vector<vi> memo;
        memo.resize(n + 100, vi(c + 100, -1));
        limit = n;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            values[n] = (ii(a, b));
        }
        int maxi = maximum(c, 0, 0, values, memo);
        cout << "Caso " << i << ": " << maxi << endl;
        i++;
        cin >> n >> c;
    }
}