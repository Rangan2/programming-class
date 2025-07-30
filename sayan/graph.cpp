/**
 * Graph ADT [Abstract DataType]
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
  private:
    int size = 0; // number of vertices;
    vector<unordered_set<int>> adjList;
    bool isDirected = false;
  public:
    Graph() { // Default Constructor
        cout << "The Default Constructor is Getting Called" << endl;
    }
    
    Graph(int size, vector<vector<int>> edgeList, bool isDirected) {
        cout << "The Custom Overloaded Constructor is Getting Called" << endl;
        this->size = size;
        adjList.resize(this->size);
        this->isDirected = isDirected;
        addEdge(edgeList);
    }

    Graph(Graph& graph) {
        // Write your copy constructor here
        cout << "Copy Constructor Called\n";
        this->size = graph.size;
        this->isDirected = graph.isDirected;
        this->adjList = graph.adjList;
    }

    ~Graph() { // Destructor
        cout << "The Default Destructor is Getting Called" << endl;
    }

    void setGraphDirected(bool isDirected) {
        this->isDirected = isDirected;
    }

    void addVertex() {
        size++;
        adjList.push_back({});
    }

    bool isEdgeValid(int& source, int& target) {
        if (source >= size || target >= size)
            return false;
        
        if (adjList[source].count(target) > 0)
            return false;
        
        if (!isDirected && adjList[target].count(source) > 0)
            return false;
        
        return true;
    }

    bool addEdge(int source, int target) {
        if (!isEdgeValid(source, target))
            return false;
        adjList[source].insert(target);
        if (!isDirected)
            adjList[target].insert(source);

        return true;
    }

    bool addEdge(vector<vector<int>>& edges) {
        for (auto& e: edges)
            if(!isEdgeValid(e[0], e[1]))
                return false;
        
        for (auto& e: edges)
            addEdge(e[0], e[1]);
        
        return true;
    }

    vector<unordered_set<int>>& getAdjList() {
        return adjList;
    }

    void sortGraphStructure(vector<vector<int>>& graph) {
        sort(graph.begin(), graph.end(), compareNodes);
    }

    static bool compareNodes(vector<int>& a, vector<int>& b) {
        if (a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }

    bool isGraphIsomorphic(Graph& G) {
        vector<unordered_set<int>>& g2AdjList = G.getAdjList();
        // write your code here
        if (this->size != G.size)
            return false;
        
        vector<unordered_set<int>>& g1 = this->adjList;
        vector<unordered_set<int>>& g2 = G.getAdjList();

        vector<vector<int>> g1Sorted(size), g2Sorted(size);

        for (int i = 0; i < size; i++) {
            g1Sorted[i] = vector<int>(g1[i].begin(), g1[i].end());
            g2Sorted[i] = vector<int>(g2[i].begin(), g2[i].end());

            sort(g1Sorted[i].begin(), g1Sorted[i].end());
            sort(g2Sorted[i].begin(), g2Sorted[i].end());
        }

        sortGraphStructure(g1Sorted);
        sortGraphStructure(g2Sorted);


        return g1Sorted == g1Sorted;
    }
};

main() {
    Graph G1(4, {{0, 1}, {1, 3}, {2, 3}}, false);
    Graph G2(4, {{0, 1}, {1, 3}, {2, 3}}, false);

    G1.addEdge(0, 3);
    G2.addEdge(0, 3);
    cout << "Are G1 and G2 isomorphic? " << (G1.isGraphIsomorphic(G2) ? "Yes" : "No") << endl;

    Graph G3(G1);  // Test copy constructor
    cout << "Are G1 and G3 isomorphic? " << (G1.isGraphIsomorphic(G3) ? "Yes" : "No") << endl;
}