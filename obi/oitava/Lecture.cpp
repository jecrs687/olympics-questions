#include <iostream>
// #include <bits/stdc++.h>

#include <vector>
#include <iomanip>
#include <map>
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

typedef vector<ll> vi;
typedef tuple<int, int, int> tiii;
typedef pair<ll, ll> ii;
typedef pair<ll, string> is;
typedef map<int, int> mii;
typedef vector<ii> vii;
vector<vi> memoize = vector<vi>(5050, vi(5050, -1));
int currentMin=INF;
int limit;
int min_pos(
    int target, 
    int current, 
    int value,
    vector<vi> &values
    ){
    if (target == 0)
       {
        if(value < currentMin)
            currentMin = value;
        return value;
    }

    if (target < 0 || current == limit || value == INF || value > currentMin)
        return INF;
    if(((limit+3) - current)*3<target) 
        return INF;
    if(memoize[current][target]!=-1)
        return memoize[current][target] + value;
    
    int firstFirst   = min_pos(target,current+1, value, values);
    int firstSecond  = min_pos(target - 1,current + 1,value + values[current][0], values);
    int secondFirst  = min_pos(target - 2,current + 1,value + values[current][1], values);
    int secondSecond = min_pos(target - 3,current + 1,value + values[current][2], values);
    int first = min(firstFirst,firstSecond);
    int second =  min(secondFirst,secondSecond);
    int response = min(first, second);
    memoize[current][target] = response != INF? response - value: INF;
    return response;
}

signed main()
{
    optimize;
    vector<vi> values = vector<vi>(5050, vi(3, INF));
    int target, list;
    cin >> target >> list;
    limit = list;
    for (int i = 0; i < list; i++)
        cin >>values[i][0] >> values[i][1] >> values[i][2];
    int value = min_pos(
        target, 0, 0, values);
    cout << value << endl;
}