#include <bits/stdc++.h>
using namespace std;
string graph[1010];
vector<int> path[1010];
pair<int, int> use[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
string USE = "UDLR";
int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    cin.get();
    int stn, stm;
    int answern, answerm;
    for (int i = 0; i < n; i++)
    {
        getline(cin, graph[i]);
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (graph[i][j] == 'A')
            {
                stn = i;
                stm = j;
                path[i].push_back(0);
            }
            else if (graph[i][j] == '#')
            {
                path[i].push_back(-1);
            }
            else if (graph[i][j] == '.')
            {
                path[i].push_back(1000010);
            }
            else if (graph[i][j] == 'B')
            {
                answern = i;
                answerm = j;
                path[i].push_back(1000010);
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(stn, stm));
    while (!q.empty())
    {
        int nown = q.front().first, nowm = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextn = nown + use[i].first, nextm = nowm + use[i].second;
            if (nextn < 0 || nextn >= n || nextm < 0 || nextm >= m)
                continue;
            if (path[nextn][nextm] <= path[nown][nowm] + 1 || path[nextn][nextm] == -1)
                continue;
            path[nextn][nextm] = path[nown][nowm] + 1;
            q.push(make_pair(nextn, nextm));
        }
    }
    if (path[answern][answerm] == 1000010)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        cout << path[answern][answerm] << endl;
        string answer = "";
        while (answern != stn || answerm != stm)
        {
            for (int i = 0; i < 4; i++)
            {
                int nextn = answern + use[i].first, nextm = answerm + use[i].second;
                if (nextn < 0 || nextn >= n || nextm < 0 || nextm >= m)
                    continue;
                if (path[nextn][nextm] + 1 == path[answern][answerm])
                {
                    answer += USE[i];
                    answern = nextn;
                    answerm = nextm;
                    break;
                }
            }
        }
        for (int i = answer.size() - 1; i >= 0; i--)
        {
            cout << answer[i];
        }
    }
    return 0;
}