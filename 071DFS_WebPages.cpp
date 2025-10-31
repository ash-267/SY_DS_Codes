/*Application:Indexing web pages for search engines.
Example: A web crawler uses BFS to visit web pages systematically, starting from a seed URL and exploring links level by level. Nodes represent web pages. Edges represent hyperlinks. BFS ensures that pages at the same "depth" (distance from the starting page) are visited before moving to deeper levels. Write a program to simulate the indexing of web pages for a search engine using a Breadth-First Search (BFS) algorithm.
*/

#include <iostream>
using namespace std;

class WebCrawler {
private:
    int vertex;           
    int edge;             
    int adj[20][20];      
    bool visited[20];     

public:
    void input() {
        cout << "Enter number of web pages: ";
        cin >> vertex;

        cout << "Enter number of hyperlinks: ";
        cin >> edge;

        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                adj[i][j] = 0;
            }
            visited[i] = false;
        }

        cout << "\nEnter hyperlinks (from to) format (0-indexed):\n";
        for (int i = 0; i < edge; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1; 
        }
    }

    void display() {
        cout << "\nAdjacency Matrix (Web Page Links):\n";
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < vertex; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        int queue[20];     
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;  

        cout << "\nBFS Traversal (Indexing Order): ";

        while (front < rear) {  
            int current = queue[front++];  
            cout << "Page " << current << " -> ";

            for (int i = 0; i < vertex; i++) {
                if (adj[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;   
                }
            }
        }

        cout << "End\n";
    }
};

int main() {
    WebCrawler crawler;
    crawler.input();
    crawler.display();

    int start;
    cout << "\nEnter starting web page (seed URL index): ";
    cin >> start;

    crawler.BFS(start);

    return 0;
}
