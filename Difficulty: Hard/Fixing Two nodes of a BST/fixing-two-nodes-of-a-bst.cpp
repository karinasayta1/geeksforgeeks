/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    Node* first = NULL;
    Node* middle = NULL;
    Node* last = NULL;
    Node* prev = NULL;

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        // violation
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    void correctBST(Node* root) {
        inorder(root);

        // fix swapped nodes
        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }
};