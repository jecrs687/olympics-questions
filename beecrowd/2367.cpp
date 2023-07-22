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
typedef pair<ll, ll> ii;
typedef map<int, ii> mii;
typedef vector<ii> vii;

map<int, mii> memoize;

int solve(int n, int m, vi count, vi forbid)
{
    /*
     Forbid[i] é o número de chocolates que eu tenho que tirar em i para vencer o jogo
     se forbid[i] for proibido, a posição i perde uma maneira de ganhar

     Count[i] é o número de maneiras que eu tenho de ganhar o jogo a partir da posição i
     se count[i] >= 2, a posição é estritamente vencedora (eu tenho duas jogadas possíveis que me fazem ganhar e ao máximo uma foi proibida)
     se count[i] = 1, a posição é perdedora <=> foi-se retirado forbid[i] na jogada anterior => count[i + forbid[i]]++
     se count[i] = 0, a posição é estritamente perdedora

     Note que precisamos apenas que count[n] >= 1 para que Paula ganhe, pois é a primeira jogada a ser feita
     */

    for (int i = 0; i <= n; i++)
    {

        if (!count[i])
        { // se a posição for perdedora (note que eu começo com i = 0)
            for (int j = 1; j <= m; j++)
            { // faço todas as posições seguintes aumentarem seu valor de Count
                count[i + j]++;
                forbid[i + j] = j; // colocando um valor de forbid nelas (nao fará diferença se count[i+j] >= 2)
            }
        }
        else if (count[i] == 1 && i + forbid[i] <= n)
        {                           // se eu só tenho uma maneira de ganhar a partir de i, eu posso transformá-la numa posição perdedora
            count[i + forbid[i]]++; // bloqueando forbid[i], a posição i passa a ser perdedora
            forbid[i + forbid[i]] = forbid[i];
        }
    }

    return count[n]; // se se tem alguma maneira de ganhar a partir de N, Paula ganha
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vi forbid;
    vi count;
    cin >> n >> m;
    forbid.resize(n + m + 1, 0);
    count.resize(n + m + 1, 0);
    cout << (solve(n, m, count, forbid) ? "Paula" : "Carlos") << endl;

    // while (n != 30 || m != 8)
    // {
    //     bool win1 = win(0, m, n);
    //     bool win2 = winner2(n, m);
    //     cout << n << " " << m << "   " << (win1 ? "Paula" : "Carlos") << "----" << (win2 ? "Paula" : "Carlos") << "----" << (win1 == win2 ? "" : "<-<-<-") << endl;

    //     if (n == 30)
    //     {
    //         n = 0;
    //         m++;
    //     }
    //     n++;
    //     }
    //     cout << (win(0, 3, 5) ? "Paula" : "Carlos") << "    5 3" << endl;
    //     cout << (win(0, 5, 20) ? "Paula" : "Carlos") << "   20 5" << endl;
    //     cout << (win(0, 6, 5) ? "Paula" : "Carlos") << "    5 6" << endl;
    // }
}