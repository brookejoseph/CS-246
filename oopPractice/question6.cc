#include <iostream>

class BTree {
public:
    int val;
    BTree *left;
    BTree *right;

    BTree();
    BTree(int current_node);

    BTree* copy() const;
};

BTree::BTree() : val(0), left(nullptr), right(nullptr) {}

BTree::BTree(int current_node) {
    this->val = current_node;
    this->left = nullptr;
    this->right = nullptr;
}

BTree* BTree::copy() const {
    BTree *additional = new BTree(this->val);

    if (this->left != nullptr) {
        additional->left = this->left->copy();
    }

    if (this->right != nullptr) {
        additional->right = this->right->copy();
    }

    return additional;
}

int main() {
    BTree* root = new BTree(10);
    root->left = new BTree(5);
    root->right = new BTree(15);

    BTree* copied_tree = root->copy();

    std::cout << "Original Root: " << root->val << std::endl;
    std::cout << "Copied Root: " << copied_tree->val << std::endl;

    delete root->left;
    delete root->right;
    delete root;

    delete copied_tree->left;
    delete copied_tree->right;
    delete copied_tree;

    return 0;
}
