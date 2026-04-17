/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:

    // Step 1: Build parent mapping
    void markParents(Node* root, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            if(curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    int minTime(Node* root, int target) {

        // Step 2: Create parent map
        unordered_map<Node*, Node*> parent;
        markParents(root, parent);

        // Step 3: Find target node
        Node* targetNode = NULL;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if(curr->data == target) {
                targetNode = curr;
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        // Step 4: BFS from target
        unordered_map<Node*, bool> visited;
        queue<Node*> burn;

        burn.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while(!burn.empty()) {

            int size = burn.size();
            bool burnedSomething = false;

            for(int i = 0; i < size; i++) {
                Node* curr = burn.front();
                burn.pop();

                // left
                if(curr->left && !visited[curr->left]) {
                    burn.push(curr->left);
                    visited[curr->left] = true;
                    burnedSomething = true;
                }

                // right
                if(curr->right && !visited[curr->right]) {
                    burn.push(curr->right);
                    visited[curr->right] = true;
                    burnedSomething = true;
                }

                // parent
                if(parent[curr] && !visited[parent[curr]]) {
                    burn.push(parent[curr]);
                    visited[parent[curr]] = true;
                    burnedSomething = true;
                }
            }

            // increase time only if fire spread
            if(burnedSomething) time++;
        }

        return time;
    }
};