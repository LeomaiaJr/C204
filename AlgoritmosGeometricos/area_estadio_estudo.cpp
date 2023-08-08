#include<iostream>
#include<cmath>

using namespace std;

typedef struct ponto{
    int x, y;
} vetor;

vetor cria_vetor(ponto p1, ponto p2){
    vetor AB;
    AB.x = p2.x - p1.x;
    AB.y = p2.y - p1.y;
    return AB;
}

float vetorial(vetor A, vetor B){
    return A.x*B.y - A.y*B.x;
}

float area_triangulo(ponto A, ponto B, ponto C){
    vetor AB;
    vetor AC;
    float area;
    AB = cria_vetor(A, B);
    AC = cria_vetor(A, C);
    area = fabs(vetorial(AB, AC))/2;
    return area;

}

float area_poligono(ponto v[], int n){
    float area = 0;

    for(int i = 0; i<= n-2; i++){
        area += area_triangulo(v[0], v[i+1], v[i+2]);
    }
    return area;
}

int main(){

    ponto v[6];
    for(int i = 0; i<6; i++){
        cin >> v[i].x >> v[i].y;
    }
    cout << area_poligono(v, 6) << endl;

    return 0;
}