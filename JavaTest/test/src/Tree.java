import java.util.*;

public class Tree {
    
    static class Node {
        char value;
        Node left;
        Node right;

        Node(char value) {
            this.value = value;
        }
    }


    static class BinaryTree {
        Node root;
        
        void insert(char value) {
            
            Node node = new Node(value);

            if (this.root == null) {
                this.root = node;
            } else {

                Queue<Node> que = new LinkedList<>();
                que.add(this.root);
                
                while(!que.isEmpty()) {

                    Node curNode = que.poll();

                    if (curNode.left == null) {
                        curNode.left = node;
                        break;
                    } else {
                        que.offer(curNode.left);
                    }

                    if (curNode.right == null) {
                        curNode.right = node;
                        break;
                    } else {
                        que.offer(curNode.right);
                    }
                }
            }
        }


        List<Character> preOrderTraversal() {

            List<Character> list = new ArrayList<>();
            _preOrderTraversal(list, this.root);

            return list;
        }

        void _preOrderTraversal(List<Character> list, Node node) {
            
            if (node != null) {
                list.add(node.value);
                _preOrderTraversal(list, node.left);
                _preOrderTraversal(list, node.right);
            }
            
        }

    }
        

    public static void main(String[] args) {
        
        String input = "ABCDEFG";
        
        BinaryTree bt = new BinaryTree();

        for (int i = 0; i < input.length(); i++) {
            char c = input.charAt(i);
            bt.insert(c);
        }

        List<Character> list = bt.preOrderTraversal();
        
        for (char c : list) {
            System.out.print(c + " ");
        }


    }
}
