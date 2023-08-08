// 1.Caixeiro Viajante
//Jorge precisa fazer suas entregas para todas as cidades de sua regiãoe depois retornar para sua casa,
//porém não sabe como poderia realiza-las com o menor caminho possível, 
//para isto foi desenvolvido o métododo caixeiro viajante na qual ele passa por todas as cidadese volta para o ponto inicial.
//Queremos utilizar o métodode força bruta para realizarmos essa atividade para poder tersempre o melhor resultado.

#include <iostream> // Entrada e saida
#include <climits> // INT_MAX
#include <algorithm> // next_permutation

using namespace std;


int main()
{
	int custo[100][100]; // 100 -> numero maximo de cidades
						 // custo[i][j] = custo de ir da cidade 'i' para a cidade 'j'
	int n; // numero de cidades
	int cidade_inicial;
	
	cin >> n;
	for(int i = 0;i < n;i++)
		for(int j = i+1;j < n;j++)
		{
			cout << "Entre com o custo de ir da cidade " << i << " para a cidade " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	cin >> cidade_inicial;
	
	
	int v[100]; // vetor com as cidades a serem permutadas
	int p; // var. auxiliar
	int menor_custo; // menor custo da viagem
	int custo_caminho; // custo do caminho
	
	// colocando as cidades que serao permutadas no vetor (todas exceto a inicial)
	p = 0;
	for(int i = 0;i < n;i++)
		if(i != cidade_inicial)
		{
			v[p] = i;
			p++;
		}

	// forca bruta
	menor_custo = INT_MAX; // inicializo o custo com infinito
	do
	{
		custo_caminho = custo[cidade_inicial][v[0]];
        for(int i = 0; i< n-2; i++){
            custo_caminho += custo[v[i]][v[i+1]];
        }

        custo_caminho += custo[v[n-2]][cidade_inicial];

        if(custo_caminho<menor_custo){
            menor_custo = custo_caminho;
        }

	}while(next_permutation(v,v+(n-1))); // n-1 = numero de cidades a serem permutadas
	// obs.: para fazer todas as permutacoes, o vetor deve estar ordenado no comeco
	
	cout << "Menor custo = " << menor_custo << endl;

	return 0;
}