#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 圖的類別
class Graph {
    private:
        unordered_map<int, vector<int> > adjList; // 鄰接表

    public:
        // 新增邊
        void addEdge(int u, int v, bool isUndirected = true) {
            adjList[u].push_back(v);
            if (isUndirected) {
                adjList[v].push_back(u); // 如果是無向圖，新增反向邊
            }
        }

        // 列出圖的所有鄰接表
        void printGraph() const {
            for (const auto& pair : adjList) {
                cout << "節點 " << pair.first << " -> ";
                for (int neighbor : pair.second) {
                    cout << neighbor << " ";
                }
                cout << endl;
            }
        }

        // 檢查節點是否連通
        bool isConnected(int u, int v) const {
            if (adjList.find(u) == adjList.end()) return false;
            for (int neighbor : adjList.at(u)) {
                if (neighbor == v) return true;
            }
            return false;
        }

    };


int main() {
    Graph g;

    // 新增一些邊
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // 列印鄰接表
    cout << "圖的鄰接表:" << endl;
    g.printGraph();

    // 檢查兩個節點是否連通
    cout << "\n檢查節點是否連通:" << endl;
    cout << "0 和 4 是否連通: " << (g.isConnected(0, 4) ? "是" : "否") << endl;
    cout << "2 和 0 是否連通: " << (g.isConnected(2, 0) ? "是" : "否") << endl;
    
    return 0;
}