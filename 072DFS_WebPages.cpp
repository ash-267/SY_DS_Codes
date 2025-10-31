/*Application: Web crawlers use DFS to explore web pages systematically, 
 * following links and indexing content for search engines. 
 * Write a simple program to index web pages using Depth First Search (DFS). 
 * The program should simulate a web graph where pages are represented as nodes and hyperlinks as edges.
 */
#include <iostream>

using namespace std;

void dfs(int node, bool visited[], int graph[10][10], int n) {
    visited[node] = true;
    cout << "Indexed Page: " << node << endl;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, visited, graph, n);
        }
    }
}

int main() {
    int n;
    cout << "Enter number of web pages: ";
    cin >> n;

    int graph[10][10];
    bool visited[10] = {false};

    cout << "Enter adjacency matrix (1 = link exists, 0 = no link):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    cout << "Enter starting web page (0 to " << n-1 << "): ";
    cin >> start;

    cout << "\n--- Web Crawling Order ---\n";
    dfs(start, visited, graph, n);

    cout << "\nAll reachable pages from " << start << " have been indexed.\n";
    return 0;
}
