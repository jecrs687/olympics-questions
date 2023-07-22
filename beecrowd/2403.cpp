#include <iostream>
// #include <bits/stdc++.h>

#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define vec_has(x, y) find(ALL(x), y) != x.end()
#define remove_value(x, y) \
    if (vec_has(x, y))     \
    x.erase(find(ALL(x), y))
#define PB push_back
#define endl '\n'

typedef long long ll;

struct Queue
{
    priority_queue<int> q;
    void push(int x)
    {
        q.push(x);
    }
    int pop()
    {
        int x = q.top();
        q.pop();
        return x;
    }
    bool empty()
    {
        return q.empty();
    }
};

struct Graph
{
    int deep;
    vector<int> adj;
};

signed
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<Graph> queues = vector<Graph>(n);

    Queue q;
    vector<int> answer;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        queues[a].adj.PB(b);
        queues[b].deep++;
    }
    for (int i = 0; i < n; i++)
        if (queues[i].deep == 0)
            q.push(-i);

    while (!q.empty())
    {
        int x = -q.pop();
        answer.PB(x);
        for (int i = 0; i < queues[x].adj.size(); i++)
        {
            int y = queues[x].adj[i];
            queues[y].deep--;
            if (queues[y].deep == 0)
                q.push(-y);
        }
    }
    if (answer.size() != n)
        cout << "*" << endl;
    else
        for (int i = 0; i < answer.size(); i++)
            cout << answer[i] << endl;
}