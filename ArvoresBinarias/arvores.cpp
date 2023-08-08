//-------------FUNCOES RECORRENTES EM ARVORES BINARIAS-------------//

#include<iostream>
#include<list>

using namespace std;

typedef struct treenodeptr { //struct do nó da arvore
    int data;
    treenodeptr * right;
    treenodeptr * left;
} treenodeptr;

//INSERIR UM NÓ NA ARVORE
void tInsere(treenodeptr *& arvore, int data) { //recebe o endereco da arvore por referencia e o dado a ser inserido 
    if (arvore == NULL) {                       //void pois nao retorna nada
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

//PESQUISAR UM NÓ NA ARVORE E PRINTAR SE ENCONTROU OU NÃO
void tPesq(treenodeptr * arvore, int data){ //recebe o endereco da arvore por valor e o dado a ser pesquisado
    if(arvore == NULL){                     //void pois nao retorna nada
        cout << "Nao encontrado" << endl;
    } else {
        if(data > arvore->data){
            tPesq(arvore->right, data);
        } else if(data < arvore->data){
            tPesq(arvore->left, data);
        } else {
            cout << "Encontrado" << endl;
        }
    }
}

//PESQUISAR UM NÓ NA ARVORE E RETORNAR O NÓ
treenodeptr tSearch(treenodeptr * arvore, int data){ //recebe o endereco da arvore por valor e o dado a ser pesquisado
    if(arvore == NULL){                              //tipo treenodeptr pois retorna um nó
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

//REMOVER UM NÓ DA ARVORE

//funcao auxiliar para remover um nó da arvore
treenodeptr* tMenor(treenodeptr *& arvore) { //recebe o endereco da arvore por referencia
    treenodeptr* aux = arvore; //nó auxiliar

    if (aux->left == NULL) { //se o nó nao tiver filho a esquerda retorna o proprio nó e o nó da arvore recebe o filho a direita do nó
        arvore = aux->right;
        return aux;
    } else {
        return tMenor(aux->left); //se o nó tiver filho a esquerda chama a funcao para o filho a esquerda
    }
}

int tRemove(treenodeptr *& arvore, int X){ //recebe o endereco da arvore por referencia e o dado a ser removido
    treenodeptr * aux;                     //retorna 0 se o dado foi removido e 1 se nao foi

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

//DESTRUIR A ARVORE
void tDestruir(treenodeptr *& arvore){ //recebe o endereco da arvore por referencia
    if(arvore != NULL){
        tDestruir(arvore->left);
        tDestruir(arvore->right);
        delete arvore;
    }
    arvore = NULL;
}


//----------------PERCURSOS----------------//

//PERCURSO EM NIVEL
void emNivel(treenodeptr * arvore){ //recebe o endereco da arvore por valor
    treenodeptr * n; //nó auxiliar
    list<treenodeptr *> q; //fila #include<list>

    if(arvore != NULL){ //se a arvore nao for vazia insere a raiz na fila
        q.push_back(arvore);
        while(q.empty() == false){
            n = *q.begin(); //n recebe o primeiro elemento da fila e remove o primeiro elemento da fila
            q.pop_front();
            if(n->left != NULL){ //se o nó tiver filho a esquerda insere o filho a esquerda na fila
                q.push_back(n->left); 
            } 
            if(n->right != NULL){ //se o nó tiver filho a direita insere o filho a direita na fila
                q.push_back(n->right); 
            }
            cout << n->data << endl; //printa o dado do nó
        }
    }
}

//PERCURSO EM PRE ORDEM
void preOrdem(treenodeptr * arvore){ //recebe o endereco da arvore por valor
    if(arvore != NULL){ 
        cout << arvore->data << endl; //printa a raiz
        preOrdem(arvore->left); //chama a funcao para o filho a esquerda
        preOrdem(arvore->right); //chama a funcao para o filho a direita
    }
}

//PERCURSO EM ORDEM
void emOrdem (treenodeptr * arvore){ //recebe o endereco da arvore por valor
	if (arvore != NULL)
	{
		emOrdem(arvore->left); //chama a funcao para o filho a esquerda
		cout << arvore->data << " "; //printa a raiz
		emOrdem(arvore->right); //chama a funcao para o filho a direita
	}
}

//PERCURSO EM POS ORDEM
void posOrdem(treenodeptr * arvore){ //recebe o endereco da arvore por valor
    if(arvore != NULL){
        posOrdem(arvore->left); //chama a funcao para o filho a esquerda
        posOrdem(arvore->right); //chama a funcao para o filho a direita
        cout << arvore->data << endl; //printa a raiz
    }
}
//---------------------------------------//


//MELHOR CAMINHO ENTRE PREORDEM, EMORDEM E POSORDEM
void posicaoPreOrdem (treenodeptr * arvore, int &PRE, int cidade, int &x) // posicao da cidade pelo percurso pre-ordem
{                                                                         // cidade = destino e x = posicao
	if (arvore != NULL)
	{
		if(arvore->data == cidade) // se a cidade for encontrada
			x = PRE; // x recebe a posicao
		else
			PRE++; // se nao for encontrada, PRE incrementa
		posicaoPreOrdem(arvore->left, PRE, cidade, x); 
		posicaoPreOrdem(arvore->right, PRE, cidade, x);
	}
}

void posicaoEmOrdem (treenodeptr * arvore, int &EM, int cidade, int &x) // posicao da cidade pelo percurso em-ordem
{                                                                       // cidade = destino e x = posicao
	if (arvore != NULL)
	{
		posicaoEmOrdem(arvore->left, EM, cidade, x);  
		if(arvore->data == cidade) // se a cidade for encontrada
			x = EM; // x recebe a posicao
		else
			EM++; // se nao for encontrada, EM incrementa
		posicaoEmOrdem(arvore->right, EM, cidade, x);
	}
}

void posicaoPosOrdem (treenodeptr * arvore, int &POS, int cidade, int &x) // posicao da cidade pelo percurso pos-ordem
{                                                                         // cidade = destino e x = posicao
	if (arvore != NULL)
	{
		posicaoPosOrdem(arvore->left, POS, cidade, x);
		posicaoPosOrdem(arvore->right, POS, cidade, x);
		if(arvore->data == cidade) // se a cidade for encontrada
			x = POS; // x recebe a posicao
		else
			POS++; // se nao for encontrada, POS incrementa
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