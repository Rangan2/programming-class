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

    bool isGraphIsomorphic(Graph& G) {
        vector<unordered_set<int>>& g2 = G.getAdjList();
        // write your code here
        int n = this->adjList.size();
        

        if (n != g2.size())
            return false;

        vector<int> permutation;
            for (int i = 0; i < n; ++i)
                permutation.push_back(i);

    
        bool match = true;

        for (int u = 0; u < n; ++u) {
            unordered_set<int> mappedNeighbours;

            for (int v : this->adjList[u])
                mappedNeighbours.insert(permutation[v]);

            if (mappedNeighbours != g2[permutation[u]]) {
                match = false;
                break;
            }
        }

        if (match)
            return true;

    

        return false;
    }
};

main() {
    Graph G1(4, {{0, 1}, {1, 3}, {2, 3}}, false), G2(4, {{0, 1}, {1, 3}, {2, 3}}, false);
    Graph G3(4, {{0, 1}, {1, 2}, {2, 3}}, false), G4(4, {{0, 1}, {0, 2}, {2, 3}}, false);

    G1.addEdge(0, 3);
    G2.addEdge(0, 3);
    cout << G1.isGraphIsomorphic(G2) << endl;
    cout << G3.isGraphIsomorphic(G4) << endl;
    cout << endl;
}

/*
1.vertex count match
2.edge count match
3. take a node u from G1 , take the neighbour nodes of u in G1 that is v 
save it in mappedNeighbours, 
check this mappedNeighbours is equals to or not with G2's permutation[u]
 */
