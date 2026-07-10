#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<vector<bool>> visited;

int dw[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dh[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void BFS(int h, int w, int H, int W) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(h, w));
    visited[h][w] = true;

    while (!Q.empty()) {
        h = Q.front().first;
        w = Q.front().second;

        Q.pop();
        for (int i = 0; i < 8; i++) {
            int now_h = h + dh[i];
            int now_w = w + dw[i];

            if (now_w >= 0 && now_h >= 0 && now_w < W && now_h < H) {
                if (A[now_h][now_w] && !visited[now_h][now_w]) {
                    visited[now_h][now_w] = true;
                    Q.push(make_pair(now_h, now_w));
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h;

    while (1) {
        int num = 0;

        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        A.assign(h, vector<int>(w));
        visited.assign(h, vector<bool>(w, false));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> A[i][j];
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (A[i][j] && !visited[i][j]) {
                    num++;
                    BFS(i, j, h, w);
                }
            }
        }
        cout << num << '\n';
    }
    return 0;
}
