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
    if (vec_has(x, y))     \
    x.erase(find(ALL(x), y))
#define PB push_back
#define endl '\n'
#define INF 1e9 + 10

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef vector<char> vc;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

set<char> s;
set<char> s2;
vector<vc> v;
vector<vi> v2;
map<char, int> memoize1 = map<char, int>();
map<char, int> memoize2 = map<char, int>();

vi dx = {0, 0, 1, -1};
vi dy = {1, -1, 0, 0};

int guass(int n)
{
    n = n - 1;
    if (n == 0)
        return 0;
    return (n * (n + 1)) / 2;
}

int dfs(vector<vc> v, map<char, int> memo=map<char,int>(), int total = 0)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            char current = v[i][j];
            int count = 0;
            queue<ii> q;
            if (current == ' ')
                continue;
            q.push(make_pair(i, j));
            while (!q.empty())
            {
                ii value = q.front();
                q.pop();
                int x = value.first;
                int y = value.second;
                if (x < 0 || x >= v.size() || y < 0 || y >= v[x].size())
                    continue;
                if (v[x][y] == current)
                {
                    v[x][y] = ' ';
                    count++;

                    if (!(has(memo, current)))
                        memo[current] = 1;
                    else if (memo[current] < count){
                        total += guass(count) - guass(memo[current]);
                        memo[current] = count;
                        }

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        ii pa = make_pair(nx, ny);
                        q.push(pa);
                    }
                }
            }
        }
    }
    return total;
}
int dfs(vector<vi> v, map<int, int> memo = map<int,int>(), int total = 0)
{
    
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            int current = v[i][j];
            int count = 0;
            queue<ii> q;
            if (current == 0)
                continue;
            q.push(make_pair(i, j));
            while (!q.empty())
            {
                ii value = q.front();
                q.pop();
                int x = value.first;
                int y = value.second;
                if (x < 0 || x >= v.size() || y < 0 || y >= v[x].size())
                    continue;
                if (v[x][y] == current)
                {
                    v[x][y] = 0;
                    count++;

                    if (!(has(memo, current)))
                        memo[current] = 1;
                    else if (memo[current] < count){
                        total += guass(count) - guass(memo[current]);
                        memo[current] = count;
                        }

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        ii pa = make_pair(nx, ny);
                        q.push(pa);
                    }
                }
            }
        }
    }
    return total;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();

    int m = n;
    int lineSize = m * 2 + (m * 2);
    v.resize(n);
    v2.resize(n);
    while (n--)
    {
        string x;
        getline(cin, x);
        int s = 0;
        string temp;
        while(s<x.size()){
            char current = x[s];
            if(s == x.size()-1){
                temp.PB(current);
            }
            if(current == ' ' || s == x.size()-1){
               s++;
                if (atoi(&temp[0]) == 0){
                    v[n].PB(temp[0]);
                }
                else{
                    v2[n].PB(stoi(temp));
                }
                temp = "";

               continue;
               }
            temp.PB(current);
            s++;
            
        }

    }
    int total1 = dfs(v);
    int total2 = dfs(v2);
    cout << total1 << " " << total2
         << endl;
}