/* ...Bismillahir Rahmanir Raheem... */
#include <bits/stdc++.h>
using namespace std;

#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define dbg(x) cerr << "Line no- " << __LINE__ << ": " << #x << " = " << x << '\n';
#define ll long long
#define mod 1000000007
const int N = 1e5 + 6;

class CP
{
public:
    
    int n, m;
    bool visited[1000][1000];
    char grid[1000][1000];
    
    void bfs(int &cnt, int i, int j)
    {
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;
        
        cnt++;
        while (!q.empty())
        {
            pair<int, int> u;
            u = q.front();
            q.pop();

            int x = u.first;
            int y = u.second;
            for(int k = 0; k < 4; k++){
                int r = x + dx[k];
                int c = y + dy[k];
                if(r >=0 and r < n and c >= 0 and c < m){
                    if(grid[r][c] =='.' and visited[r][c] == 0){
                        q.push({r,c});
                        visited[r][c] = 1;
                    }
                }
            }
        }
    }
    void solve()
    {
        cin >> n >> m;
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] or grid[i][j] == '#')
                    continue;
                bfs(cnt, i,j);
            }
        }
        cout << cnt << "\n";
    }

    void run()
    {
        faster;
        int test = 1;
        // cin >> test;
        int i = 1;
        while (test--)
        {
            solve();
            // cout << "Case " << i++ << ":\n";
        }
    }
};

int main()
{
    CP cp;
    cp.run();
    return 0;
}