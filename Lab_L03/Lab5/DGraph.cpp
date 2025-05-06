#include <string>

template <class T>
class DGraph {
public:
     class VertexNode; // Forward declaration
     class Edge; // Forward declaration
protected:
     VertexNode* nodeList; //list of vertexNode of DGraph
     int countVertex;
     int countEdge;
public:
     DGraph() {
          this->nodeList = nullptr;
          this->countEdge = 0;
          this->countVertex = 0;
     }
     ~DGraph() {};
     VertexNode* getVertexNode(T vertex);
     void add(T vertex);
 
     void connect(T from, T to, float weight=0);
 
     void removeVertex(T removeVertex);
     bool removeEdge(T from, T to);
     string shape();
     bool empty();
     void clear();
     void printGraph();

public:
     class VertexNode {
     private:
          T vertex;
          Edge* adList; //list of adjacent edge of this vertex
          VertexNode* next;

          friend class Edge;
          friend class DGraph;
     public:

          VertexNode(T vertex, Edge* adList = nullptr, VertexNode* next = nullptr) {
               this->vertex = vertex;
               this->adList = adList;
               this->next = next;
     }
          string toString();
          void addAdjacentEdge(Edge* newEdge);
          bool connectTo(VertexNode* toNode, float weight = 0);
          bool removeTo(VertexNode* toNode);
          Edge* getEdge(VertexNode* toNode);
     };
 
     class Edge {
     private:
          VertexNode* fromNode;
          VertexNode* toNode;
          float weight;
          Edge* next;

          friend class VertexNode;
          friend class DGraph;
     public:
          Edge(VertexNode* fromNode, VertexNode* toNode, float weight = 0.0, Edge* next = nullptr) {
               this->fromNode = fromNode;
               this->toNode = toNode;
               this->weight = weight;
               this->next = next;
          }
          string toString();

     };
};

template<class T>
typename DGraph<T>::Edge* DGraph<T>::VertexNode::getEdge(VertexNode* toNode) {
    // Iterate through the adjacency list of this vertex
    Edge* current = this->adList;
    while (current != nullptr) {
        if (current->toNode == toNode) {
            return current; // Return the edge if found
        }
        current = current->next;
    }
    return nullptr; // Return nullptr if no edge is found
}

template<class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge* newEdge) {
    // Add the new edge to the front of the adjacency list
    newEdge->next = this->adList;
    this->adList = newEdge;
}

template<class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode* toNode, float weight) {
    // Check if an edge already exists
    Edge* existingEdge = this->getEdge(toNode);
    if (existingEdge != nullptr) {
        // If the edge exists, update its weight
        existingEdge->weight = weight;
        return false; // No new edge created
    }

    // If the edge does not exist, create a new edge and add it to the adjacency list
    Edge* newEdge = new Edge(this, toNode, weight);
    this->addAdjacentEdge(newEdge);
    return true; // New edge created
}

template<class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode* toNode) {
    // Remove the edge with "toNode" as the ending vertex from the adjacency list
    Edge* current = this->adList;
    Edge* previous = nullptr;

    while (current != nullptr) {
        if (current->toNode == toNode) {
            // If the edge is found, remove it
            if (previous == nullptr) {
                // If the edge is the first in the list
                this->adList = current->next;
            } else {
                // If the edge is in the middle or end of the list
                previous->next = current->next;
            }
            delete current; // Free the memory
            return true; // Successfully removed
        }
        previous = current;
        current = current->next;
    }
    return false; // Edge not found
}

template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    // Iterate through the node list to find the vertex
    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        if (current->vertex == vertex) {
            return current; // Return the vertex node if found
        }
        current = current->next;
    }
    return nullptr; // Return nullptr if the vertex is not found
}

