#include <iostream>

using namespace std;

struct Point {
    double x, y;
};

double calculateArea(Point points[], int n) {
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (points[i].x + points[j].x) * (points[i].y - points[j].y);
    }
    return area;
}

int main() {
    int numPoints = 6;
    Point points[numPoints];

    // Ler as coordenadas dos pontos
    for (int i = 0; i < numPoints; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Calcular a área
    double area = calculateArea(points, numPoints);

    // Printar o resultado
    cout << "Área do estádio: " << area << endl;

    return 0;
}
