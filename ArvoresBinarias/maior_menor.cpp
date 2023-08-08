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

int maior(treenodeptr * arvore){ // o maior valor sempre estara na direita
    if(arvore == NULL){
        return -1;
    } else {
        if(arvore->right == NULL){
            return arvore->data;
        } else {
            return maior(arvore->right);
        }
    }
}

int menor(treenodeptr * arvore){ // o menor valor sempre estara na esquerda
    if(arvore == NULL){
        return -1;
    } else {
        if(arvore->left == NULL){
            return arvore->data;
        } else {
            return menor(arvore->left);
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

    cout << menor(arvore) << " e " << maior(arvore) << endl;

    tDestruir(arvore);

    return 0;
}