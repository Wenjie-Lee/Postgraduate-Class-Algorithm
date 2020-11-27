// practice 7-4

/*
磁盘调度最短寻道时间优先SSTF算法
思想：根据当前磁头位置c，所有请求位置都减去c，
再以abs(position)为优先级排序，取第一个为下一个要去的点。
以此向下执行，直到序列中所有的请求都已完成

8 53
98 183 37 122 14 124 65 67
:236
*/
const int maxn = 100;

struct request {
    int relative_pos, idx;
}req[maxn];

bool cmp(request a, request b) {
    return abs(a.relative_pos) < abs(b.relative_pos);
}

int n, c, pos[maxn], mov;
vector<request> vc;
vector<int> list;

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++)     // O(n)
    {
        cin >> req[i].relative_pos;
        req[i].idx = i;
        //req[i].relative_pos = abs(c - pos[i]);
        vc.push_back(req[i]);
    }
    int not_request = n;
    while (not_request > 0)         // O(n)
    {
        for (int i = 0; i < vc.size(); i++) {   // O(n)
            vc[i].relative_pos = c - vc[i].relative_pos;
        }
        sort(vc.begin(), vc.end(), cmp);        // O(nlgn)
        mov += abs(vc[0].relative_pos);
        c = vc[0].relative_pos;
        list.push_back(vc[0].idx);
        vc.erase(vc.begin());
        not_request--;
    }
    cout << mov << endl;
    cout << "list:";
    for (auto i : list)
        cout << " " << i;
    return 0;
}