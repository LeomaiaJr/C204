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
void primoPosOrdem (treenodeptr * arvore, int &j){  // conta os numeros primos em pos-ordem(pq sim)
    int aux = 0;  // contagem de numeros divisiveis
	if (arvore != NULL)
	{
		primoPosOrdem(arvore->left,j);
		primoPosOrdem(arvore->right,j);
		for(int i = 1; i <= arvore->data; i++)
		{
			if(arvore->data % i == 0) // se o numero for divisivel por i, aumenta a contagem
				aux++;
		}
		if(aux == 2)  // divisivel somente por dois numeros = numero primo
			j++;
	}
}

int contaPrimos(treenodeptr * arvore) {
    int j = 0;
    
    primoPosOrdem(arvore, j);

    return j;
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

    contaPrimos(arvore);

    cout << contaPrimos(arvore) << " numeros primos" << endl;

    tDestruir(arvore);
    
    return 0;
}