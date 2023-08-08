#include <iostream>
#include <list>

using namespace std;

typedef struct treenodeptr {
    int data; // toxidade
    treenodeptr * right;
    treenodeptr * left;
} treenodeptr;

typedef struct Peixe {
    int P; // quantidade de peixes
    float V; // viscosidade da pele
    float E; // espessura da cauda
    float O; // diâmetro do olho
    int N = 7; // número atômico do Nitrogênio
    int T; // toxidade
} Peixe;

void tInsere(treenodeptr *& arvore, int data) {
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

void emNivel(treenodeptr * arvore, int P, Peixe Peixe[]){
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
            
            for(int i = 0; i < P; i++){
                if(n->data == Peixe[i].T){
                    cout << i << ":" << n->data << endl;
                }
            }
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

    int P = 10000; // quantidade de peixes
    Peixe peixe[P];
    int N = 7; // número atômico do Nitrogênio

    cin >> P;

    for (int i = 0; i < P; i++) {
        cin >> peixe[i].V >> peixe[i].E >> peixe[i].O;
        
        peixe[i].T = int(peixe[i].V*peixe[i].E*N*peixe[i].E*N*peixe[i].O);

        tInsere(arvore, peixe[i].T);
    }

    emNivel(arvore, P, peixe);

    tDestruir(arvore);
    
    return 0;
}