// g++ -std=c++20 2468_1.cpp -o 2468
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[100][100];
int visited[100][100];
int max_height;
int min_height;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int max_safety_zone;



void dfs(int r, int c, int h) {
    
    visited[r][c] = 1;

    for (int i = 0; i < 4; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];

        if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N && map[new_r][new_c] > h && visited[new_r][new_c] == 0) {
            dfs(new_r, new_c, h);
        }
    }
}

int get_safety_zone(int height) {

    int safety_cnt = 0;

    // 방문 배열 초기화
    for (int i = 0; i < N*N; i++) {
        visited[i/N][i%N] = 0;
    }    
    
    for (int i = 0; i < N*N; i++) {
        int row = i/N;
        int col = i%N;
        
        if (map[row][col] > height && visited[row][col] == 0) {
            ++safety_cnt;
            dfs(row, col, height);
        }
    }
    
    return safety_cnt;
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N*N; i++) {
        int num;
        cin >> num;

        max_height = max(num, max_height);
        min_height = min(num, min_height);
        map[i/N][i%N] = num;
    }
    

    for (int i = min_height; i < max_height; i++) {
        int safety_cnt = get_safety_zone(i);
        max_safety_zone = max_safety_zone > safety_cnt ? max_safety_zone : safety_cnt;
    }
    
    cout << max_safety_zone << endl;
}