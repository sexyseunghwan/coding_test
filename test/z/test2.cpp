// g++ -std=c++20 test2.cpp -o test2
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


class Node {
public:
    char value;
    Node* left;
    Node* right;

    Node(char val): value(val), left(nullptr), right(nullptr) {}
};


class BinaryTree {
public:
    Node* root;
    
    BinaryTree(): root(nullptr) {}

    void insert_value(char val) {
        
        Node* node = new Node(val);
        
        if (root == nullptr) {
            root = node;
        } else {
            
            queue<Node*> que;
            que.push(root);
            
            while(!que.empty()) {
                
                Node* cur = que.front();
                que.pop();
                
                if (cur->left == nullptr) {
                    cur->left = node;
                    break;
                } else {
                    que.push(cur->left);          
                }

                if (cur->right == nullptr) {
                    cur->right = node;
                    break;
                } else {
                    que.push(cur->right);
                }
            } 
        }
    }

    vector<char> pre_order_traversal() {    

        vector<char> vec;
        _pre_order_traversal(root, vec);

        return vec;
    }
    
    void _pre_order_traversal(Node* node, vector<char> &vec) {
        if (node != nullptr) {
            vec.push_back(node->value);
            _pre_order_traversal(node->left, vec);
            _pre_order_traversal(node->right, vec);
        }
    }   

    vector<char> in_order_traversal() {

        vector<char> vec;
        _in_order_traversal(root, vec);

        return vec;
    }

    void _in_order_traversal(Node* node, vector<char> &vec) {
        
        if (node != nullptr) {
            _in_order_traversal(node->left, vec);
            vec.push_back(node->value);
            _in_order_traversal(node->right, vec);
        }

    }

    vector<char> post_order_traversal() {

        vector<char> vec;
        _post_order_traversal(root, vec);

        return vec;

    }

    void _post_order_traversal(Node* node, vector<char> &vec) {

        if (node != nullptr) {
            _post_order_traversal(node->left, vec);
            _post_order_traversal(node->right, vec);
            vec.push_back(node->value);
        }
    }

    vector<char> level_order_traversal() {

        vector<char> vec;
        _level_order_traversal(root, vec);
        return vec;

    }

    void _level_order_traversal(Node* node, vector<char> &vec) {
        
        queue<Node*> que;
        que.push(node);        

        while(!que.empty()) {
            
            Node* cur_node= que.front();
            que.pop();
            vec.push_back(cur_node->value);

            if (cur_node->left != nullptr) que.push(cur_node->left);
            if (cur_node->right != nullptr) que.push(cur_node->right);
        }

        // if (node != nullptr) {

        //     if (node->left != nullptr) {
        //         _level_order_traversal(node->left, vec);
        //     } else {
        //         vec.push_back(node->value);
        //     }

        //     if (node->right != nullptr) {
        //         _level_order_traversal(node->right, vec);
        //     } else {
        //         vec.push_back(node->value);
        //     }
            

        // }
        
        // queue<Node*> que;
        // que.push(node);

        // while(!que.empty()) {
            
        //     Node* node = que.front();
        //     que.pop();
            


        // }
        
    }

};


int main() {

    string str = "ABCDEFG";

    BinaryTree bt = BinaryTree();
    
    for (const char& c : str) {
        bt.insert_value(c);
    }

    //vector<char> vec = bt.pre_order_traversal();
    //vector<char> vec = bt.in_order_traversal();
    //vector<char> vec = bt.post_order_traversal();
    vector<char> vec = bt.level_order_traversal();
    
    for (const char& c : vec) {
        cout << c << " ";
    }

    return 0;
}
