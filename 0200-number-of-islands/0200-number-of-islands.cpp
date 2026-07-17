class Solution {
public:

    class DSU {
    public:
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union(int px, int py) {
            parent[px] = py;
        }
    };

    int numIslands(vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        DSU dsu(row * col);

        int landCount = 0;

        // only right and down
        int rc[2][2] = {
            {0, 1},
            {1, 0}
        };

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == '1') {

                    landCount++;

                    for (int k = 0; k < 2; k++) {

                        int r = i + rc[k][0];
                        int c = j + rc[k][1];

                        if (r >= 0 && c >= 0 &&
                            r < row && c < col &&
                            grid[r][c] == '1') {

                            int node1 = i * col + j;
                            int node2 = r * col + c;

                            int p1 = dsu.find(node1);
                            int p2 = dsu.find(node2);

                            if (p1 != p2) {
                                dsu.Union(p1, p2);
                                landCount--;
                            }
                        }
                    }
                }
            }
        }

        return landCount;
    }
};