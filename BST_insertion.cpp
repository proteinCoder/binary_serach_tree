class Solution {
  public:
    Node* insert(Node* root, int key) {
        if (!root) {
            return new Node(key);
        }

        if(key == root->data) return root;

        if (key < root->data) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }

        return root;
    }
