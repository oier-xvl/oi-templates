#include <bits/stdc++.h>

const long long IMX = 1ll << 30;
const long long LMX = 1ll << 60;

const long long MOD1 = 998244353;
const long long MOD2 = 1000000007;
const long long MOD3 = 1000000009;

using ll = long long;
using i128 = __int128;
using ld = long double;
using f128 = __float128;

namespace xvl_ {
    #define SP(n, x) std :: setprecision(n) << std :: fixed << x
    #define DEBUG(x) std :: cerr << __LINE__ << ": " << #x << " = " << (x) << '\n'
    #define fst first
    #define snd second
    template <typename T> T Max(T a, T b) { return a > b ? a : b; } template <typename T, typename... Args> T Max(T a, Args... args) { return a > Max(args...) ? a : Max(args...); }
    template <typename T> T Min(T a, T b) { return a < b ? a : b; } template <typename T, typename... Args> T Min(T a, Args... args) { return a < Min(args...) ? a : Min(args...); }
}
using namespace std;
using namespace xvl_;
const int N = 1000005;
template <size_t N> struct UnweightedGraph {
    using iterator = typename vector <int> :: iterator;
    struct range {
        iterator l, r;
        iterator begin() const { return l; }
        iterator end() const { return r; }
        int size() const { return r - l; }
        bool empty() const { return l == r; }
        int &operator [] (int k) const { return l[k]; }
    };
    int m = 0;
    vector <int> u, v, deg, G;
    UnweightedGraph() : deg(N + 1) {  }
    void add_edge(int x, int y) {
        u.emplace_back(x);
        v.emplace_back(y);
        m++;
    }
    void build() {
        G.resize(m), deg.assign(N + 1, 0);
        for (int i = 0; i < m; i++) deg[u[i]]++;
        for (int i = 0; i < N; i++) deg[i + 1] += deg[i];
        for (int i = m - 1; i >= 0; i--) G[--deg[u[i]]] = v[i];
    }
    range operator [] (int x) { return {G.begin() + deg[x], G.begin() + deg[x + 1]}; }
};
UnweightedGraph <N> G;
int n, m;
int main() {
    // freopen("InName.in", "r", stdin);
    // freopen("OutName.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) { int u, v; cin >> u >> v; G.add_edge(u, v); }
    G.build();
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto v : G[i]) cout << v << ' ';
        cout << '\n';
    }
    return 0;
}