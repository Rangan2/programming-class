/**
 * Graph ADT [Abstract DataType]
 */

#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int size = 0;                            // number of vertices;
    vector<unordered_map<int, int>> adjList; // weighted graph
    bool isDirected = false;

public:
    Graph()
    { // Default Constructor
        cout << "The Default Constructor is Getting Called" << endl;
    }

    Graph(int size, vector<vector<int>> edgeList, bool isDirected)
    {
        cout << "The Custom Overloaded Constructor is Getting Called" << endl;
        this->size = size;
        adjList.resize(this->size);
        this->isDirected = isDirected;
        addEdge(edgeList);
    }

    Graph(Graph &graph)
    {
        // Write your copy constructor here
    }

    ~Graph()
    { // Destructor
        cout << "The Default Destructor is Getting Called" << endl;
    }

    void setGraphDirected(bool isDirected)
    {
        this->isDirected = isDirected;
    }

    void addVertex()
    {
        size++;
        adjList.push_back({});
    }

    bool isEdgeValid(int &source, int &target)
    {
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
    bool addEdge(int source, int target, int weight = 1)
    {
        if (!isEdgeValid(source, target))
            return false;
        adjList[source][target] = weight;
        if (!isDirected)
            adjList[target][source] = weight;

        return true;
    }

    bool addEdge(vector<vector<int>> &edges)
    {
        for (auto &e : edges)
            if (!isEdgeValid(e[0], e[1]))
                return false;

        for (auto &e : edges)
            if (e.size() == 2)
                addEdge(e[0], e[1]);
            else if (e.size() == 3)
                addEdge(e[0], e[1], e[2]);

        return true;
    }

    vector<unordered_map<int, int>> &getAdjList()
    {
        return adjList;
    }

    bool isGraphIsomorphic(Graph &G, vector<int> permutation)
    {
        if (permutation.size() != this->size)
            return false;

        vector<unordered_map<int, int>> &g2AdjList = G.getAdjList();

        if (g2AdjList.size() != this->adjList.size())
            return false;

        for (int i = 0; i < size; i++)
        {
            if (this->adjList[i].size() != g2AdjList[permutation[i]].size())
                return false;

            for (auto [v, w] : this->adjList[i])
            {
                if (g2AdjList[permutation[i]].count(permutation[v]) == 0 ||
                    w != g2AdjList[permutation[i]][permutation[v]])

                    return false;
            }
        }

        return true;
    }

    Graph minimumSpanningTree()
    {
        Graph mst(this->size, {}, false);
        auto edgeList = this->getEdgeList();
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        vector<bool> isVisited(this->size, false);
        for (auto edge : edgeList)
        {
            if (isVisited[edge[0]] == true && isVisited[edge[1]] == true) // cycle
                continue;

            mst.addEdge(edge[0], edge[1], edge[2]);
            isVisited[edge[0]] = true;
            isVisited[edge[1]] = true;
        }

        return mst;
    }

    vector<int> bfs()
    {
        vector<int> visited(size, 0), result;
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it)
            {
                int v = it->first;
                if (!visited[v])
                {
                    visited[v] = 1;
                    q.push(v);
                }
            }
        }

        return result;
    }

    void dfsVisit(int u, vector<int> &visited, vector<int> &result)
    {
        visited[u] = 1;
        result.push_back(u);

        
        for (unordered_map<int, int>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it)
        {
            int v = it->first;
            if (!visited[v])
                dfsVisit(v, visited, result);
        }
    }

    vector<int> dfs()
    {
        vector<int> visited(size, 0), result;
        dfsVisit(0, visited, result);
        return result;
    }

    // used kahn's algorithm(googled and understood)
    vector<int> topologicalOrdering()
    {
        vector<int> inDegree(size, 0);

        for (int u = 0; u < size; ++u)
        {
            unordered_map<int, int> neighbors = adjList[u];
            for (unordered_map<int, int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
            {
                int v = it->first;
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < size; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            unordered_map<int, int> neighbors = adjList[u];
            for (unordered_map<int, int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
            {
                int v = it->first;
                inDegree[v]--;
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }

        if (topoOrder.size() != size)
            return {}; 

        return topoOrder;
    }

    bool dfsCycleDirected(int u, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[u] = true;
        recStack[u] = true;

        unordered_map<int, int> neighbors = adjList[u];
        for (unordered_map<int, int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            int v = it->first;
            if (!visited[v])
            {
                if (dfsCycleDirected(v, visited, recStack))
                    return true;
            }
            else if (recStack[v])
            {
                return true;
            }
        }

        recStack[u] = false;
        return false;
    }
    bool dfsCycleUndirected(int u, int parent, vector<bool> &visited)
    {
        visited[u] = true;

        unordered_map<int, int> neighbors = adjList[u];
        for (unordered_map<int, int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
        {
            int v = it->first;

            if (!visited[v])
            {
                if (dfsCycleUndirected(v, u, visited))
                    return true;
            }
            else if (v != parent)
            {

                return true;
            }
        }

        return false;
    }

    bool hasCycles()
    {
        vector<bool> visited(size, false);

        if (isDirected)
        {
            vector<bool> recStack(size, false);
            for (int i = 0; i < size; ++i)
            {
                if (!visited[i])
                {
                    if (dfsCycleDirected(i, visited, recStack))
                        return true;
                }
            }
        }
        else
        {
            for (int i = 0; i < size; ++i)
            {
                if (!visited[i])
                {
                    if (dfsCycleUndirected(i, -1, visited))
                        return true;
                }
            }
        }

        return false;
    }

private:
    vector<vector<int>> getEdgeList()
    {
        vector<vector<int>> edgeList;
        for (int u = 0; u < size; u++)
        {
            unordered_map<int, int> neighbors = adjList[u];
            for (unordered_map<int, int>::iterator it = neighbors.begin(); it != neighbors.end(); ++it)
            {
                int v = it->first;
                int w = it->second;
                if (isDirected || u < v) // for undirected case
                    edgeList.push_back({u, v, w});
            }
        }
        return edgeList;
    }
};

main()
{
    Graph G1(4, {{0, 1}, {1, 3}, {2, 3}}, false), G2(4, {{0, 1}, {1, 3}, {2, 3}}, false);
    G1.addEdge(0, 3);
    G2.addEdge(0, 3);
    // cout << G1.isGraphIsomorphic(G2, {});
}