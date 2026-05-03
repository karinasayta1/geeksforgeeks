/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
public:
    // returns sum of subtree if valid, else -1
    int solve(Node* root) {
        // Base case
        if (!root) return 0;

        // Leaf node
        if (!root->left && !root->right) {
            return root->data;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // If any subtree is invalid
        if (leftSum == -1 || rightSum == -1) return -1;

        // Check Sum Tree condition
        if (root->data != leftSum + rightSum) return -1;

        // Return total sum of subtree
        return root->data + leftSum + rightSum;
    }

    bool isSumTree(Node* root) {
        return solve(root) != -1;
    }
};