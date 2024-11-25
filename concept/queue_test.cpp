// g++ -std=c++20 queue_test.cpp -o queue_test
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void queue_0();
void queue_1();

int main() {

    //queue_0();    
    queue_1();

    return 0;
}


/* 단일값 queue */
void queue_0() {

    queue<int> que;
    
    que.push(10);
    que.push(20);
    que.push(30);
    
    while(!que.empty()) {

        int elem = que.front();
        que.pop();

        cout << elem << endl;
    }
}

/* 복수값 queue */
void queue_1() {
    
    queue<pair<int, int>> que;

    que.push({1,3});
    que.push({5,7});
    que.push({2,4});


    while(!que.empty()) {

        pair<int, int> p = que.front();
        que.pop();
        int first = p.first;
        int second = p.second;

        cout << first << " " << second << endl;
    }  

} 