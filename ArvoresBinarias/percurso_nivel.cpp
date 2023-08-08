#include<iostream>
#include<list>

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

void emNivel(treenodeptr * arvore){
    treenodeptr * n;
    list<treenodeptr *> q;

    if(arvore != NULL){
        q.push_back(arvore);
        while(q.empty() == false){
            n = *q.begin();
            q.pop_front();
            if(n->left != NULL){
                q.push_back(n->left);
            }
            if(n->right != NULL){
                q.push_back(n->right);
            }
            cout << n->data << endl;
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

    emNivel(arvore);

    tDestruir(arvore);

    return 0;
}