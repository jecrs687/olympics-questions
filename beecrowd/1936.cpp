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
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define vec_has(x, y) find(ALL(x), y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)
#define max_el(x) *max_element(ALL(x))
#define min_el(x) *min_element(ALL(x))
#define remove_value(x, y) \
  if (vec_has(x, y))       \
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
  int i;
  cin >> i; 
  int memo[i];
  int v=1;
  for (; v<=i; v++) {
    if (v == 1) {
      memo[v] = 1;
      continue; 
    }
    int current = memo[v-1] * v;
    if(current > i+1) break;
    memo[v] = current;

  }
  int values=0;
  for(v--; v>0; v--) {
    if (i >= memo[v]) {
      i -= memo[v];
      values++;
    }
    if(i == 0){
      break;
    }
  }
  cout << values;

}