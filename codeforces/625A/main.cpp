#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
using namespace std;
template<class T> inline T sqr(T x) { return x * x;  }
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define see(x) cerr << #x << ":[" << x <<"]\n"
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

using namespace std;

LL gao(LL n, LL b, LL c, LL a){
    LL ans = 0;
    while(true){
        if(n < b){
            ans += n / a;
            break;
        }
        ans += (n - b )/ (b-c);
        see((n - b )/ (b-c));
        see(n/b);
        ans += n/b;
        n -= (n/b) * b;
    }
    return ans;
}

int main(void){
    LL n;
    cin>>n;
    LL a, b, c;
    cin >> a>>b>>c;
    LL ans = 0;
    ans = max(n / a, gao(n, b, c, a));
    cout << ans << "\n";
}
