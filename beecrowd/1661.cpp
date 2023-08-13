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
signed main()
{
    optimize;
    int n;
    cin >> n;

    while(n!=0){
    vi values;
    vi positiv;
    vi negativ;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a>=0){
           positiv.PB(i);
           values.PB(a);
        }
        else{
            negativ.PB(i);
            values.PB(-a);
        }  
    }
    int lastPositive = 0;
    int diferenceTotal = 0;
    for (int i = 0; i < negativ.size(); i++)
    {
        int negative = values[negativ[i]];
        int positive = values[positiv[lastPositive]];
        int positionDiference = abs(negativ[i] - positiv[lastPositive]);
        int diference = min(negative, positive)*positionDiference;
        diferenceTotal += diference;

        if(negative < positive){
            values[positiv[lastPositive]] -= negative;
            values[negativ[i]] = 0;
        }else if(negative == positive){
            values[positiv[lastPositive]] = 0;
            values[negativ[i]] = 0;
            lastPositive++;
        }
        else{
            values[negativ[i]] -= positive;
            values[positiv[lastPositive]] = 0;
            lastPositive++;
            i--;
        }
    }
    cout << diferenceTotal << endl;
    cin >> n;
    }

}