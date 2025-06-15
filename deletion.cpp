    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return NULL;

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Node found

            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // Case 2: One child
            else if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            Node* temp = findMin(root->right); // Inorder successor
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }
};
