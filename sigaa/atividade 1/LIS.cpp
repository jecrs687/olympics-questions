#include <iostream>
#include <vector>
#include <set>
#include <iterator>
using namespace std;
 
int lis(vector<int> const& a) {
    int n = a.size(); // insere o tamanho do vetor na variável n
    const int INF = 1e9; // define o valor de INF como 10^9
    vector<int> d(n+1, INF); // cria um vetor de tamanho n+1 e preenche com INF
    d[0] = -INF; // define o primeiro valor como -INF

    for (int i = 0; i < n; i++) { // percorre o vetor
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin(); // define l como o valor da posição do primeiro valor maior que a[i]
        if (d[l-1] < a[i] && a[i] < d[l]) // se o valor da posição anterior for menor que a[i] e o valor da posição atual for maior que a[i]
            d[l] = a[i]; // define o valor da posição atual como a[i]
    }

    int ans = 0; // define a resposta como 0
    for (int l = 0; l <= n; l++)  // percorre o vetor
        if (d[l] < INF) // se o valor da posição atual for menor que INF
            ans = l; // define a resposta como l
    
    return ans; // retorna a resposta
}
int main()
{
    vector<int> input = {6,2,5,1,7,4,8,3};
 
    cout << "The length of the LIS is " << lis(input);
 
    return 0;
}
