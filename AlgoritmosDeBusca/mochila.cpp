#include <iostream>
#include <cstring>

using namespace std;


int n; // quantidade de elementos a serem analisados
int v[2004], peso[2004]; //variaveis de valor para cada item e o peso de cada item
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];

int solve(int i, int cap) // os parametros sao o indice do seu produto e a capacidade atual da mochila
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco na mochila
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	if(pd[i][cap]!=-1) 
		return pd[i][cap];
	
	
	npega = solve(i + 1, cap); // valor caso nao pegue o item

	pd[i][cap] = npega;
	

	if(cap >= peso[i]) //caso seja possivel pegar o item
	{
		pega = solve(i + 1, cap - peso[i]) + v[i]; //valor caso pegue o item

		if(pega > npega)  //caso pegar seja uma melhor opcao
		{
			itens_pegos[i][cap] = 1; // caminho valendo 1 significa que peguei o item
			pd[i][cap] = pega;
			return pd[i][cap];
		}
		else
		{
			itens_pegos[i][cap] = 0; // caminho valendo 0 significa que nao peguei o item
			return pd[i][cap];
		}
	}

	else
		return pd[i][cap]; // caso nao tenha mais capacidade
}




int main()
{
	
	int mochila;
	cout << "Insira a capacidade da mochila" << endl;
	cin >> mochila; 
	cout << "Insira a quantidade de elementos" << endl;
	cin >> n; 
	int custo; 
	cin >> custo; 
	
	for(int i = 0; i < n; i++){
		cout << "Insira o peso e o valor do item" << endl;
		cin >>peso[i] >> v[i];
		v[i] -= custo; 
		
	}
	
	for(int i = 0; i< 2004; i++)
		for(int j = 0; j < 2004; j++)
			pd[i][j] = -1;
	
	
	cout << "O valor total foi de: ";
	cout << solve(0, mochila) << endl;
	cout << "---------------------"<< endl;
	
	//recuperacao de caminho
	int i = 0;
	int j = mochila;
	
	//while pra falar quais itens foram pegos
	while(i != n){ // enquanto eu nao chegar no ultimo item
		if(itens_pegos[i][j] == 0) // se nesse momento a melhor opcao foi nao pegar eu nao pego
			i++; // avanço para o proximo i, mantendo a capacidade
		
		else // if(caminho[i][j] == 1) /// se nesse momento a melhor opcao for pegar, eu pego
		{
			cout << "Peguei o item " << i << endl; // indico que peguei o item
			cout << "Peso:" << peso[i] << endl;
			cout << "Valor:" << v[i] << endl;
			cout << "---------------------"<< endl;
			j-= peso[i]; // diminuo a capacidade disponivel
			i++; // avanco para o proximo i
		}
	}
	
	
	
	return 0;
}