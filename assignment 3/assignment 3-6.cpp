// assignment 3-6

/*
算法思想：从总集U中找到一个顶点集S，使所有边至少有1个端点存在于S。求一个顶点集S且使S点权和最小。
	如果是这个意思的话，给的答案是错的，S={1,3,4,7}，而(2,5)没有一个端点在S中.
	答案应该是S={1,3,5,7}	

输入样例1：
input.txt
7 7
1 100 1 1 1 100 10
1 6
2 4
2 5
3 6
4 5
4 6
6 7
输出样例1：
output.txt
13
1 0 1 0 1 0 1
*/

const int MAXN = 100;	// 设置一个图顶点上限

struct Node {
	int idx,				// idx 表示刚加入的点
		local_sum;			// 表示当前覆盖节点的权值和
	bool s_vertex[MAXN],	// 表示被选中的顶点
		cover_vertex[MAXN];	// 表示被覆盖的顶点
	Node() {
		memset(s_vertex, 0, sizeof(s_vertex));
		memset(cover_vertex, 0, sizeof(cover_vertex));
	};
};

int n, m, w[MAXN], best_sum = 1000000;
int G[MAXN][MAXN], best_vertex[MAXN];

// 以权重为优先级
struct cmp {
	bool operator()(Node a, Node b) {
		return a.local_sum > b.local_sum;
	}
};

void add_node(priority_queue<Node, vector<Node>, cmp> &q,
	Node node, int idx, int local_sum, bool isLeft) {
	Node e = Node();
	for (int i = 1; i <= n; i++)
	{
		e.s_vertex[i] = node.s_vertex[i];
		e.cover_vertex[i] = node.cover_vertex[i];
	}
	e.idx = idx;
	e.local_sum = local_sum;
	// isLeft 表示要将idx顶点加入
	if (isLeft)
	{
		e.local_sum += w[idx];
		e.s_vertex[idx] = true;
		// 将所有于idx点相邻的顶点修改为被覆盖
		for (int j = 1; j <= n; j++)
			if (G[idx][j])
				e.cover_vertex[j] = true;
	}
	else {
		e.s_vertex[idx] = false;
	}
	q.push(e);
}
// 判断此时是否已得到一个顶点覆盖集
bool all_covered(Node e) {
	for (int i = 1; i <= n; i++)
		if (!e.s_vertex[i] && !e.cover_vertex[i])
			return false;
	return true;
}

void bfs() {
	// 以顶点的权值为优先级存储
	priority_queue<Node, vector<Node>, cmp> q;
	Node node = Node();

	int x = 1, local_sum = 0;
	while (true)
	{
		// 所有点都遍历过了
		if (x > n) {
			if (all_covered(node)) {
				if (node.local_sum < best_sum) {
					best_sum = node.local_sum;
					memset(best_vertex, 0, size(best_vertex));
					for (int i = 1; i <= n; i++)
						best_vertex[i] = node.s_vertex[i];
				}
				break;
			}
		}
		else {
			// 已经被覆盖就跳过
			if (!all_covered(node))
				add_node(q, node, x, local_sum, false);
			add_node(q, node, x, local_sum, true);
		}
		
		if (q.empty()) break;
		node = q.top();
		local_sum = node.local_sum;
		x = node.idx + 1;	// 朝下一个顶点
		q.pop();
	}
}

int main() {
	fstream file;
	string path = _getcwd(NULL, 0);
	path.append("\\input.txt");
	//file.open("E:/VS2015/Projects/PAT/PAT/input.txt");
	file.open(path);
	if (!file.is_open()) {
		cout << path << " 不存在" << endl;
		return 0;
	}
	file >> n >> m;
	for (int i = 1; i <= n; i++)
		file >> w[i];
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		file >> a >> b;
		G[a][b] = G[b][a] = 1;
	}
	file.close();

	bfs();
	
	file.open("./output.txt", ios::out);
	file << best_sum << endl;
	file << best_vertex[1];
	for (int i = 2; i <= n; i++)
		file << " " << best_vertex[i];
	file.close();

	cout << "文件输出成功！" << endl << path << endl;
	return 0;
}