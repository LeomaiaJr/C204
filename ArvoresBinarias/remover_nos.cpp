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

treenodeptr* tMenor(treenodeptr *& arvore) {
    treenodeptr* aux = arvore;

    if (aux->left == NULL) {
        arvore = aux->right;
        return aux;
    } else {
        return tMenor(aux->left);
    }
}

int tRemove(treenodeptr *& arvore, int X){
    
    treenodeptr * aux;

    if(arvore == NULL){
        return 1;
    }
    if(X == arvore->data){
        aux = arvore;
        if(arvore->left == NULL){ //raiz nao tem filho a esquerda
            arvore = arvore->right;
        }
        else if(arvore->right == NULL){ //raiz nao tem filho a direita
            arvore = arvore->left;
        }
        else{ //raiz tem filho a esquerda e a direita
            aux = tMenor(arvore->right);
            arvore->data = aux->data;
        }
        delete aux;
        return 0;
    }
    else if(X < arvore->data){
            return tRemove(arvore->left, X);
    }
    else{
        return tRemove(arvore->right, X);
    }
}

void emOrdem (treenodeptr * arvore){  // mostra os elemento em ordem crescente
	if (arvore != NULL)
	{
		emOrdem(arvore->left);
		cout << arvore->data << " ";
		emOrdem(arvore->right);
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
    
    int N, X, remocao;
    
    cin >> N;
    while(N != 0){
        tInsere(arvore, N);
        cin >> N;
    }

    cin >> X;

    remocao = tRemove(arvore, X);
    while(remocao == 0){
        remocao = tRemove(arvore, X); //remover todos os elementos iguais a x e nao so o primeiro
    }

    emOrdem(arvore);
    cout << endl;
    
    tDestruir(arvore);
    
    return 0;
}