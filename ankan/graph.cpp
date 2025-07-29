/**
 * Graph ADT [Abstract DataType]
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
  private:
    int size = 0; // number of vertices;
    vector<unordered_map<int, int>> adjList; // weighted graph
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

    Graph(const Graph& graph) {
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
    
    // g.addEdge(v1, v2); --> {v1, v2, 1}
    // g.addEdge(v1, v2, w); --> {v1, v2, w}
    bool addEdge(int source, int target, int weight = 1) {
        if (!isEdgeValid(source, target))
            return false;
        adjList[source][target] = weight;
        if (!isDirected)
            adjList[target][source] = weight;

        return true;
    }

    bool addEdge(vector<vector<int>>& edges) {
        for (auto& e: edges)
            if(!isEdgeValid(e[0], e[1]))
                return false;
        
        for (auto& e: edges)
            if (e.size() == 2)
                addEdge(e[0], e[1]);
            else if (e.size() == 3)
                addEdge(e[0], e[1], e[2]);
        
        return true;
    }

    vector<unordered_map<int, int>>& getAdjList() {
        return adjList;
    }

    bool isGraphIsomorphic(Graph& G, vector<int> permutation) {
        if (permutation.size() != this->size)
            return false;
        
        vector<unordered_map<int, int>>& g2AdjList = G.getAdjList();
        
        if (g2AdjList.size() != this->adjList.size())
            return false;

        for(int i = 0; i < size; i++) {
            if (this->adjList[i].size() != g2AdjList[permutation[i]].size())
                return false;
            
            for (auto& k : this->adjList[i]) {
                int v = k.first;
                int w = k.second;

                if (g2AdjList[permutation[i]].count(permutation[v]) == 0 ||
                    w != g2AdjList[permutation[i]][permutation[v]])

                    return false;
            }
        }

        return true;
    }

    Graph minimumSpanningTree() {
        Graph mst(this->size, {}, false);
        auto edgeList = this->getEdgeList();
        sort(edgeList.begin(), edgeList.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });

        vector<bool> isVisited(this->size, false);
        for (auto edge: edgeList) {
            if (isVisited[edge[0]] == true && isVisited[edge[1]] == true) // cycle
                continue;
            
            mst.addEdge(edge[0], edge[1], edge[2]);
            isVisited[edge[0]] = true;
            isVisited[edge[1]] = true;
        }

        return mst;
    }

    vector<int> bfs() {
        vector<bool> visited(this->size, false);
        vector<int> result;
        queue<int> Q;

        Q.push(0);
        visited[0] = true;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            result.push_back(u);

            for (auto& i : adjList[u]) {
                int v = i.first;   // extracting the neighbour vertex from unordered_map
                if (!visited[v]) {
                    visited[v] = true;
                    Q.push(v);
                }
            }
        }
        return result;
    }

    vector<int> dfs() {
        vector<bool> visited2 (this->size, false);
        vector<int> result2;

        dfsVisit(0, visited2, result2);

        return result2;
    }

    void dfsVisit(int u, vector<bool>& visited2, vector<int>& result2) {
            visited2[u] = true;
            result2.push_back(u);

            for (auto& i : adjList[u]) {
                int v = i.first;
                if (!visited2[v]) {
                dfsVisit(v, visited2, result2);
            }
            }
            
        }

    vector<int> topologicalOrdering() {
        
    }

    bool hasCycles() {

    }

  private:
    vector<vector<int>> getEdgeList() {
        vector<vector<int>> edgeList;
        for (int u = 0; u < size; u++) {
            for (auto& i : adjList[u]) {
                int v = i.first;
                int w = i.second;
                if (isDirected || u > v)
                    edgeList.push_back({u, v, w});
            }
        }
        return edgeList;
    }
};

int main() {
    Graph G1(4, {{0, 1, 4}, {1, 3, 6}, {2, 3, 7}}, false), G2(4, {{0, 1}, {1, 3}, {2, 3}}, false);
    G1.addEdge(0, 3, 1);
    G2.addEdge(0, 3);
    cout << G1.isGraphIsomorphic(G2, {});

    Graph MST = G1.minimumSpanningTree();
    vector<unordered_map<int, int>> mstEdges = MST.getAdjList();
    cout << "mst edge list : ";
    for (int i = 0; i < 4; i++) {
        for (auto& u : mstEdges[i]) {
            int v = u.first;
            int w = u.second;
            if (i < v)
                cout << i << "-" << v << " " << "weight" << "=" << w << endl;
        }
    }

    vector<int> bfsTraversal = G1.bfs();
    cout << "BFS traversal : ";
    for (int i : bfsTraversal) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> dfsTraversal = G1.dfs();
    cout << "DFS traversal is : ";
    for (int i : dfsTraversal) {
        cout << i << " ";
    }

    return 0;
}

/*

*/