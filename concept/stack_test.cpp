// g++ -std=c++20 stack_test.cpp -o stack_test
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

void stack_0();
void stack_1();

int main() {

    //stack_0();
    stack_1();

    return 0;
}


/* 단일값 stack */
void stack_0() {

    stack<int> stack;

    stack.push(1);
    stack.push(3);
    stack.push(5);
    stack.push(7);

    while(!stack.empty()) {

        int elem = stack.top();
        stack.pop();

        cout << elem << endl;
    }
}

/* 복수값 stack */
void stack_1() {
    
    stack<pair<int,int>> stack; /* pair 을 사용하기 위해서는 utility 를 include 해야 한다. */
    
    stack.push({1,3});
    stack.push({2,4});
    stack.push({3,5});

    while(!stack.empty()) {
        
        pair<int, int> p = stack.top();
        int first = p.first;
        int second = p.second;
        stack.pop();

        cout << first << " " << second << endl; 

    }

}
