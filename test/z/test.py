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
    

    def in_order_traversal(self):
        list = []
        self._in_order_traversal(list, self.root)

        return list     
    
    def _in_order_traversal(self, list, node):
        
        if node:
            self._in_order_traversal(list, node.left)
            list.append(node.value)
            self._in_order_traversal(list, node.right)


    def post_order_traversal(self):
        list = []
        self._post_order_traversal(list, self.root)

        return list

    def _post_order_traversal(self, list, node):

        if node:
            self._post_order_traversal(list, node.left)
            self._post_order_traversal(list, node.right)
            list.append(node.value)        


    def level_order_traversal(self):
        list = []
        self._level_order_traversal(list, self.root)

        return list

    def _level_order_traversal(self, list, node):
        
        que = deque([node])

        while que:
            cur_node = que.popleft()
            list.append(cur_node.value)

            if cur_node.left:
                que.append(cur_node.left)
            if cur_node.right:
                que.append(cur_node.right)



str = "ABCDEFG"
bt = BinaryTree()

for char in str:
    bt.insert(char)

list = bt.pre_order_traversal()
print(list)

list = bt.in_order_traversal()
print(list)

list = bt.post_order_traversal()
print(list)

list = bt.level_order_traversal()
print(list)