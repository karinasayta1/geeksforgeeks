/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // recursive approach with recursion
      bool isMirror(Node* leftTree, Node* rightTree) {
        // Both null → symmetric
        if (leftTree == NULL && rightTree == NULL)
            return true;
        
        // One null → not symmetric
        if (leftTree == NULL || rightTree == NULL)
            return false;
        
        // Check value + recursive mirror
        return (leftTree->data == rightTree->data) &&
               isMirror(leftTree->left, rightTree->right) &&
               isMirror(leftTree->right, rightTree->left);
    }
    
    bool isSymmetric(Node* root) {
        // code here
         if (root == NULL)
            return true;
        
        return isMirror(root->left, root->right);
    }
};