#include<iostream>

using namespace std;

int main(){

    struct Aluno{
        float nota1;
        float nota2;
        float nota3;
        float media;
    }; 

    int qtdAlunos;
    float mediaTurma = 0;

    cin >> qtdAlunos;

    Aluno *alunos = new Aluno[qtdAlunos];

    for(int i = 0; i < qtdAlunos; i++){
        cin >> alunos[i].nota1;
        cin >> alunos[i].nota2;
        cin >> alunos[i].nota3;
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
        mediaTurma += alunos[i].media;
    }

    mediaTurma /= qtdAlunos;

    cout << mediaTurma << endl;

    delete[] alunos;
    
    return 0;
}