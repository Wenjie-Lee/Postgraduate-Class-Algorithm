// practice 7-4

/*
8 53
98 183 37 122 14 124 65 67
*/
const int maxn = 100;

struct request {
    int relative_pos, idx;
}req[maxn];

bool cmp(request a, request b) {
    return a.relative_pos < b.relative_pos;
}

int n, c, pos[maxn], mov;
vector<request> vc;

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
        req[i].idx = i;
        req[i].relative_pos = abs(c - pos[i]);
        vc.push_back(req[i]);
    }
    int not_request = n;
    while (not_request > 0)
    {
        sort(vc.begin(), vc.end(), cmp);
        mov += vc[0].relative_pos;
        vc.erase(vc.begin());
        not_request++;
    }
    cout << mov << endl;
    return 0;
}