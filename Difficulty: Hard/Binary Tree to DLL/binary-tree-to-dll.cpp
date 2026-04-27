/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
public:
    Node* prev = NULL;
    Node* head = NULL;

    void inorder(Node* root) {
        if (!root) return;

        // Left
        inorder(root->left);

        // Process current node
        if (prev == NULL) {
            head = root; // first node
        } else {
            prev->right = root;
            root->left = prev;
        }

        prev = root;

        // Right
        inorder(root->right);
    }

    Node* bToDLL(Node* root) {
        inorder(root);
        return head;
    }
};