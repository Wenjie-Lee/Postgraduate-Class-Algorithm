/*
4
XXXX
XOOX
XXOX
XOXX
4
XXXX
XOOO
XXOX
XOXX
5
XXXOX
XOXOX
OXOOX
XOXXX
XXXXX
*/
const int maxn = 10;
// 上 右 下 左
int x[4] = { 0, 1, 0, -1 }, y[4] = {1, 0, -1, 0}, n;
char g[maxn][maxn];
bool vis[maxn][maxn];
vector<pair<int, int> > path;

bool valid(int i, int j) {
	if (i == 0 || i == n-1 || j == 0 || j == n-1)
		return false;
	return true;
}

bool dfs(int i, int j) {
	vis[i][j] = true;
	// 如果O处于边界上，则不能转换为X; 
	if (!valid(i, j)) 
		return false;
	path.push_back(make_pair(i, j));
	bool flag = true;
	for (int a = 0; a < 4; a++)
	{
		if (!vis[i + x[a]][j + y[a]] && g[i + x[a]][j + y[a]] == 'O')
		{
			if (!dfs(i + x[a], j + y[a]))
				flag = false;
		}
	}
	return flag;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &g[i][j]);
		}
		scanf("\n");
	}
	// 最外面一圈直接不用遍历
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (!vis[i][j] && g[i][j] == 'O')
			{
				// 根据对内坐标转换
				if (!dfs(i, j)) {
					path.clear();
				}
				else {
					for (int z = 0; z < path.size(); z++)
						g[path[z].first][path[z].second] = 'X';
				}
				
			}
		}
	}
	// 转换
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%c", g[i][j]);
		printf("\n");
	}
	return 0;
}