#include <bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define iiii pair<pair<int, int> , pair<int, int> >
#define X first
#define Y second
const int xxx = 3333333;
const int Open = 1;
const int Close = -1;
const int add = 1e6 + 1;
using namespace std;
vector<iiii> event;
ii it[4*xxx];
int n, res;

void Enter() {
    //freopen("AREA.inp", "r", stdin);
    cin >> n;
    int i, x1, y2, x2, y1;
    for(i=1; i<=n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += add; y1 += add; x2 += add; y2 += add;
        event.push_back(iiii(ii(x1, Open), ii(y1, y2)));
        event.push_back(iiii(ii(x2, Close), ii(y1, y2)));
    }
    sort(event.begin(), event.end());
}

void Upd(int k, int l, int r, int i, int j, int v) {
    if (r<=i || j<=l) return;
    if (i<=l && r<=j )
        it[k].X += v;
    else {
        int m = (l+r) >> 1;
        Upd(k << 1, l, m, i, j, v);
        Upd((k << 1) | 1, m, r, i, j, v);
    }
    if (it[k].X == 0)
        it[k].Y = it[k << 1].Y + it[(k << 1) | 1].Y;
    else it[k].Y = r - l;
}

void SweepLine() {
    int i, y1, y2, type, len, d;
    for(i=0; i<(event.size()-1); i++) {
        y1 = event[i].Y.X; y2 = event[i].Y.Y;
        type = event[i].X.Y;
        Upd(1, 0, xxx, y1, y2, type);
        len = event[i+1].X.X - event[i].X.X;
        d = it[1].Y;
        res += len * d;
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    // freopen("in" , "r", stdin );
    // freopen("out", "w", stdout);
    Enter();
    SweepLine();
    cout << res << '\n';
    return 0;
}