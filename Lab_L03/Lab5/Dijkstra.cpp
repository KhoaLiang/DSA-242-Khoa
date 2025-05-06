#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// Some helping functions

int Dijkstra(int** graph, int src, int dst) {
    const int n = 6; // Assuming the graph has 6 vertices as per the example
    vector<int> dist(n, INT_MAX); // Distance vector initialized to infinity
    dist[src] = 0; // Distance to the source is 0

    // Min-heap priority queue to store {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second; // Current vertex
        int d = pq.top().first;  // Current distance
        pq.pop();

        // If we reach the destination, return the distance
        if (u == dst) {
            return d;
        }

        // Relaxation step: Check all adjacent vertices
        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0) { // If there is an edge between u and v
                int weight = graph[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // If the destination is unreachable, return -1
    return -1;
}