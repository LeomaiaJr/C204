//MÉTODO UTILIZADO: FORÇA BRUTA
//JUSTIFICATIVA: FOI O QUE EU TIVE MAIS FACILIDADE DE ENTENDER ENTRE O FORÇA BRUTA E O GULOSO

#include <iostream>

using namespace std;

int n; // quantidade de elementos a serem analisados
int v[2004], peso[2004]; //variaveis de valor para cada item e o peso de cada item
int pd[2004][2004]; //variavel para a pd
int itens_pegos[2004][2004];
int galho_aux = 1; //variavel para fazer o cout do numero do galho

int solve(int i, int cap) // os parametros sao o indice do seu produto e a capacidade atual da mochila
{
	int pega, npega; // variavel auxiliar do processo de decisao

	if(cap < 0) //caso nao tenha mais espaco na mochila
		return 0;

	if(i == n) // caso tenha chego no ultimo item
		return 0;
	
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
	int G; //galhos da arvore
    int P; //numero de pacotes'
    int W; //peso que cada galho suporta
    
    cout << "Insira a quantidade de galhos da arvore" << endl;
    cin >> G;

    do{ //loop para fazer o programa rodar para cada galho
        cout << "Insira o numero de pacotes" << endl;
        cin >> P;

        n = P;

        cout << "Insira a capacidade de cada galho" << endl;
        cin >> W;
        
        cout << "Insira o numero de enfeites por pacote e o peso do do pacote" << endl;
        for(int i = 0; i < n; i++){
            cin >> v[i] >>peso[i];
        }
        
        for(int i = 0; i< 2004; i++)
            for(int j = 0; j < 2004; j++)
                pd[i][j] = -1;

        cout << "Galho " << galho_aux << endl;
        cout << "Numero total de enfeites:" << solve(0, W) << endl;
        galho_aux++; //para printar o numero do galho
        G--;
    }while(G > 0);

	//recuperacao de caminho
	int i = 0;
	int j = W;
	
	return 0;
}