template<class T>
void DGraph<T>::add(T vertex) {
    // Check if the vertex already exists
    if (getVertexNode(vertex) != nullptr) {
        throw std::runtime_error("Vertex already exists!");
    }

    // Create a new vertex node
    VertexNode* newNode = new VertexNode(vertex);

    // Add the new vertex node to the end of the node list
    if (this->nodeList == nullptr) {
        this->nodeList = newNode; // If the list is empty, set as head
    } else {
        VertexNode* current = this->nodeList;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode; // Add to the end of the list
    }

    // Increase the vertex count
    this->countVertex++;
}

template<class T>
void DGraph<T>::connect(T from, T to, float weight) {
    // Get the vertex nodes for "from" and "to"
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);

    // If either vertex does not exist, throw an exception
    if (fromNode == nullptr || toNode == nullptr) {
        throw std::runtime_error("VertexNotFoundException: Vertex doesn't exist!");
    }

    // Connect the "from" vertex to the "to" vertex
    if (fromNode->connectTo(toNode, weight)) {
        this->countEdge++; // Increase the edge count if a new edge is created
    }
}

template<class T>
void DGraph<T>::printGraph() {
    std::cout << "==================================================" << std::endl;
    std::cout << "Number of vertices: " << this->countVertex << std::endl;

    // Print all vertices
    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        std::cout << "V(" << current->vertex << ")" << std::endl;
        current = current->next;
    }

    std::cout << "------------------------------" << std::endl;
    std::cout << "Number of edges: " << this->countEdge << std::endl;

    // Print all edges
    current = this->nodeList;
    while (current != nullptr) {
        Edge* edge = current->adList;
        while (edge != nullptr) {
            std::cout << "E(" << edge->fromNode->vertex << "," << edge->toNode->vertex << "," << edge->weight << ")" << std::endl;
            edge = edge->next;
        }
        current = current->next;
    }

    std::cout << "==================================================" << std::endl;
}

template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    // Get the vertex nodes for "from" and "to"
    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);

    // If either vertex does not exist, throw an exception
    if (fromNode == nullptr || toNode == nullptr) {
        throw std::runtime_error("VertexNotFoundException: Vertex doesn't exist!");
    }

    // Remove the edge from "fromNode" to "toNode"
    if (fromNode->removeTo(toNode)) {
        this->countEdge--; // Decrement the edge count
        return true; // Edge successfully removed
    }

    return false; // Edge not found
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    // Get the vertex node for "removeVertex"
    VertexNode* removeNode = getVertexNode(removeVertex);

    // If the vertex does not exist, throw an exception
    if (removeNode == nullptr) {
        throw std::runtime_error("VertexNotFoundException: Vertex doesn't exist!");
    }

    // Iterate through all vertices in the graph
    VertexNode* current = this->nodeList;
    while (current != nullptr) {
        // Remove edges from the current vertex to "removeVertex"
        if (current->removeTo(removeNode)) {
            this->countEdge--; // Decrement the edge count
        }
        current = current->next;
    }

    // Remove the vertex node from the node list
    VertexNode* prev = nullptr;
    current = this->nodeList;
    while (current != nullptr) {
        if (current == removeNode) {
            // If the node to remove is found
            if (prev == nullptr) {
                // If it's the head of the list
                this->nodeList = current->next;
            } else {
                // If it's in the middle or end of the list
                prev->next = current->next;
            }
            delete current; // Free the memory
            this->countVertex--; // Decrement the vertex count
            return;
        }
        prev = current;
        current = current->next;
    }
}

template<class T>
string DGraph<T>::shape() {
    // Return the string with format: [Vertices: <numOfVertex>, Edges: <numOfEdge>]
    return "[Vertices: " + std::to_string(this->countVertex) + ", Edges: " + std::to_string(this->countEdge) + "]";
}

template<class T>
bool DGraph<T>::empty() {
    // Return true if the graph is empty (no vertices and no edges)
    return this->countVertex == 0 && this->countEdge == 0;
}

template<class T>
void DGraph<T>::clear() {
    // Remove all edges and vertices from the graph
    while (this->nodeList != nullptr) {
        // Remove the first vertex in the list
        this->removeVertex(this->nodeList->vertex);
    }
}
