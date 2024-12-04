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

    def postorder(self):
        result = []
        self._postorder_helper(self.root, result)
        return ''.join(result)
    
    def _postorder_helper(self, node, result):
        if node:
            self._postorder_helper(node.left, result)
            self._postorder_helper(node.right, result)
            result.append(node.value)

def encrypt_message(message):
    binary_tree = BinaryTree()
    for char in message:
        binary_tree.insert(char)
    return binary_tree.postorder()

# Test the encryption function
message = "ABCDEF"
encrypted_message = encrypt_message(message)
print("Encrypted message:", encrypted_message)  # Expected: "DEBFCA"
