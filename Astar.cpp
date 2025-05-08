#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
    int g, h, f;
    Node* parent;

    Node(int x, int y, int g, int h, Node* parent = nullptr)
        : x(x), y(y), g(g), h(h), f(g + h), parent(parent) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);  // Manhattan distance
}

bool isValid(int x, int y, vector<vector<int>>& grid) {
    return (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0);
}

vector<Node*> aStar(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    priority_queue<Node*, vector<Node*>, Compare> openSet;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    Node* startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second));
    openSet.push(startNode);

    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};  // up, down, left, right

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (visited[current->x][current->y]) continue;
        visited[current->x][current->y] = true;

        if (current->x == goal.first && current->y == goal.second) {
            vector<Node*> path;
            while (current) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto dir : directions) {
            int nx = current->x + dir.first;
            int ny = current->y + dir.second;

            if (isValid(nx, ny, grid) && !visited[nx][ny]) {
                int g = current->g + 1;
                int h = heuristic(nx, ny, goal.first, goal.second);
                openSet.push(new Node(nx, ny, g, h, current));
            }
        }
    }

    return {};
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int sx, sy, ex, ey;
    cout << "Enter starting node: ";
    cin >> sx >> sy;

    cout << "Enter goal node: ";
    cin >> ex >> ey;

    vector<Node*> path = aStar(grid, {sx, sy}, {ex, ey});

    if (!path.empty()) {
        cout << "Path found:\n";
        for (auto node : path) {
            cout << "(" << node->x << "," << node->y << ") ";
        }
        cout << endl;
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
