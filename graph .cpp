#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int minDistance(vector<int>& dist, vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 1; v < dist.size(); v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void displayResults(vector<int>& dist, vector<int>& parent, int src, int dest) {
    cout << "\nTitik\tJarak Terpendek\tJalur Terpendek\n";
    cout << dest << "\t" << dist[dest] << "\t\t";

    stack<int> path;
    int current = dest;
    while (current != src) {
        path.push(current);
        current = parent[current];
    }
    path.push(src);

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    cout << endl;
}

void dijkstra(vector<vector<int> >& graph, int src, int dest) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX); 
    vector<bool> sptSet(V, false);
    vector<int> parent(V, -1); 

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 1; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    displayResults(dist, parent, src, dest);
}

void inputGraph(vector<vector<int> >& graph) {
    int node, edge;

    cout << "Masukkan jumlah node (V): ";
    cin >> node;

    while (node <= 0) {
        cout << "Jumlah node harus lebih besar dari 0. Ulangi input.\n";
        cout << "Masukkan jumlah node (V): ";
        cin >> node;
    }

    cout << "Masukkan jumlah edge (E): ";
    cin >> edge;

    while (edge <= 0) {
        cout << "Jumlah edge harus lebih besar dari 0. Ulangi input.\n";
        cout << "Masukkan jumlah edge (E): ";
        cin >> edge;
    }

    graph = vector<vector<int> >(node + 1, vector<int>(node + 1, 0));

    cout << "\nMasukkan nilai bobot untuk setiap edge:\n";
    for (int i = 0; i < edge; i++) {
        int u, v, weight;
        cout << "Edge " << i + 1 << " (u v weight): ";

        cin >> u >> v >> weight;
        while (u <= 0 || v <= 0 || u > node || v > node) {
            cout << "Node harus lebih besar dari 0 dan tidak boleh lebih besar dari jumlah node. Ulangi input.\n";
            cout << "Edge " << i + 1 << " (u v weight): ";
            cin >> u >> v >> weight;
        }

        graph[u][v] = weight;
        graph[v][u] = weight; 
    }
}

int main() {
    vector<vector<int> > graph;
    
    cout << "Graph Aplication\n\n";

    inputGraph(graph);

    int startNode, endNode;
    cout << "\nMasukkan titik awal: ";
    cin >> startNode;

    cout << "Masukkan titik akhir: ";
    cin >> endNode;

    if (startNode >= 1 && startNode <= graph.size() - 1 && endNode >= 1 && endNode <= graph.size() - 1) {
        dijkstra(graph, startNode, endNode);
    } else {
        cout << "Titik awal atau akhir tidak valid.\n";
    }

    return 0;
}
