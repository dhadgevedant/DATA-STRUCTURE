/********************************************************************************************
 problem definition : 

	you are planning your wedding and need to select marriage hall location from a list of available options you want to find the
    shortest path from your current location to visit all the marriage location and determine the optimal rule that minimize ravel 
    distance and time use appropriate data structure and algorithm to implement it.
**************************************************************/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph() {
        V = 0;
    }

    void createGraph() {
        cout << "Enter number of vertices: ";
        cin >> V;
        adjMatrix.resize(V, vector<int>(V));

        cout << "Enter the adjacency matrix (use 0 if no edge):\n";
        for (int i = 0; i < V; i++) {
            for (int j = i+ 1; j < V; j++) {
                cin >> adjMatrix[i][j];
                adjMatrix[j][i] = adjMatrix[i][j];
            }
        }

        cout << "Graph created successfully.\n";
    }

    void displayGraph() {
        if (V == 0) {
            cout << "Graph is empty.\n";
            return;
        }

        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void dijkstra(int start) {
        if (V == 0) {
            cout << "Graph not created yet.\n";
            return;
        }

        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        dist[start] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = findMinVertex(dist, visited);
            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && adjMatrix[u][v] &&
                    dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "\nShortest distances from vertex " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "To " << i << " = ";
            if (dist[i] == INT_MAX)
                cout << "INF";
            else
                cout << dist[i];
            cout << "\n";
        }
    }

private:
    int findMinVertex(const vector<int>& dist, const vector<bool>& visited) {
        int minDist = INT_MAX, minIndex = -1;
        for (int i = 0; i < V; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
};

int main() {
    Graph g;
    int choice, start;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Create Graph\n";
        cout << "2. Run Dijkstra's Algorithm\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.createGraph();
                break;

            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.dijkstra(start);
                break;

            case 3:
                g.displayGraph();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
