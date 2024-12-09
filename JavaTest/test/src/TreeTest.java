import java.util.*;


public class TreeTest {
    
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

        void insert(char val) {
            
            Node node = new Node(val);

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

        List<Character> preOrder() {
            List<Character> list = new ArrayList<>();
            innerPreOrder(list, this.root);

            return list;
        }

        void innerPreOrder(List<Character> list, Node node) {
            if (node != null) {
                list.add(node.value);
                innerPreOrder(list, node.left);
                innerPreOrder(list, node.right);
            }
        }


        List<Character> levelOrder() {
            List<Character> list = new ArrayList<>();
            innerLevelOrder(list, this.root);

            return list;
        }


        void innerLevelOrder(List<Character> list, Node node) {
            
            Queue<Node> que = new LinkedList<>();
            que.offer(node);

            while(!que.isEmpty()) {
                
                Node curNode = que.poll();
                list.add(curNode.value);

                if (curNode.left != null) {
                    que.offer(curNode.left);
                }

                if (curNode.right != null) {
                    que.offer(curNode.right);
                }

            }


        }

    }


    public static void main(String[] args) {
        
        String str = "ABCDEFG";
        BinaryTree bt = new BinaryTree();

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            bt.insert(c);
        }
        
        //List<Character> list = bt.preOrder();
        List<Character> list = bt.levelOrder();
        System.out.println(list);
        

    }
}
