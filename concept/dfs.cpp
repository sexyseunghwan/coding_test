#include <iostream>

// g++ -std=c++20 test.cpp -o test

// #include <utility>
// #include <cmath>
// #include <vector>
// #include <climits>

using namespace std;

int N;
int map[100][100];

int main() {

    cin >> N;

    for (int i = 0; i < N*N; i++) {
        cin >> map[i/N][i%N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    } 

}

