#include<iostream>

using namespace std;

typedef struct Node {
    int data;
    Node * right;
    Node * left;
} Node;

void tInsere(Node *& curr, int data) { //passagem por referencia, pois o curr pode ser alterado
    if (curr == NULL) {
        curr = new Node;
        curr->data = data;
        curr->right = NULL;
        curr->left = NULL;
    } else {
        if (data > curr->data) {
            //ir para a direita
            tInsere(curr->right, data);
        } else if (data < curr->data) {
            //ir para a esquerda
            tInsere(curr->left, data);
        }
    }
}

void tPesq(Node * curr, int data){ //passagem por valor, pois o curr nao sera alterado
    if(curr == NULL){
        cout << "Nao encontrado" << endl;
    } else {
        if(data > curr->data){
            tPesq(curr->right, data);
        } else if(data < curr->data){
            tPesq(curr->left, data);
        } else {
            cout << "Encontrado" << endl;
        }
    }
}

void tDestruir(Node *& curr){
    if(curr != NULL){
        tDestruir(curr->left);
        tDestruir(curr->right);
        delete curr;
    }
    curr = NULL;
}

int main(){

    Node * root = NULL;

    int N, X, num;

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> num;
        tInsere(root, num);
    }

    cin >> X;

    tPesq(root, X);

    tDestruir(root);
    
    return 0;
}