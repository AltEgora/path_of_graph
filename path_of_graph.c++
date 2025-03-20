#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

void bfs(int start, const std::vector<std::vector<int>>& graph, std::vector<int>& distances) {
    std::queue<int> q;
    distances[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : graph[cur]) {
            if (distances[i] == -1) {
                distances[i] = distances[cur] + 1;
                q.push(i);
            }
        }
    }
}

int main() {
    std::ifstream input("graph.txt");
    if (!input.is_open()) {
        std::cerr << "Ошибка при открытии файла" << std::endl;
        return 1;
    }

    int tops, ribs;
    input >> tops >> ribs;

    std::vector<std::vector<int>> graph(tops);
    for (int i = 0; i < ribs; ++i) {
        int x, y;
        input >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int starttop;
    input >> starttop;
    input.close();
    std::vector<int> distances(tops, -1);

    bfs(starttop, graph, distances);

    for (int i : distances) {
        std::cout << i << '\n';
    }
    return 0;
}
