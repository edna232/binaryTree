#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};


class BinaryTree {
public:
    Node* root;


    BinaryTree() {
        root = NULL;
    }

    
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    Node* insertRecursive(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else {
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    void deleteNode(int value) {
        root = deleteRecursive(root, value);
    }

    Node* deleteRecursive(Node* root, int value) {
        if (root == NULL) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRecursive(root->right, value);
        } else {
        
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

        
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRecursive(root->right, temp->data);
        }
        return root;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }
    bool search(int value) {
        return searchRecursive(root, value);
    }

    bool searchRecursive(Node* node, int value) {
        if (node == NULL) {
            return false;
        }
        if (node->data == value) {
            return true;
        }
        return (value < node->data) ? searchRecursive(node->left, value) : searchRecursive(node->right, value);
    }


    void inorderTraversal() {
        inorderRecursive(root);
        cout << endl;
    }

    void inorderRecursive(Node* node) {
        if (node != NULL) {
            inorderRecursive(node->left);
            cout << node->data << " ";
            inorderRecursive(node->right);
        }
    }

    void preorderTraversal() {
        preorderRecursive(root);
        cout << endl;
    }

    void preorderRecursive(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorderRecursive(node->left);
            preorderRecursive(node->right);
        }
    }

    void postorderTraversal() {
        postorderRecursive(root);
        cout << endl;
    }

    void postorderRecursive(Node* node) {
        if (node != NULL) {
            postorderRecursive(node->left);
            postorderRecursive(node->right);
            cout << node->data << " ";
        }
    }

    
    int height() {
        return calculateHeight(root);
    }

    int calculateHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {
    BinaryTree tree;


    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order Traversal: ";
    tree.inorderTraversal();

    cout << "Pre-order Traversal: ";
    tree.preorderTraversal();

    cout << "Post-order Traversal: ";
    tree.postorderTraversal();

    cout << "Height of the tree: " << tree.height() << endl;


    int searchVal = 60;
    if (tree.search(searchVal)) {
        cout << "Value " << searchVal << " found in the tree." << endl;
    } else {
        cout << "Value " << searchVal << " not found in the tree." << endl;
    }

    cout << "Deleting node 20" << endl;
    tree.deleteNode(20);
    tree.inorderTraversal();

    return 0;
}

