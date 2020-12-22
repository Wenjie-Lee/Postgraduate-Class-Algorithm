// practice 9-2
/*
多源最短路径问题，使用Floyd算法

*1
4 4
0 1 2
0 2 5
0 3 1
2 3 3
*/
const int maxn = 110, inf = 99999999;
int n, m, dis[maxn][maxn];

void floyd() {
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int curdis = dis[i][k] + dis[k][j];
                if (dis[i][k] != inf && dis[k][j] != inf && curdis < dis[i][j])
                    dis[i][j] = curdis;
            }
        }
    }
}

int main() {
    // init
    fill(dis[0], dis[0] + maxn*maxn, inf);
    for (int i = 0; i < n; i++)
        dis[i][i] = 0;

    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        dis[a][b] = dis[b][a] = c;
    }

    floyd();
    int u = -1, mint = inf;
    for (int i = 0; i < n; i++)
    {
        int maxt = -1;
        for (int j = 0; j < n; j++)
            if (dis[i][j] > maxt)
                maxt = dis[i][j];
        printf("idx: %d, time: %d\n", i, maxt);
        if (maxt < mint)
        {
            u = i;
            mint = maxt;
        }
    }
    printf("MinimalTime: idx: %d, time: %d", u, mint);

    return 0;
}