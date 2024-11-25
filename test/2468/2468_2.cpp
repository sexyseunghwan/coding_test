// g++ -std=c++20 2468_2.cpp -o 2468
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int N;
int map[100][100];
bool visited[100][100];
int min_height;
int max_height;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
int max_safety_cnt;

void bfs(int height, int r, int c) {

    queue<pair<int, int>> que;
    que.push({r,c});
    
    while(!que.empty()) {

        pair<int,int> pair = que.front();
        que.pop();
        visited[pair.first][pair.second] = true;
        int elem = map[pair.first][pair.second];
        

    }

}


int find_safety_area(int height) {

    int safety_cnt = 0;

    for (int i = 0; i < N*N; i++) {
        int r = i/N;
        int c = i%N;

        if (map[r][c] > height && !visited[r][c]) {
            ++safety_cnt;
            bfs(height, r, c);
        }
    }
    
    return safety_cnt;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    
    for (int i = 0; i < N*N; i++) {
        int input;
        cin >> input;

        min_height = min(min_height, input);
        max_height = max(max_height, input);    

        map[i/N][i%N] = input;       
    }
    
    
    for (int i = min_height - 1; i < max_height; i++) {
        max_safety_cnt = max(max_safety_cnt, find_safety_area(i));
    }

    cout << max_safety_cnt << endl;
    
    return 0;
}