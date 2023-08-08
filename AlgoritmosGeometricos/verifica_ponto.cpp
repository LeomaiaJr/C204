#include<iostream>

using namespace std;

typedef struct ponto{
    int x;
    int y;
} vetor;


vetor cria_vetor(ponto a, ponto b){
    vetor AB;
    AB.x = b.x - a.x;
    AB.y = b.y - a.y;
    return AB;
}

float vetorial(vetor a, vetor b){
    return a.x*b.y - a.y*b.x;
}

int sentido(ponto a, ponto b, ponto p){
    vetor AB;
    vetor AP;
    float vet;

    AB = cria_vetor(a, b);
    AP = cria_vetor(a, p);

    vet = vetorial(AB, AP);

    if(vet > 0) return 1;
    if(vet < 0) return -1;
    else return 0;
}

int lado(ponto a, ponto b, ponto p){
// retorna: 1 se p estiver à esquerda de ab,
// -1 se p estiver à direita,
// 0 se estiver alinhado
    int s = sentido(a, b, p);
    if(s > 0) return 1;
    if(s < 0) return -1;
    else return 0;
}

int main(){

    ponto a, b, p;

    cout << "Digite o ponto a: ";
    cin >> a.x >> a.y;
    cout << "Digite o ponto b: ";
    cin >> b.x >> b.y;
    cout << "Digite o ponto p: ";
    cin >> p.x >> p.y;

    cout << "return lado(a, b, p): " << lado(a, b, p) << endl;

    if(lado(a, b, p) == 0)
        cout << "O ponto p está alinhado com ab." << endl;
    else if(lado(a, b, p) == 1)
        cout << "O ponto p está no lado esquerdo de ab" << endl;
    else
        cout << "O ponto p está no lado direito de ab" << endl;

    return 0;
}