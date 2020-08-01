#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

typedef pair<int, int> P;

struct Node {
    int x, y;
    int cost;
    int k;
    int dir;
};

int main() {
    int H, W, K;
    P s, g;
    cin >> H >> W >> K;
    cin >> s.second >> s.first >> g.second >> g.first;
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    vector<string> m(H);
    rep(i, H) cin >> m[i];

    vector<vector<vector<bool>>> visit(
        H, vector<vector<bool>>(W, vector<bool>(4)));
    auto comp = [](const Node& a, const Node& b) {
        if (a.cost != b.cost) return a.cost > b.cost;
        if (a.k != b.k) return a.k > b.k;
        if (a.dir != b.dir) return a.dir > b.dir;
        if (a.y != b.y) return a.y > b.y;
        return a.x > b.x;
    };
    priority_queue<Node, vector<Node>, decltype(comp)> Q(comp);

    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};

    rep(i, 4) {
        Q.push({
            s.first,
            s.second,
            0,
            K,
            i,
        });
    }

    while (!Q.empty()) {
        auto node = Q.top();
        Q.pop();

        if (visit[node.y][node.x][node.dir]) {
            continue;
        }
        visit[node.y][node.x][node.dir] = true;

        if (make_pair(node.x, node.y) == g) {
            cout << node.cost << endl;
            return 0;
        }

        rep(i, 4) {
            P np(node.x + dx[i], node.y + dy[i]);
            if (!(0 <= np.first && np.first < W)) continue;
            if (!(0 <= np.second && np.second < H)) continue;
            if (m[np.second][np.first] != '.') continue;
            auto nc = (node.dir == i && node.k < K) ? node.cost : node.cost + 1;
            auto nk = (node.dir == i && node.k < K) ? node.k + 1 : 1;
            Q.push({
                np.first,
                np.second,
                nc,
                nk,
                i,
            });
        }
    }

    cout << -1 << endl;
    return 0;
}
