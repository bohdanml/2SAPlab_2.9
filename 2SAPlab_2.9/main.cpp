#include <iostream>

struct Node {
    int mainData;
    char auxiliaryData;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int mainValue, char auxiliaryValue) {
    Node* newNode = new Node();
    newNode->mainData = mainValue;
    newNode->auxiliaryData = auxiliaryValue;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a new node into the binary tree
void insertNode(Node*& root, int mainValue, char auxiliaryValue) {
    if (root == nullptr) {
        root = createNode(mainValue, auxiliaryValue);
    }
    else {
        if (mainValue <= root->mainData) {
            insertNode(root->left, mainValue, auxiliaryValue);
        }
        else {
            insertNode(root->right, mainValue, auxiliaryValue);
        }
    }
}

// Function to print the binary tree (pre-order traversal)
void printTree(Node* root, int depth = 0) {
    if (root == nullptr) return;
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
    std::cout << "|--(" << root->mainData << ", " << root->auxiliaryData << ")" << std::endl;
    printTree(root->left, depth + 1);
    printTree(root->right, depth + 1);
}

// Function to find the last node with maximum value
Node* findMax(Node* root) {
    if (root == nullptr || root->right == nullptr) {
        return root;
    }
    return findMax(root->right);
}

int main() {
    Node* root = nullptr;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the values of the elements (integer and character):\n";
    for (int i = 0; i < n; ++i) {
        int mainValue;
        char auxiliaryValue;
        std::cin >> mainValue >> auxiliaryValue;
        insertNode(root, mainValue, auxiliaryValue);
    }

    // Print the binary tree
    std::cout << "Binary Tree:" << std::endl;
    printTree(root);

    // Find and print the last node with maximum value
    Node* maxNode = findMax(root);
    std::cout << "\nLast node with maximum value: (" << maxNode->mainData << ", " << maxNode->auxiliaryData << ")" << std::endl;

    return 0;
}
