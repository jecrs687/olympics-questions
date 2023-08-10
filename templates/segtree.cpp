
#define MAXN 100000

int tree[4*MAXN];
void update(int pos, int i, int j, int x, int val){
    int esq = 2*pos;
    int dir = 2*pos + 1;
    int mid = (i+j)/2;
    tree[pos] += val;
    if(i == j) return ;
    else if(x ‹= mid) update (esq, i, mid, x, val); else update(dir, mid+1, j, x, val);
}
// como chamar na main:
int x, val;
int x = update(1, 0, MAXN-1, x, val);

int query(int pos, int i, int j, int L, int r){
int esq = 2*pos;
int dir = 2*pos + 1;
int mid = (i+j)/2;
if(i > r || j < 1) return 0;
if(i >= 1 && j <= r) return tree [pos];
else{
int ans = query(esq, i, mid, 1, r);
ans += query (dir, mid+1, j, 1, r);
return ans;
}
}