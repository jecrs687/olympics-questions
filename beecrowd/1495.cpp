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
signed main()
{
    optimize;
    int n, g;
    vi ans; 
    while (cin >> n >> g)
    {
        int sum = 0;
        priority_queue<int> pq;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            if (a > b)
            {
                sum += 3;
                continue;
            }
            else if (a == b)
            {
                if(g > 0){
                    sum += 3;
                    g--;
                    continue;
                }
                if(g == 0){
                    sum++;
                    continue;
                }
            }
            pq.push(a-b);
        }
        while (!pq.empty())
        {   
            int value = -pq.top();
            pq.pop();
            if(g < value)
                break;
            if (g == value)
                {sum++; break;}
            sum += 3;
            g -= value+1;
        }
        ans.PB(sum);
    }
    for(auto x: ans)
        cout << x << endl;
}