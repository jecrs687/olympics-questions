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

bool check(int n, bool lastTrue, vector<ii> values, vi visiteds)
{
    bool value = lastTrue ? values[n].second:!values[n].second;
    if (visiteds[n] != -1)
                                                                                                                    return visiteds[n] == value;
    visiteds[values[n]] = value;
    return check(values[n], value, values, visiteds);
} 

signed main()
{
    optimize;
    int n;
    cin >> n;
    vi ans;
    while (n != 0)
    {
        vector<ii> values;
        int quantity = 0;
        for (int i = 0; i < n; i++)
        {
            string name;
            int x;
            string type;
            cin; cin >> x;
            cin; cin >> type;
            bool isTrue = type == "true." ? true : false;
            values.PB(ii(x - 1, isTrue));
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> visiteds = vector<int>(n, -1);
            if (check(values[i], trues[i], values, visiteds))
                quantity++;
        }
        ans.PB(quantity);
        cin >> n;
    }
    for (int i = 0; i < ans.size(); i++)
        if (ans[i] != 0)
            cout << ans[i] << endl;
        else
            cout << "Inconsistent" << endl;
}