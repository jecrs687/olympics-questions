
#include <iostream>
// #include <bits/stdc++.h>

#include <vector>
#include <map>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define has(x, y) x.find(y) != x.end()
#define NumberOfDigits(x) (floor(log10(x)) + 1)

#define PB push_back
#define endl '\n'

typedef long long ll;
#define oldint int
#define int ll

typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

map<int, int> momoize = map<int, int>();
int n, m, xv, yv, z;
int total = 0;
int arr[201][201];
void dps(int x, int y)
{
    if (y > m || y < 1)
        return;
    if (x > n || x < 1)
        return;
    if (arr[x][y] == -1)
        return;
    arr[x][y] = -1;
    total++;

    dps(x + 1, y);
    dps(x + 1, y - 1);
    dps(x + 1, y + 1);

    dps(x - 1, y);
    dps(x - 1, y - 1);
    dps(x - 1, y + 1);

    dps(x, y + 1);
    dps(x, y - 1);
}

signed main()
{
    int d = arr[0][4];
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> xv >> yv >> z;
    int x, y;
    for (int i = 0; i < z; i++)
    {
        cin >> x >> y;
        arr[x][y] = -1;
    }
    dps(xv, yv);
    cout << total << endl;
}
