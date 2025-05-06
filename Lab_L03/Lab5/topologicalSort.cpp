#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions
    
    void topologicalSortUtil(int v, bool visited[], list<int>& stack) {
        // Mark the current node as visited
        visited[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (int i = 0; i < adj[v].getSize(); i++) {
            int neighbor = adj[v].getElement(i);
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }

        // Push the current vertex to the front of the stack
        stack.push_front(v);
    }

    void topologicalSort() {
        bool* visited = new bool[V]; // Array to track visited vertices
        for (int i = 0; i < V; i++) {
            visited[i] = false; // Initialize all vertices as not visited
        }

        list<int> stack; // List to store the topological order

        // Call the recursive helper function for all unvisited vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        // Print the topological order
        for (int vertex : stack) {
            cout << vertex << " ";
        }
        cout << endl;

        delete[] visited; // Free dynamically allocated memory
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort(); // Output: 5 4 2 3 1 0

    return 0;
}