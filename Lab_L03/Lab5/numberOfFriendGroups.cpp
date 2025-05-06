void dfs(int node, vector<vector<int>>& friends, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : friends[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, friends, visited);
        }
    }
}

int numberOfFriendGroups(vector<vector<int>>& friends) {
    int n = friends.size(); // Number of people
    vector<bool> visited(n, false); // Track visited nodes
    int friendGroups = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            // Start a new DFS for an unvisited node
            dfs(i, friends, visited);
            friendGroups++; // Increment the count of friend groups
        }
    }

    return friendGroups;
}