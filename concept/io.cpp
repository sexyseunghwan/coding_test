#include <iostream>
#include <string>

using namespace std;

void io_0();
void io_1();
void io_2();


// g++ -std=c++20 io.cpp -o io

int main() {

    /* 알고리즘 문제에서는 문제의 파라미터를 받는 방법이 존재한다. */ 

    //io_0(); /* 1차 배열 처리 */
    //io_1(); /* 정방행렬 처리 */
    io_2(); /* 비정방행렬 처리 */

}


/* 1차 배열 처리 */
void io_0() {
    
/*
1 3 5 7 9
*/
    // 1. 위와 같이 whitespace 로 구분되어 있는 경우
    // int N = 5;
    // int arr[N];

    // for (int i = 0; i < N; i++) {
    //     cin >> arr[i];
    // }

/*
13579
*/
    // 2. 위와 같이 다 같이 붙어있는 경우
    int N = 5;
    int arr[N];
    string input;

    cin >> input;

    for (int i = 0; i < N; i++) {
        arr[i] = input[i] - '0';
    }

    

    cout << "========================" << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }

}


/* 2차 정방행렬 처리 */ 
void io_1() {

/*
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7

    위와 같은 정방행렬(N*N)을 받는 방법
*/
    
    // int N = 5; // 정방행렬의 행,열 크기
    // int matrix[N][N];

    // 1. 기본적인 방법
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    // 2. 1중 loop 로 데이터를 받는 방법
    // for (int i = 0; i < N*N; i++) {
    //     cin >> matrix[i/N][i%N]; 
    // }


/*
68262
32346
67332
72536
89527

    위와 같은 정방행렬(N*N)을 받는 방법
*/

    int N = 5;
    int matrix[N][N];
    
    // 1. 기본적인 방법
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < N; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }

    cout << "====================" << endl;
    for (int i = 0; i< N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
}

/* 비정방행렬 처리 */ 
void io_2() {

/*

6 8 2
3 2 3
6 7 3
7 2 5
8 9 5

*/
    // int N = 5; // 행
    // int M = 3; // 렬
    // int matrix[N][M];

    // 1. 기본적인 방법
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cin >> matrix[i][j];
    //     }
    // }

    // 2. 1차 루프로 해결하는 방법
    // for (int i = 0; i < N*M; i++) {
    //     cin >> matrix[i/M][i%M];
    // }

/*

682
323
673
725
895

*/
    int N = 5; // 행
    int M = 3; // 렬
    int matrix[N][M];

    
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        for (int j = 0; j< M; j++) {
            matrix[i][j] = input[j] - '0';
        }
    }


    cout << "====================" << endl;
    for (int i = 0; i< N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }





}