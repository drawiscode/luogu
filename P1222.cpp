#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <functional>

using namespace std;

struct Node {
    double l, r;
};
struct Event {
    double x;
    double y1, y2;
    int type;
    bool operator<(Event const& other) const {
        return x < other.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Event> ev;
    vector<double> ys;

    ev.reserve(2*n);
    ys.reserve(2*n);

    for (int i = 0; i < n; i++) {
        long long x, y, m;
        cin >> x >> y >> m;

        double U1 = x + y;
        double U2 = x + y + 2.0 * m;
        double V1 = x - y - m;
        double V2 = x - y + m;

        ev.push_back({U1, V1, V2, +1});
        ev.push_back({U2, V1, V2, -1});

        ys.push_back(V1);
        ys.push_back(V2);
    }

    sort(ev.begin(), ev.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int m = ys.size()-1;

    vector<double> cover(m*4,0);
    vector<int> cnt(m*4,0);

    function<void(int,int,int,double,double,int)> upd =
    [&](int idx, int l, int r, double ql, double qr, int type) {
        if (ys[r] <= ql || ys[l] >= qr) return;
        if (ql <= ys[l] && ys[r] <= qr) {
            cnt[idx] += type;
        } else {
            int mid = (l+r)/2;
            upd(idx*2, l, mid, ql, qr, type);
            upd(idx*2+1, mid, r, ql, qr, type);
        }
        if (cnt[idx] > 0) cover[idx] = ys[r] - ys[l];
        else if (l+1 == r) cover[idx] = 0;
        else cover[idx] = cover[idx*2] + cover[idx*2+1];
    };

    double area = 0;
    for (int i = 0; i+1 < ev.size(); i++) {
        upd(1, 0, m, ev[i].y1, ev[i].y2, ev[i].type);
        double dx = ev[i+1].x - ev[i].x;
        area += cover[1] * dx;
    }

    cout << fixed << setprecision(1) << area / 2.0 << "\n";
    return 0;
}