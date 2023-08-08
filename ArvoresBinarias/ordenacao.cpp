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

void ordenacao(treenodeptr * arvore){
    if(arvore != NULL){ // se a arvore nao for nula, chama a funcao para a direita, imprime o valor do no atual e chama a funcao para a esquerda
        ordenacao(arvore->right); 
        cout << arvore->data << endl;
        ordenacao(arvore->left);
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

    ordenacao(arvore);

    tDestruir(arvore);

    return 0;
}