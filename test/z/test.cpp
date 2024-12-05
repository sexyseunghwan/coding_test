// g++ -std=c++20 test.cpp -o test
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    char value;
    Node* left;
    Node* right;

    Node(char value): value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree(): root(nullptr) {}

    void insert(char value) {   
        
        Node* node = new Node(value);
        
        if (root == nullptr) {
            root = node;
        } else {
            
            queue<Node*> que;
            que.push(root);
            
            while (!que.empty()) {
                
                Node* cur_node = que.front();
                que.pop();

                if (cur_node->left == nullptr) {
                    cur_node->left = node;
                    break;
                } else {
                    que.push(cur_node->left);
                }
                
                if (cur_node->right == nullptr) {
                    cur_node->right = node;
                    break;
                } else {
                    que.push(cur_node->right);
                }
            } 
        }
    }

    void _pre_order_traversal(Node* node, vector<char> &vec) {

        if (node != nullptr) {
            vec.push_back(node->value);
            _pre_order_traversal(node->left, vec);
            _pre_order_traversal(node->right, vec);
        } 
    }
    
    vector<char> pre_order_traversal() {
        vector<char> vec;
        _pre_order_traversal(root, vec);
        return vec;
    }
};


int main() {

    string input = "ABCDEFG";
    BinaryTree bt = BinaryTree();

    for (const char& c : input) {
        bt.insert(c);
    }
    
    vector<char> result = bt.pre_order_traversal();

    for (const char& c : result) {
        cout << c << " ";
    }
    
    return 0;
}


