#include <bits/stdc++.h>
using namespace std;

struct node
{
    int h, f, c;

    bool operator<(const node &a) const
    {
        return h < a.h;
    }
};

const int N = 1e3 + 5;
int n, m;
long long congDon[N], dP[N][N];
pair<int, int> sach[N];
node giaSach[N];

long long xuLi(int vT, int j, int i)
{
    return (dP[vT][j - 1] + giaSach[j].f + giaSach[j].c * (congDon[i] - congDon[vT]));
}

int main()
{
    //freopen("a.inp", "r", stdin);
    freopen("BSF.inp", "r", stdin);
    freopen("BSF.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> sach[i].first >> sach[i].second;
    for (int i = 1; i <= m; ++i)
        cin >> giaSach[i].h >> giaSach[i].f >> giaSach[i].c;

    sort(sach + 1, sach + n + 1);
    sort(giaSach + 1, giaSach + n + 1);

    congDon[0] = 0;
    for (int i = 1; i <= n; ++i)
        congDon[i] = congDon[i - 1] + sach[i].second;

    memset(dP, 0, sizeof(dP));

    dP[1][1] = giaSach[1].f + giaSach[1].c * congDon[1];
    for (int j = 2; j <= m; ++j)
        dP[1][j] = min(dP[1][j - 1], giaSach[1].f + giaSach[1].c * congDon[1]);

    for (int i = 2; i <= n; ++i)
    {
        int vT = lower_bound(giaSach + 1, giaSach + m + 1, (node){sach[i].first, 0, 0}) - giaSach;

        dP[i][vT - 1] = INT64_MAX;
        for (int j = vT; j <= m; ++j)
        {
            dP[i][j] = dP[i][j - 1];

            int l = 0, r = i;
            while (r - l > 3)
            {
                int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;

                if (xuLi(m1, j, i) < xuLi(m2, j, i))
                    r = m2;
                else
                    l = m1;
            }

            for (int f = l; f <= r; ++f)
                dP[i][j] = min(dP[i][j], xuLi(f, j, i));
        }
    }

    cout << dP[n][m];

    return 0;
}
