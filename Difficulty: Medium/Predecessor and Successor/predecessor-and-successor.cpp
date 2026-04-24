/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        Node* curr = root;
        
        while (curr != NULL) {
            if (key > curr->data) {
                pre = curr;              // possible predecessor
                curr = curr->right;
            } 
            else if (key < curr->data) {
                suc = curr;              // possible successor
                curr = curr->left;
            } 
            else {
                // predecessor → max in left subtree
                Node* temp = curr->left;
                while (temp) {
                    pre = temp;
                    temp = temp->right;
                }
                
                // successor → min in right subtree
                temp = curr->right;
                while (temp) {
                    suc = temp;
                    temp = temp->left;
                }
                break;
            }
        }
        
        return {pre, suc};
    }
};