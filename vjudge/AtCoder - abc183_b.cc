#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define ALL(x) x.begin(), x.end()
#define PB push_back
#define endl '\n'

typedef long long ll;
#define int ll
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;



signed main(){
        double sx,sy,gx,gy;
        cin>>sx>>sy>>gx>>gy;
        double ans = (sy*gx + sx*gy)/(sy+gy);
        cout << fixed << setprecision(10) << ans << endl;
}