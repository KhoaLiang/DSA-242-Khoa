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

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	void DFSUtil(int v, bool visited[], Adjacency *dfsTraversal)
    {
        // Mark the current node as visited and add it to the traversal
        visited[v] = true;
        dfsTraversal->push(v);

        // Recur for all adjacent vertices of the current vertex
        for (int i = 0; i < adj[v].getSize(); i++)
        {
            int adjVertex = adj[v].getElement(i);
            if (!visited[adjVertex])
            {
                DFSUtil(adjVertex, visited, dfsTraversal);
            }
        }
    }

    Adjacency *DFS(int v)
    {
        // Create a visited array and mark all vertices as not visited
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Create an Adjacency object to store the DFS traversal
        Adjacency *dfsTraversal = new Adjacency();

        // Call the recursive helper function to perform DFS
        DFSUtil(v, visited, dfsTraversal);

        // Clean up the visited array
        delete[] visited;

        return dfsTraversal;
    }
};