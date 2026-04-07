/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    // Check if node is leaf
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }
    
    // Add left boundary (excluding leaves)
    void addLeft(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    
    // Add all leaf nodes
    void addLeaves(Node* root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        
        if (root->left) addLeaves(root->left, res);
        if (root->right) addLeaves(root->right, res);
    }
    
    // Add right boundary (excluding leaves, in reverse)
    void addRight(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> temp;
        
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        // reverse add
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if (!root) return res;
        
        // Add root (if not leaf)
        if (!isLeaf(root))
            res.push_back(root->data);
        
        addLeft(root, res);     // left boundary
        addLeaves(root, res);   // leaf nodes
        addRight(root, res);    // right boundary
        
        return res;
    }
};