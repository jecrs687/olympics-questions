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
int maxlocal = 0;
int sum;
void search(int k, int sum, map<int, int> &values, vi &ans, vi &possibles)
{
    if (k == possibles.size())
    {
        ans.PB(sum);
        return;
    }
    int current = possibles[k];
    for (int i = 0; i <= values[current]; i++)
    {
        int newValue = (current * i);
        if (values[newValue] != 0 && current != newValue)
            return;
        int newSum = sum + newValue;
        ans.PB(newSum);
        search(k + 1, newSum, values, ans, possibles);
    }
}
signed main()
{
    optimize;

    int x;
    cin >> x;
    while (x--)
    {
        int total;
        cin >> total;
        int limit = total;
        map<int, int> values;

        while (total--)
        {
            int value;
            cin >> value;
            values[value]++;
        }
        int minPossible = INF;
        vi possibles;
        set<int> ans;
        int gap = 0;
        for (auto i : values)
            if (i.second >= 1)
            {
                for (int j = 1; j <= i.second; j++)
                    ans.insert(i.first * j);
            }
        int last = 0;
        for (auto i : ans)
        {
            if (i - last != 1)
                break;
            last = i;
        }
        int response = last!=1? ((last+1) + minPossible): last;
        cout << response << endl;

        
    }
}
