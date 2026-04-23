/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (root == NULL) return NULL;

        // If both nodes are smaller → go left
        if (n1->data < root->data && n2->data < root->data)
            return LCA(root->left, n1, n2);

        // If both nodes are greater → go right
        if (n1->data > root->data && n2->data > root->data)
            return LCA(root->right, n1, n2);

        // Otherwise, this is the split point → LCA
        return root;
    }
};