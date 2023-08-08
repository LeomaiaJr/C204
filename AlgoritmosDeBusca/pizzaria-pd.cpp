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
	int nPizzas; 
    cout << "Insira a quantidade de pedidos" << endl;
	cin >> n; //n de elementos
	cout << "Insira a capacidade maxima" << endl;
	cin >> nPizzas; //capacidade que roberto pode levar
	
	for(int i = 0; i < n; i++){
		cout << "Insira o tempo e o numero de pizas" << endl;
		cin >> v[i] >>peso[i];		// valor e peso do item = tempo para cada pizza e quantidade de pizzas
	}
	
	for(int i = 0; i< 2004; i++)
		for(int j = 0; j < 2004; j++)
			pd[i][j] = -1;
	
	
	cout << "O tempo total foi de: ";
	cout << solve(0, nPizzas) << endl;
	cout << "---------------------"<< endl;
	
	//recuperacao de caminho
	int i = 0;
	int j = nPizzas;
	
	return 0;
}