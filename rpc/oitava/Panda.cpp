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

using namespace std;

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
typedef pair<int, ii> iii;

typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;


map<int, int> memoize = map<int, int>();
vvi list;
vvii listMin;

vvi weight = {
    {1,2,3},
    {8,0,4},
    {7,6,5}
};
  int c, l, x,y,e;
int maxValue = 0;
priority_queue<int> pq;
void completeList(int a, int b, int e){
    priority_queue<iii> q;
    q.push({0, {a, b}});

    while(!q.empty())
    {
        ii current = q.top().second;
        q.pop();
        int i = current.first;
        int j = current.second;
        int value = listMin[i][j].first;
        if(listMin[i][j].second == -1)
            continue;
        if(i < 1 || j<1 || i>c || j>l )
            continue;
        for(int k = 0; k< 3; k++)
        for(int z=0; z<3; z++){
            int newI = i + k-1;
            int newJ = j + z-1;
            if(newI < 1 || newJ<1 || newI>c || newJ>l )
                continue;
            ii temp = listMin[newI][newJ];
            int newValue = min(value+weight[k][z], temp.first);
            if(newValue <= e){
                listMin[newI][newJ].first = newValue;
                listMin[newI][newJ].second = -2;

                if(temp.second != -1 && temp.second != -2)
                    q.push({-newValue, {newI, newJ}});
                else{
                    if(temp.second == -1){
                        pq.push(list[newI][newJ]);
                    }
                    if(newValue > maxValue)
                        maxValue = newValue;
                }
            }
        }

    }
}


signed main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    cin >> c >> l >> x >> y >> e;
    int max = 0;
    list.resize(c+1);
    listMin.resize(c+1);
    for(int i = 1; i <= c; i++){
        list[i].resize(l+1, 0);
        listMin[i].resize(l+1, {INF, 0});

        for(int j = 1; j <= l; j++){
            int value;
            cin >> value;

            if(value != 0){
                int difX = x-i;
                int difY = y-j;
                int absX = abs(difX);
                int absY = abs(difY);
                int dif = absX - absY;
                int line, column;

                line = difX > 0 ? 0 : difX ==0? 1: 2;
                column = difY > 0 ? 0 : difY ==0? 1: 2;

                int weightMove1 = weight[line][column] * min(absX, absY);
                int weightMove2 = weight[(dif > 0? line: 1)][(dif> 0 ?1: column)] * abs(dif);
                listMin[i][j].second = -1;
                if(weightMove1 + weightMove2 <=e)
                    list[i][j] = value;
            }
        }
    }
    listMin[x][y].first = 0;
    completeList(x,y,e);
    int response = pq.top();
    cout << response<< endl;
}