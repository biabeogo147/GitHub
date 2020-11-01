#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> paii;

const int N = 1e5 + 5;
int n, m, giaTri[N], vis[N], ans;
paii A[N];
vector<int> canhKe[N];

void xuLi(int u, int v)
{
    ans = max(ans, giaTri[u] - giaTri[v]);
    for (auto i : canhKe[u])
        if (vis[i] == 0)
        {
            vis[i] = u;
            xuLi(i, v);
        }
}

int main()
{
    freopen("a.inp", "r", stdin);
    //freopen("THAMQUAN.inp", "r", stdin);
    //freopen("THAMQUAN.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= n; ++i)
            canhKe[i].clear(), vis[i] = 0;

        for (int i = 1; i <= n; ++i)
            cin >> giaTri[i], A[i] = {giaTri[i], i};

        for (int i = 0; i < m; ++i)
        {
            int x, y;
            cin >> x >> y;

            canhKe[x].emplace_back(y);
        }

        sort(A + 1, A + n + 1);

        ans = 0;
        for (int i = 1; i <= n; ++i)
            if (vis[A[i].second] == 0)
                xuLi(A[i].second, A[i].second);

        cout << ans << '\n';
    }

    return 0;
}
