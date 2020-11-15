// practice 5-1

/*
算法思想： DFS，对所有事件按照开始时间早晚和持续事件长短排序；
        （1） 所有事件都遍历过时，跳出；
        （2） 选择下一个事件，满足下一个事件的开始时间晚于当前事件的结束事件。
            再分叉选择此事件与否。
            剪枝技巧：（1） 只有当前的时间 + 之后所有的时间 >= 当前最长时间，才会往下走

输入样例1：
4
1 2
3 5
1 4
4 5
样例输出1：
4
*/

const int maxn = 10010;
int n, max_time = 0, start_time, end_time;

struct event {
    int start, end;
} events[maxn];

bool cmp(event a, event b) {
    if (a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}

void dfs(int index, int local_time) {
    if (index == n) return;
    // 最长时间占比，可简化为直接比较时间的长短
    max_time = max(max_time, local_time);

    for (int i = index; i < n; i++)
    {
        // 必须满足下一个事件的开始时间要晚于上一个事件的结束时间
        if (events[index].end > events[i].start) continue;
        local_time += events[index].end - events[index].start;
        // 只有当前的时间 + 之后所有的时间 >= 当前最长时间，才会往下走
        if (local_time + end_time - events[index].end >= max_time)
            dfs(index + 1, local_time);
        local_time -= events[index].end - events[index].start;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &events[i].start, &events[i].end);
    sort(events, events + n, cmp);
    // 记录所有事件中的最早开始时间，最晚结束时间
    start_time = events[0].start, end_time = events[n - 1].end;
    dfs(0, 0);
    printf("%d\n", max_time);
    return 0;
}