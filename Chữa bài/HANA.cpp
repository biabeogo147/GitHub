#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> paii;

const int N = 2e2 + 5, M = 1e7;
int n, m, nam[N][N];
paii dP[N][N][10];

int main()
{
    freopen("a.inp", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> nam[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int mask = 0; mask < (1 << 3); ++mask)
                dP[i][j][mask] = {-1, -1};

    for (int i = 1; i < n; ++i)
        if (nam[i][0] != -1)
            for (int preMask = 0; preMask < (1 << 3); ++preMask)
            {
                int mask = preMask | (1 << (nam[i][0] - 1));
                if (dP[i - 1][0][preMask] != paii(-1, -1))
                    dP[i][0][mask] = {-1, 0};
            }

    for (int j = 1; j < m; ++j)
        if (nam[0][j] != -1)
            for (int preMask = 0; preMask < (1 << 3); ++preMask)
            {
                int mask = preMask | (1 << (nam[0][j] - 1));
                if (dP[0][j - 1][preMask] != paii(-1, -1))
                    dP[0][j - 1][mask] = {0, -1};
            }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            if (nam[i][j] != -1)
                for (int preMask = 0; preMask < (1 << 3); ++preMask)
                {
                    int mask = preMask;
                    if (nam[i][j] != 0)
                        mask = preMask | (1 << (nam[i][j] - 1));

                    if (dP[i - 1][j][preMask] != paii(-1, -1))
                        dP[i][0][mask] = {-1, 0};
                    if (dP[i][j - 1][preMask] != paii(-1, -1))
                        dP[i][0][mask] = {0, -1};
                }

    for (int mask = 0; mask < (1 << 3); ++mask)
        if (__builtin_popcount(mask) >= 2 && dP[n - 1][m - 1][mask] != paii(-1, -1))
        {
            vector<paii> duongDi;
            int i = n - 1, j = m - 1;
            while (i > 0 && j > 0)
            {
                duongDi.emplace_back(paii(i, j));
                i += dP[i][j][mask].first, j += dP[i][j][mask].second;
            }
            duongDi.emplace_back(paii(0, 0));

            for (int i = duongDi.size() - 1; i >= 0; --i)
                cout << duongDi[i].first + 1 << " " << duongDi[i].second << "\n";

            break;
        }

    return 0;
}
