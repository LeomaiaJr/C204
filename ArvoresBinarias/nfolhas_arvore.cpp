#include<iostream>

using namespace std;

typedef struct treenodeptr {
    int data;
    treenodeptr * right;
    treenodeptr * left;
} treenodeptr;

void tInsere(treenodeptr *& arvore, int data) { //passagem por referencia, pois a arvore pode ser alterado
    if (arvore == NULL) {
        arvore = new treenodeptr;
        arvore->data = data;
        arvore->right = NULL;
        arvore->left = NULL;
    } else {
        if (data > arvore->data) {
            //ir para a direita
            tInsere(arvore->right, data);
        } else if (data < arvore->data) {
            //ir para a esquerda
            tInsere(arvore->left, data);
        }
    }
}

int contaFolhas(treenodeptr * arvore) {
    if (arvore == nullptr) {
        return 0;
    } else {
        if (arvore->left == nullptr && arvore->right == nullptr) {
            return 1;
        } else {
            return contaFolhas(arvore->left) + contaFolhas(arvore->right); //numero de folhas da esquerda + numero de folhas da direita
        }
    }
}

void tDestruir(treenodeptr *& arvore){
    if(arvore != NULL){
        tDestruir(arvore->left);
        tDestruir(arvore->right);
        delete arvore;
    }
    arvore = NULL;
}

int main(){

    treenodeptr * arvore = NULL;

    int N;

    cin >> N;
    while(N != -1){
        tInsere(arvore, N);
        cin >> N;
    }

    cout << contaFolhas(arvore) << endl;

    tDestruir(arvore);
    
    return 0;
}
