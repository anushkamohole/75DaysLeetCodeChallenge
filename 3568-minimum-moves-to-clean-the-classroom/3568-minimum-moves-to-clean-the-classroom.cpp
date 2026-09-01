class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = -1, startC = -1;
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        int totalLitter = 0;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterId[r][c] = totalLitter++;
                }
            }
        }

        // If there is no litter to collect, 0 moves are needed
        if (totalLitter == 0) return 0;

        int targetMask = (1 << totalLitter) - 1;

        // BFS structures
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << totalLitter, false)
                )
            )
        );

        queue<tuple<int, int, int, int, int>> q;

        q.push({startR, startC, energy, 0, 0});
        visited[startR][startC][energy][0] = true;

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c, curEnergy, mask, moves] = q.front();
            q.pop();

            // Target condition: all litter collected
            if (mask == targetMask) {
                return moves;
            }

            // Cannot move anywhere from this cell if energy is depleted
            if (curEnergy == 0) {
                continue;
            }

            // Explore all 4 adjacent directions
            for (int i = 0; i < 4; ++i) {
                int nr = r + dRow[i];
                int nc = c + dCol[i];

                // Boundary and obstacle check
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    char cell = classroom[nr][nc];

                    // Energy update: resets to max capacity on 'R', otherwise decreases by 1
                    int nextEnergy = (cell == 'R') ? energy : (curEnergy - 1);

                    // Litter mask update: turn on the bit corresponding to this litter
                    int nextMask = mask;
                    if (cell == 'L') {
                        nextMask |= (1 << litterId[nr][nc]);
                    }

                    // Push next state if not visited
                    if (!visited[nr][nc][nextEnergy][nextMask]) {
                        visited[nr][nc][nextEnergy][nextMask] = true;
                        q.push({nr, nc, nextEnergy, nextMask, moves + 1});
                    }
                }
            }
        }

        // Return -1 if no path can collect all litter
        return -1;
    }
};