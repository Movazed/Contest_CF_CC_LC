#include <bits/stdc++.h>
#define START_LOOP(var, limit) int var = 0; while(var < limit) {
#define END_LOOP(var) var++; }
#define IS_OUT_OF_BOUNDS(r, c, R, C) (r < 0 || r >= R || c < 0 || c >= C)
#define CREATE_STATE_TUPLE(r, c, d) std::make_tuple(r, c, d)
#define CALCULATE_NEXT_DIRECTION(cell, dir) ((cell) == '/' ? slash_turn[dir] : ((cell) == '\\' ? bslash_turn[dir] : dir))
#define ADVANCE_STATE(r, c, d, new_dir) r += dr[new_dir]; c += dc[new_dir]; d = new_dir

using namespace std;


int M, N;
vector<string> grid;
bool visited[50][50][4];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int slash_turn[] = {1, 0, 3, 2};
int bslash_turn[] = {3, 2, 1, 0};

void solve() {

    cin >> M >> N;
    
    grid.assign(M, string(N, ' '));
    memset(visited, false, sizeof(visited));

    START_LOOP(i, M)
        START_LOOP(j, N)
            cin >> grid[i][j];
        END_LOOP(j)
    END_LOOP(i)

    int max_len = 0;

    START_LOOP(r, M)
        START_LOOP(c, N)
            START_LOOP(d, 4)
                if (!visited[r][c][d]) {
                    map<tuple<int, int, int>, int> trace_map;
                    int path_len = 0;
                    int cur_r = r;
                    int cur_c = c;
                    int cur_d = d;

                    while (true) {
                        if (IS_OUT_OF_BOUNDS(cur_r, cur_c, M, N)) {
                            break;
                        }

                        auto it = trace_map.find(CREATE_STATE_TUPLE(cur_r, cur_c, cur_d));
                        if (it != trace_map.end()) {
                            int loop_val = path_len - it->second;
                            max_len = max(max_len, loop_val);
                            break;
                        }

                        if (visited[cur_r][cur_c][cur_d]) {
                            break;
                        }

                        visited[cur_r][cur_c][cur_d] = true;
                        trace_map[CREATE_STATE_TUPLE(cur_r, cur_c, cur_d)] = path_len;
                        path_len++;

                        char cell_char = grid[cur_r][cur_c];
                        int next_dir = CALCULATE_NEXT_DIRECTION(cell_char, cur_d);
                        
                        ADVANCE_STATE(cur_r, cur_c, cur_d, next_dir);
                    }
                }
            END_LOOP(d)
        END_LOOP(c)
    END_LOOP(r)

    cout << max_len;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}