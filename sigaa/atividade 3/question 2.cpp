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
typedef pair<ii, string> iis;

typedef vector<ii> vii;
map<string, int> memoize = map<string, int>();
signed main()
{
    optimize;
    int x;
    cin >> x;
    priority_queue<iis> v;
    for (int i = 0; i < x; i++)
    {
        string s;
        int a, b;
        cin >> s >> a >> b;
        v.push({{-a, b}, s});
    }
    int moment = 0;
    int points = 0;
    while (!v.empty())
    {
        auto value = v.top();
        int tempTask = -value.first.first;
        moment += tempTask;
        points += value.first.second - moment;
        cout << points << endl;
        v.pop();
    }
}