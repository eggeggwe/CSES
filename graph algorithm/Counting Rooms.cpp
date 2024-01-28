#include <iostream>
#include <utility>
#include <string>
#include <queue>
using namespace std;
string s[1010];
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    long long int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                rooms++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while (!q.empty())
                {
                    pair<int, int> now = q.front();
                    q.pop();
                    if (s[now.first][now.second] == '#')
                        continue;
                    s[now.first][now.second] = '#';
                    for (int k = 0; k < 4; k++)
                    {
                        int nextn = now.first + dir[k].first, nextm = now.second + dir[k].second;
                        if (nextn < 0 || nextn >= n || nextm < 0 || nextm >= m)
                            continue;
                        if (s[nextn][nextm] == '.')
                        {
                            q.push(make_pair(nextn, nextm));
                        }
                    }
                }
            }
        }
    }
    cout << rooms;
    return 0;
}