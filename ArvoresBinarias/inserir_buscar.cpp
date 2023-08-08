#include <iostream>
using namespace std;

// Estrutura para representar um nó da árvore
struct Node {
    int value;
    Node* left;
    Node* right;
};

// Função para criar um novo nó com o valor especificado
Node* createNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Função para inserir um nó na árvore
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    } else if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Função para procurar um nó na árvore e removê-lo
Node* removeNode(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    } else if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Achou o nó pra remover
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Nó tem duas folhas: encontrar o menor valor à direita
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->value = temp->value;
            root->right = removeNode(root->right, temp->value);
        }
    }
    return root;
}

// Função para procurar um nó
bool searchNode(Node* root, int value) {
    if (root == nullptr) {
        return false;
    } else if (root->value == value) {
        return true;
    } else if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// Função para printar os elementos da árvore em ordem crescente
void printTree(Node* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->value << " ";
        printTree(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Inserir elementos
    int value;
    do {
        cin >> value;
        if (value != 0) {
            root = insertNode(root, value);
        }
    } while (value != 0);

    // Procurar e remover um elemento
    int searchValue;
    cin >> searchValue;
    if (searchNode(root, searchValue)) {
        root = removeNode(root, searchValue);
    cout << "Elemento " << searchValue << " encontrado!" << endl;
    } else {
        cout << "Elemento não encontrado" << endl;
    }

    // Printar os elementos da árvore em ordem crescente
    printTree(root);
    cout << endl;

return 0;
}
