#include <iostream>
// Deklarasikan nullptr jika tidak disertakan dalam versi C++ Anda
#ifndef nullptr
#define nullptr NULL
#endif

// Struktur simpul (node) untuk pohon biner
struct Node {
    int data;
    Node* left;
    Node* right;

    // Konstruktor
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Fungsi untuk menambahkan simpul ke dalam pohon biner
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Fungsi untuk mencari nilai dalam pohon biner
bool search(Node* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Fungsi untuk mencetak pohon biner secara inorder
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Menambahkan beberapa nilai ke dalam pohon
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Mencetak pohon secara inorder
    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    // Mencari nilai dalam pohon
    int target = 40;
    if (search(root, target)) {
        std::cout << target << " Data ditemukan dalam pohon." << std::endl;
    } else {
        std::cout << target << "Data tidak ditemukan dalam pohon." << std::endl;
    }

    return 0;
}
