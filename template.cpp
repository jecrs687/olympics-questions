
#include <iostream>
//#include <bits/stdc++.h>

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

map<int, int> momoize = map<int, int>();

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

int total=0;
bool visiteds[201][201];
int arr[201][201];

signed main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);


}