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

void posicaoPreOrdem (treenodeptr * arvore, int &PRE, int cidade, int &x)  // posicao da cidade pelo percurso pre-ordem
{
	if (arvore != NULL)
	{
		if(arvore->data == cidade)
			x = PRE;
		else
			PRE++;
		posicaoPreOrdem(arvore->left, PRE, cidade, x);
		posicaoPreOrdem(arvore->right, PRE, cidade, x);
	}
}

void posicaoEmOrdem (treenodeptr * arvore, int &EM, int cidade, int &x)  // posicao da cidade pelo percurso em-ordem
{
	if (arvore != NULL)
	{
		posicaoEmOrdem(arvore->left, EM, cidade, x);
		if(arvore->data == cidade)
			x = EM;
		else
			EM++;
		posicaoEmOrdem(arvore->right, EM, cidade, x);
	}
}

void posicaoPosOrdem (treenodeptr * arvore, int &POS, int cidade, int &x)  // posicao da cidade pelo percurso pos-ordem
{
	if (arvore != NULL)
	{
		posicaoPosOrdem(arvore->left, POS, cidade, x);
		posicaoPosOrdem(arvore->right, POS, cidade, x);
		if(arvore->data == cidade)
			x = POS;
		else
			POS++;
	}
}

int melhorCaminho(treenodeptr * arvore, int cidade)  // funcao que retorna o melhor caminho
{
	int PRE = 0;  // posicao da cidade pre-ordem
	int EM = 0;   // posicao da cidade em-ordem
	int POS = 0;  // posicao da cidade pos-ordem
	int aux = 0; 

	// chamada de funcoes aux de posicao da cidade nos percursos
	posicaoPreOrdem(arvore, PRE, cidade, aux);
	PRE = aux;
	posicaoEmOrdem(arvore, EM, cidade, aux);
	EM = aux;
	posicaoPosOrdem(arvore, POS, cidade, aux);
	POS = aux;

	if(PRE < POS && PRE < EM)   // pre-ordem e mais perto
		aux = 1;
	else if(EM < POS && EM < PRE)  // em-ordem e mais perto
		aux = 2;
	else if(POS < PRE && POS < EM)   // pos-ordem e mais perto
		aux = 3;
	
	return aux;
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
    int cidade;
    int melhor_caminho;

    cin >> N;
    while(N != -1){
        tInsere(arvore, N);
        cin >> N;
    }

    cin >> cidade;

    melhor_caminho = melhorCaminho(arvore, cidade);

    //1 = pre; 2 = em; 3 = pos

    if(melhor_caminho == 1){
        cout << "Pre" << endl;
    } else if(melhor_caminho == 2){
        cout << "Em" << endl;
    } else if(melhor_caminho == 3){
        cout << "Pos" << endl;
    }

    tDestruir(arvore);

    return 0;
}