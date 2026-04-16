/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        
        // Base cases
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        
        int left = 0, right = 0;
        
        if(root->left) left = root->left->data;
        if(root->right) right = root->right->data;
        
        // Check current node + recursive check
        if(root->data == left + right &&
           isSumProperty(root->left) &&
           isSumProperty(root->right)) {
            return true;
        }
        
        return false;
    }
};