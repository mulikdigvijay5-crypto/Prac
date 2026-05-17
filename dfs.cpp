#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

class Graph {
    map<string, list<string>> adj;

public:

    // Add Edge (Undirected)
    void addEdge(string u, string v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Recursive DFS
    void dfs(string node, set<string> &visited) {
        visited.insert(node);
        cout << node << " ";

        for (auto neighbour : adj[node]) {
            if (visited.find(neighbour) == visited.end()) {
                dfs(neighbour, visited);
            }
        }
    }

    void DFS(string start) {
        set<string> visited;
        cout << "\nDFS Traversal: ";
        dfs(start, visited);
        cout << endl;
    }

    // Recursive BFS Helper
    void bfsHelper(queue<string> &q, set<string> &visited) {
        if (q.empty()) return;

        string node = q.front();
        q.pop();
        cout << node << " ";

        for (auto neighbour : adj[node]) {
            if (visited.find(neighbour) == visited.end()) {
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }

        bfsHelper(q, visited);
    }

    void BFS(string start) {
        set<string> visited;
        queue<string> q;

        visited.insert(start);
        q.push(start);

        cout << "\nBFS Traversal: ";
        bfsHelper(q, visited);
        cout << endl;
    }
};

int main() {
    Graph g;
    int choice;

    while (true) {
        cout << "\n----- MAIN MENU -----";
        cout << "\n1. Add Edges";
        cout << "\n2. Depth First Search (DFS)";
        cout << "\n3. Breadth First Search (BFS)";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number of edges: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                string u, v;
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.addEdge(u, v);
            }
        }
        else if (choice == 2) {
            string start;
            cout << "Enter starting vertex for DFS: ";
            cin >> start;
            g.DFS(start);
        }
        else if (choice == 3) {
            string start;
            cout << "Enter starting vertex for BFS: ";
            cin >> start;
            g.BFS(start);
        }
        else if (choice == 4) {
            cout << "\nProgram Ended.\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
