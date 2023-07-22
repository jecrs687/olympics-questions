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
#define MAX 1000000

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ll, string> is;
typedef map<int, int> mi;

typedef vector<ii> vii;
map<string, int> memoize = map<string, int>();
int maxlocal = 0;
int limit;
int n, k, maxDistance;
int maximum(int current, int value, int *values,  int *memo,  int *profits)
{
    if (current  == n)
        return value;
    if (memo[current] != -1)
        return memo[current] + value;    
    int next = current+1;
    int b =  maximum(
            next,
            value,
            values,
            memo, profits);
    if(values[current] + k > maxDistance + 10)
        return value + profits[current];
    while(next < n && values[next] - values[current] < k)
        next++;
    int a = maximum(
        next,
        value + profits[current],
        values,
        memo, profits);
    int maxi = max(a, b);
    memo[current] = maxi - value;
    return maxi;
}

signed main()
{
    optimize;

    int t;
    cin >> t;
    vi ans;
    while (t--)
    {
        cin >> n >> k;
        int values[n];
        int profits[n];
        int memo[n];
        memset(values, 0, sizeof(values));
        memset(memo, -1, sizeof(memo));
        memset(profits, 0, sizeof(profits));
        maxDistance = 0;
        for (int i = 0; i < n; i++)
            {
                cin >> values[i];
                if(values[i] > maxDistance)
                    maxDistance = values[i];    
            }
        
        for (int i = 0; i < n; i++)
            cin >> profits[i];
        
        int maxi = maximum(0, 0, values, memo, profits);
        ans.PB(maxi);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
}
