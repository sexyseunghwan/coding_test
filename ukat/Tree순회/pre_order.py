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
        
        new_node = Node(value)
        
        if not self.root: 
            self.root = new_node
        else:
            queue = deque([self.root])
            
            while queue:
                current = queue.popleft()

                if not current.left:
                    current.left = new_node
                    break
                else:
                    queue.append(current.left)

                if not current.right:
                    current.right = new_node
                    break
                else:
                    queue.append(current.right)
    

    def pre_order_traversal(self, node):
        result = []
        self._pre_order_traversal(node,result)
        return result

    def _pre_order_traversal(self, node, result):
        
        if node:
            result.append(node.value)
            self._pre_order_traversal(node.left, result)
            self._pre_order_traversal(node.right, result)


    def post_order_traversal(self, node):
        result = []
        self._post_order_traversal(node, result)
        return result

    def _post_order_traversal(self, node, result):

        if node:
            self._post_order_traversal(node.left, result)
            self._post_order_traversal(node.right, result)
            result.append(node.value)
        
    def in_order_traversal(self, node):
        result = []
        self._in_order_traversal(node, result)
        return result
    
    def _in_order_traversal(self, node, result):

        if node:
            self._post_order_traversal(node.left, result)
            result.append(node.value)   
            self._post_order_traversal(node.right, result)
        
    def level_order_traversal(self, node):
        result = []
        self._level_order_traversal(node, result)
        return result

    def _level_order_traversal(self, node, result):
        
        if not self.root:
            return
        
        queue = deque([self.root])

        while queue:
            node = queue.popleft()
            result.append(node.value)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)



message = "ABCDEFG"
binary_tree = BinaryTree()

for char in message:
    binary_tree.insert(char)

print("Pre-order traversal:")
array = binary_tree.pre_order_traversal(binary_tree.root)
print(array)

print("Post-order traversal:")
array = binary_tree.post_order_traversal(binary_tree.root)
print(array)

print("In-order traversal:")
array = binary_tree.in_order_traversal(binary_tree.root)
print(array)

print("Level-order traversal:")
array = binary_tree.level_order_traversal(binary_tree.root)
print(array)

