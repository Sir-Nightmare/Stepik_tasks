#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cell {
    int x;
    int y;
};

int operator==(cell a, cell b) {
    return (a.x == b.x) && (a.y == b.y);
}


int canGo(cell c) {
    return (c.x > 0) && (c.x < 8) && (c.y > 0) && (c.y < 8);
}

bool notVisited(cell temp, vector<cell> &visited) {
    vector<cell>::iterator it;
    it = find(visited.begin(), visited.end(), temp);
    return it == visited.end();
}

void whereToGo(cell now, vector<cell> &vecToGo, vector<cell> &visited) {
    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++) {
        cell temp = {now.x + dx[i], now.y + dy[i]};
        if (canGo(temp) && notVisited(temp, visited)) {
            visited.push_back(temp);
            vecToGo.push_back(temp);
        }
    }
}

int doEverything(vector<cell> &cellVec, vector<cell> &visited, cell lastCell) {
    int step = 0;
    while (true) {
        for (int i = 0; i < cellVec.size(); i++) {
            if (cellVec[i].x == lastCell.x && cellVec[i].y == lastCell.y) {
                return step;
            }
        }
        vector<cell> tempVec;
        step++;
        for (int i = 0; i < cellVec.size(); i++) {
            whereToGo(cellVec[i], tempVec, visited);
        }
        cellVec = tempVec;
    }
}

int main() {
    cell firstCell = {1, 2};
    cell lastCell = {2, 3};
    vector<cell> cellVec{firstCell};
    vector<cell> visited{firstCell};
    cout << doEverything(cellVec, visited, lastCell);
    return 0;
}