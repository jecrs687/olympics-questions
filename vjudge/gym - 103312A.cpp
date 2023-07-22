


#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>  
#include<map>
#include<string>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

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

 map<int,int> memoizeDict = map<int,int>();

int total;

//read int faster
void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
          c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

bool is_prime(int n){
    if(n < 2) return false;
    int middle = (int) n/2 + 1;
    for (int i = 0; i < middle; i++)
        if(n % i == 0) return false;
    return true;
}

int is_square(int n){
    double value = pow(n, 0.5);
    return value ==(int) value;
}


bool is_prime_or_square(int attempt){
    if (has(memoizeDict, attempt))
        return memoizeDict[attempt];
    if(is_prime(attempt)){
        return true;
    }
    if(is_square(attempt)){
        return true;
    }
    memoizeDict[attempt] = false;
    return false;
};



int recursive(int rest,int total){
    int value, numberSize, copy;
    if(rest==0){
        return total;
    }
    numberSize = pow(10, NumberOfDigits(rest) -1);
    value = rest/numberSize;
    copy = rest % numberSize;
    if (value == 0){
        return recursive(rest, total);
    }
    if (is_prime_or_square(value)){
        return recursive(copy, total+1);
    }else{
        while (!is_prime_or_square(value) && numberSize > 0){
            numberSize /= 10;
            int most_importante = copy/numberSize;
            copy = copy % numberSize;
            value = value * 10 + most_importante;
            }
        if (numberSize == 0){
            numberSize = pow(10, NumberOfDigits(rest) -1);
            copy = rest % numberSize;
            return recursive(copy, total);
            }
        else {
            copy = rest % numberSize;
            return recursive(copy, total+1);
        }
    }
}

signed main(){
    int totalNumber;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin >> total;
    // cin >> totalNumber;
    total = 2;
    totalNumber = 52;
    cout << recursive(totalNumber, 1) << endl;
}
