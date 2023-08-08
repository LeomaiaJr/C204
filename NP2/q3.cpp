#include <iostream>
#include <cmath>

using namespace std;

typedef struct Ponto{
    int x;
    int y;
} Ponto;

int calcula_distancia(Ponto p1, Ponto p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

int main(){

    Ponto p[5];

    for(int i = 0; i < 5; i++){
        cin >> p[i].x >> p[i].y;
    }

    int diametro = 0;
    int distancia = 0;

    distancia = calcula_distancia(p[3], p[4]);
    diametro = calcula_distancia(p[1], p[2]);

    cout << diametro << endl;
    cout << distancia << endl;

    return 0;
}