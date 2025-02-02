#include "KTLT_array.h"

// Function to perform DFS and mark the visited cells
void dfsMark(int grid[][MAX], int x, int y, int n, int m, bool visited[][MAX]) {
    // Check for out of bounds or if the cell is water or already visited
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y]) {
        return;
    }

    // Mark the cell as visited
    visited[x][y] = true;

    // Explore all four directions (up, down, left, right)
    dfsMark(grid, x + 1, y, n, m, visited);
    dfsMark(grid, x - 1, y, n, m, visited);
    dfsMark(grid, x, y + 1, n, m, visited);
    dfsMark(grid, x, y - 1, n, m, visited);
}

int numberOfClosedIslands(int grid[][MAX], int n, int m) {
    // Initialize visited array
    bool visited[MAX][MAX] = {false};

    // Mark all lands connected to the boundary as visited
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1 && !visited[i][0]) {
            dfsMark(grid, i, 0, n, m, visited);
        }
        if (grid[i][m - 1] == 1 && !visited[i][m - 1]) {
            dfsMark(grid, i, m - 1, n, m, visited);
        }
    }
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1 && !visited[0][j]) {
            dfsMark(grid, 0, j, n, m, visited);
        }
        if (grid[n - 1][j] == 1 && !visited[n - 1][j]) {
            dfsMark(grid, n - 1, j, n, m, visited);
        }
    }

    int closedIslands = 0;

    // Iterate through each cell in the grid
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            // If the cell is land and not visited, perform DFS
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfsMark(grid, i, j, n, m, visited);
                closedIslands++;
            }
        }
    }

    return closedIslands;
}