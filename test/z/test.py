from collections import deque


class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
    
class BinaryTree:
    
    def __init__(self):
        self.root = None
    
    def insert(self, value):

        node = Node(value)

        if (not self.root):
            self.root = node
        else:
            
            que = deque([self.root])

            while que: 
                
                cur_node = que.popleft()

                if not cur_node.left:
                    cur_node.left = node
                    break
                else:
                    que.append(cur_node.left)

                if not cur_node.right:
                    cur_node.right = node
                    break
                else:
                    que.append(cur_node.right)

    def pre_order_traversal(self):
        list = []
        self._pre_order_traversal(list, self.root)

        return list        

    def _pre_order_traversal(self, list, node):

        if node:
            list.append(node.value)
            self._pre_order_traversal(list, node.left)
            self._pre_order_traversal(list, node.right)
    
    
    



str = "ABCDEFG"
bt = BinaryTree()

for char in str:
    bt.insert(char)

list = bt.pre_order_traversal()

for char in list:
    print(char)