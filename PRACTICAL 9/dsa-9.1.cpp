#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10];
bool visited[10];

// Depth First Search (DFS)
void DFS(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int next : graph[node]) {
        if (!visited[next]) {
            DFS(next);
        }
    }
}

// Breadth First Search (BFS)
void BFS(int start) {
    queue<int> q;
    bool seen[10] = {false};

    q.push(start);
    seen[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int next : graph[node]) {
            if (!seen[next]) {
                seen[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, edges, u, v, start;

    cout << "Enter number of buildings: ";
    cin >> n;

    cout << "Enter number of roads: ";
    cin >> edges;

    cout << "Enter roads (u v):\n";

    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter starting building: ";
    cin >> start;

    cout << "DFS Traversal: ";
    for (int i = 0; i < 10; i++)
        visited[i] = false;
    DFS(start);

    cout << "\nBFS Traversal: ";
    BFS(start);

    cout << endl;
    return 0;
}