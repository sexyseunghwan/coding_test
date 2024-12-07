
import java.util.*;

public class Test {

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

        BinaryTree() {}
        
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
                        que.add(curNode.left);
                    }

                    if (curNode.right == null) {
                        curNode.right = node;
                        break;
                    } else {
                        que.add(curNode.right);
                    }
                }

            }
        }
        
        List<Character> preOrderTraversal() {   
            
            List<Character> list = new ArrayList<>();
            preOrderTraversalInner(this.root, list);

            return list;
        }

        void preOrderTraversalInner(Node node, List<Character> list) {

            if (node != null) {
                list.add(node.value);
                preOrderTraversalInner(node.left, list);
                preOrderTraversalInner(node.right, list);
            }
        }

        List<Character> inOrderTraversal() {

            List<Character> list = new ArrayList<>();
            inOrderTraversalInner(this.root, list);

            return list;
        }

        void inOrderTraversalInner(Node node, List<Character> list) {

            if (node != null) {
                inOrderTraversalInner(node.left, list);
                list.add(node.value);
                inOrderTraversalInner(node.right, list);
            }

        }


        List<Character> postOrderTraversal() {
            
            List<Character> list = new ArrayList<>();
            postOrderTraversalInner(this.root, list);

            return list;
        }

        void postOrderTraversalInner(Node node, List<Character> list) {
            
            if (node != null) {
                postOrderTraversalInner(node.left, list);
                postOrderTraversalInner(node.right, list);
                list.add(node.value);
            }

        }


        List<Character> levelOrderTraversal() {

            List<Character> list = new ArrayList<>();
            levelOrderTraversalInner(this.root, list);

            return list;
        }


        void levelOrderTraversalInner(Node node, List<Character> list) {
            
            Queue<Node> que = new LinkedList<>();
            que.offer(node);

            while(!que.isEmpty()) {

                Node curNode = que.poll();
                list.add(curNode.value);
                
                if (curNode.left != null) que.offer(curNode.left);
                if (curNode.right != null) que.offer(curNode.right);
            }
        }

        
    }

    public static void main(String[] args) throws Exception {
        
        String input = "ABCDEFG";
        
        BinaryTree bt = new BinaryTree();
        

        for (int i = 0; i < input.length(); i++) {
            char ch = input.charAt(i);
            bt.insert(ch);
        }

        //List<Character> list = bt.preOrderTraversal();
        //List<Character> list = bt.postOrderTraversal();
        //List<Character> list = bt.inOrderTraversal();
        List<Character> list = bt.levelOrderTraversal();
        
        for (char c : list) {
            System.out.print(c + " ");
        }

    }

}
