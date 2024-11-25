// g++ -std=c++20 array.cpp -o array
#include <iostream>
#include <cstring>

using namespace std;


void array_0();
void array_1();


int main() {

    //array_0();
    array_1();
}

/* 배열 초기화 하는 방법 - 1차원 배열*/
void array_0() {
    
    int arr[5] = {1,2,3,4,5};

    // 기본적으로 배열을 초기화 하는방법
    // for (int i = 0; i < 5; i++) {
    //     arr[i] = 0;
    // }

    // memset 을 통한 배열초기화 방법 -> <cstring> include 필요함.
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}

/* 배열 초기화 하는 방법 - 2차원 배열*/
void array_1() {

    int arr[2][3] = {
        {1,3,5},
        {2,4,6}
    };

    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}