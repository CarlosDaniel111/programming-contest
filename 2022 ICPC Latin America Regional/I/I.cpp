#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e2 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

int n, m;
int tablero[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]);
}

int dfs(int x, int y) {

    visited[x][y] = true;
    int opc1 = 0, opc2 = 0, opc3 = 0, opc4 = 0;
    if (isValid(x + 1, y) && tablero[x][y] < tablero[x + 1][y]) {
        opc1 = 1 + dfs(x + 1, y);
    }
    if (isValid(x, y + 1) && tablero[x][y] < tablero[x][y + 1]) {
        opc2 = 1 + dfs(x, y + 1);
    }
    if (isValid(x - 1, y) && tablero[x][y] < tablero[x - 1][y]) {
        opc3 = 1 + dfs(x - 1, y);
    }
    if (isValid(x, y - 1) && tablero[x][y] < tablero[x][y - 1]) {
        opc4 = 1 + dfs(x, y - 1);
    }

    return opc1 + opc2 + opc3 + opc4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    FOR(i, n) {
        FOR(j, m) {
            cin >> tablero[i][j];
        }
    }

    int ans = -1;
    FOR(i, n) {
        FOR(j, m) {
            memset(visited, 0, sizeof(visited));
            ans = max(ans, 1 + dfs(i, j));
        }
    }

    cout << ans << ENDL;

    return 0;
}
