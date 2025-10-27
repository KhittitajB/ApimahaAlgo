#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

unordered_map<int, vector<int>> read_graph() {
    unordered_map<int, vector<int>> graph;
    
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    return graph;
}


// --- Example Usage ---
int main() {
    cout << "Creating a new graph...\n";
    
    // Call the shortcut function
    unordered_map<int, vector<int>> my_graph = read_graph();

    cout << "\nGraph creation complete.\n";
    cout << "Adjacency List:\n";

    // We can use 'map' (which is sorted) to print the output
    // in a clean, node-by-node order.
    map<int, vector<int>> sorted_graph(my_graph.begin(), my_graph.end());

    for (const auto& pair : sorted_graph) {
        cout << pair.first << ": [ ";
        for (int neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << "]\n";
    }

    return 0;
}