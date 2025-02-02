#include "KTLT_array.h"

// Function to perform DFS and calculate the area of an island
int dfs(int grid[][MAX], int x, int y, int n, int m, bool visited[][MAX]) {
    // Check for out of bounds or if the cell is water or already visited
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y]) {
        return 0;
    }

    // Mark the cell as visited
    visited[x][y] = true;

    // Initialize area
    int area = 1;

    // Explore all four directions (up, down, left, right)
    area += dfs(grid, x + 1, y, n, m, visited);
    area += dfs(grid, x - 1, y, n, m, visited);
    area += dfs(grid, x, y + 1, n, m, visited);
    area += dfs(grid, x, y - 1, n, m, visited);

    return area;
}

int maxAreaOfIsland(int grid[][MAX], int n, int m) {
    // Initialize visited array
    bool visited[MAX][MAX] = {false};

    int max_area = 0;

    // Iterate through each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is land and not visited, perform DFS
            if (grid[i][j] == 1 && !visited[i][j]) {
                int area = dfs(grid, i, j, n, m, visited);
                if (area > max_area) {
                    max_area = area;
                }
            }
        }
    }

    return max_area;
}