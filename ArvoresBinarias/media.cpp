#include<iostream>
#include<iomanip>

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

int contarNos(treenodeptr * arvore) { 
    if (arvore == nullptr) {
        return 0;
    } else {
        return 1 + contarNos(arvore->left) + contarNos(arvore->right); //1 + numero de nos da esquerda + numero de nos da direita
    }
}
int somaNos(treenodeptr * arvore) {
    if (arvore == nullptr) {
        return 0;
    } else {
        return arvore->data + somaNos(arvore->left) + somaNos(arvore->right); //valor do no atual + soma dos nos da esquerda + soma dos nos da direita
    }
}

float media(treenodeptr * arvore) {
    if (arvore == nullptr) {
        return 0.0;
    } else {
        int sum = somaNos(arvore);
        int count = contarNos(arvore);
        if (count == 0) {
            return 0.0;
        } else {
            return (float)sum / count; //soma de todos os valores de todos os nós / numero de nós
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

    cout << fixed << setprecision(2) << "Media: " << media(arvore) << endl;
    
    return 0;
}
