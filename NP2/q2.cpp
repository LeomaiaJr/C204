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

treenodeptr * tSearch(treenodeptr * arvore, int data){ 
    if(arvore == NULL){                              
        return NULL;
    } else {
        if(data > arvore->data){
            return tSearch(arvore->right, data);
        } else if(data < arvore->data){
            return tSearch(arvore->left, data);
        } else {
            return arvore;
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
    int Tmin, Tmax;

    cin >> P;

    for (int i = 0; i < P; i++) {
        cin >> peixe[i].V >> peixe[i].E >> peixe[i].O;
        
        peixe[i].T = int(peixe[i].V*peixe[i].E*N*peixe[i].E*N*peixe[i].O);

        tInsere(arvore, peixe[i].T);
    }

    cin >> Tmin >> Tmax;

    for(int i = Tmin; i <= Tmax; i++){
        treenodeptr * n = tSearch(arvore, i);
        if(n != NULL){
            for(int j = 0; j < P; j++){
                if(n->data == peixe[j].T){
                    cout << j << ":" << n->data << endl;
                }
            }
        }
    }

    tDestruir(arvore);
    
    return 0;
}