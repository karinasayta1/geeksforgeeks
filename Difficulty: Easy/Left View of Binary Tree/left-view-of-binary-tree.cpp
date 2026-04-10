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
void solve(Node* root, int level, vector<int>& result) {
    if (root == NULL)
        return;
    
    // First node at this level
    if (level == result.size())
        result.push_back(root->data);
    
    solve(root->left, level + 1, result);
    solve(root->right, level + 1, result);
}
class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> result;
        solve(root, 0, result);
        return result;
    }
};