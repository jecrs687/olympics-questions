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
void resetMemo(int n)
{
    memset(memo, -1, sizeof(memo));
}

int solve(int index, int x, int y, int z)
{
    if (index == a) return 0;

    int &inMemory = memo[index][x][y][z];
    if (inMemory != -1) return inMemory;

    int thisValue = v[index];
    int test1 = solve(index + 1, x, y, z);
    if (thisValue == 0)
    {
        if (y == 1) y = 2;
        if (z == 1) z = 2;
        if (x == 2) return test1;
        if (x == 1) inMemory = test1 + 1;
        else inMemory = max(test1, 1 + solve(index + 1, 1, y, z));
    }
    if (thisValue == 1)
    {
        if (x == 1) x = 2;
        if (z == 1) z = 2;
        if (y == 2) return test1;
        if (y == 1) inMemory = test1 + 1;
        else inMemory = max(test1, 1 + solve(index + 1, x, 1, z));
    }
    if (thisValue == 2)
    {
        if (x == 1) x = 2;
        if (y == 1) y = 2;
        if (z == 2) return test1;
        if (z == 1) inMemory = test1 + 1;
        else inMemory = max(test1, 1 + solve(index + 1, x, y, 1));
    }

    return inMemory;
}
signed main()
{

    cin >> a;

    for (int i = 0; i < a; i++)
        cin >> v[i];        
    
    resetMemo(a);
    int value = solve(0, 0, 0, 0);

    int ans = value;
    cout << ans << endl;
}