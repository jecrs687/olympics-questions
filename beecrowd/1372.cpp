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
int maxlocal = 0;
int limit;
int maximum(int target, int current, int value, vi &values, vi &memo)
{
   if(current >=  target)
        return value;
    if(memo[current] != -1)
        return memo[current] + value;
    int a = maximum(
                    target,
                    current + 2,
                    value + values[current],
                    values, memo);
    int b = maximum(target, current + 1, value, values, memo);

    int maxi =  max(a, b);
    memo[current] = maxi - value;
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
        vector<vi> values=vector<vi>(n+10, vi(c+10, -1));
        limit = n;
        for (int j = 0; j < n; j++)
        {
            for(int i = 0; i < c; i++)
            {
                int x; 
                cin >> x;
                values[j][i] = x;
            }
        }
        vi ans;
        for (int i = 0; i < n; i++)
        {
            vi memo = vi(c + 10, -1);
            int x = maximum(c, 0, 0, values[i], memo);
            ans.PB(x);
        }
        vi memo = vi(n + 10, -1);
        int tot = maximum(n, 0, 0, ans, memo);

        cout<< tot << endl;
        cin >> n >> c;
    }
}