#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, M = 1e9 + 5;
int n, dP[N][N], demKhac[N][N];
string s;

int xuLi(int l, int r)
{
    if (demKhac[l][r] == 1)
        return 1;
    if (l > r)
        return 0;
    if (dP[l][r] != 0)
        return dP[l][r];

    int ans = M, i = l;
    for (int j = i + 1; j <= r; ++j)
        if (s[i] != s[j])
        {
            ans = min(ans, xuLi(l, i - 1) + 1 + xuLi(j, r) - (l < i && j <= r && s[i - 1] == s[j]));
            i = j;
        }

    return (dP[l][r] = ans);
}

int main()
{
    //freopen("a.inp", "r", stdin);
    freopen("DELSTR.inp", "r", stdin);
    freopen("DELSTR.out", "w", stdout);

    cin >> n >> s;

    memset(dP, 0, sizeof(dP));
    memset(demKhac, 0, sizeof(demKhac));

    bool dD[27];
    for (int i = 0; i < s.size(); ++i)
    {
        memset(dD, 0, sizeof(dD));
        for (int j = i; j < s.size(); ++j)
        {

            int t = s[j] - 'a';
            demKhac[i][j] = demKhac[i][j - 1] + (dD[t] == 0);
            dD[t] = 1;
        }
    }

    cout << xuLi(0, n - 1);

    return 0;
}
