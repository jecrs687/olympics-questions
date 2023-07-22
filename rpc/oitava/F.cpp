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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> x;
  priority_queue<is> pq;

  for(int i = 0; i < x; i++){
    string a;
    cin >> a;
    memoize[a]++;
  }
  for(auto i : memoize){
    pq.push({-i.second, i.first});
  }
  int valueToWin =x/2 %2 == 0?  x/2 + 1: ceil(x/2);
  vector<string> ans;
  int sum= 0;
  int last = 1;
  while(!pq.empty()){

    auto i = pq.top();
    pq.pop();
    sum += -i.first;
    
    if(i.first == last){
        ans.push_back(i.second);
      continue;
    }
    last = i.first;
    if(sum>= valueToWin){
      break;
    }
    ans.push_back(i.second);

  }

  sort(ALL(ans));
    cout << ans.size()<< endl;
    for(auto i : ans){
        cout << i << endl;
    }
}