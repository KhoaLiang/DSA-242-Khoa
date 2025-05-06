#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack, vector<list<int>>& adj) {
        // Mark the current node as visited and add it to the recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, adj)) {
                return true; // Cycle detected
            } else if (recStack[neighbor]) {
                return true; // Cycle detected
            }
        }

        // Remove the vertex from the recursion stack
        recStack[v] = false;
        return false;
    }

    bool isCyclic() {
        vector<bool> visited(V, false); // Track visited nodes
        vector<bool> recStack(V, false); // Track nodes in the recursion stack

        // Call the recursive helper function for all vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, recStack, adj)) {
                    return true; // Cycle detected
                }
            }
        }

        return false; // No cycle detected
    }
}; 
int main() {
    DirectedGraph g(8); 
    int edge[][2] = {{0,6}, {1,2}, {1,4}, {1,6}, {3,0}, {3,4}, {5,1}, {7,0}, {7,1}};

    for (int i = 0; i < 9; i++) {
        g.addEdge(edge[i][0], edge[i][1]);
    }

    if (g.isCyclic()) {
        cout << "Graph contains cycle"; 
    } else {
        cout << "Graph doesn't contain cycle"; 
    }

    return 0;
}