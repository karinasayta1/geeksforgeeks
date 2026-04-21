/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
public:
    int count = 0;
    int ans = -1;

    void reverseInorder(Node* root, int k) {
        if (!root || count >= k) return;

        // Go to larger elements first
        reverseInorder(root->right, k);

        count++;
        if (count == k) {
            ans = root->data;
            return;
        }

        reverseInorder(root->left, k);
    }

    int kthLargest(Node *root, int k) {
        reverseInorder(root, k);
        return ans;
    }
};