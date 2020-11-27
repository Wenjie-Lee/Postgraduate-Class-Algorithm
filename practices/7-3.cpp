// practice 7-3

/*
汽车加油，指出应在哪些加油站加油，使加油次数最少，到达终点

    （1） 加油次数最少，就是汽车要在可行驶里程内尽量少加油，

4
2 7 3 6

*/
const int maxn = 100;
int n, d = 7, a[maxn];
int time = 0;
vector<int> record;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int idx = 0;
    while (true)
    {
        if (idx == n - 1) break;
        // 在油箱空前，尽量往前走
        while (d >= a[idx]) 
            d -= a[idx++];
        // 在能达到的最后加油站加满油
        time++;
        d = 7;
        record.push_back(idx-1);
    }
    cout << time << endl;
    cout << record[0];
    for (int i = 1; i < record.size(); i++)
        cout << "->" << record[i];
    return 0;
}