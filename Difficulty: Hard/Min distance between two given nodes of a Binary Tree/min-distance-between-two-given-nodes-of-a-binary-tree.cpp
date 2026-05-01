/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    // Find Lowest Common Ancestor
    Node* LCA(Node* root, int a, int b) {
        if (!root) return NULL;
        
        if (root->data == a || root->data == b)
            return root;
        
        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        
        if (left && right) return root;
        
        return left ? left : right;
    }
    
    // Find distance from root to target node
    int getDist(Node* root, int target, int dist) {
        if (!root) return -1;
        
        if (root->data == target)
            return dist;
        
        int left = getDist(root->left, target, dist + 1);
        if (left != -1) return left;
        
        return getDist(root->right, target, dist + 1);
    }
    
    int findDist(Node* root, int a, int b) {
        Node* lca = LCA(root, a, b);
        
        int d1 = getDist(lca, a, 0);
        int d2 = getDist(lca, b, 0);
        
        return d1 + d2;
    }
};