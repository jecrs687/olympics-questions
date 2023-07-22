#define MAXN 100000
int bit[MAXN];
// caixa[×] += val
void update(int x, int val) {
    while(x < MAXN) {
        bit[×] += val;
        × += (x & -x) ;
    }
}
// for (int i-1;1‹-x;i++) sum += caixa[i];
int query(int x) {
int sum = 0;
while (x > 0) {
    sum += bit[×];
    x -= (x & -x) ;
}
return sum;
}

int r, l;

query(r) - query(l - 1);