#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

void makeConvexPolygon(Point points[], int numPoints, Point convexHull[], int& numHullPoints) {
    // Encontrar o ponto mais à esquerda
    int leftmostIndex = 0;
    for (int i = 1; i < numPoints; i++) {
        if (points[i].x < points[leftmostIndex].x) {
            leftmostIndex = i;
        }
    }

    int currentIndex = leftmostIndex;
    int nextIndex;
    numHullPoints = 0;
    do {
        convexHull[numHullPoints++] = points[currentIndex];
        nextIndex = (currentIndex + 1) % numPoints;

        for (int i = 0; i < numPoints; i++) {
            if (crossProduct(points[currentIndex], points[nextIndex], points[i]) > 0) {
                nextIndex = i;
            }
        }

        currentIndex = nextIndex;
    } while (currentIndex != leftmostIndex);
}

int main() {
    int numPoints;
    cin >> numPoints;

    Point points[numPoints];

    // Ler as coordenadas
    for (int i = 0; i < numPoints; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Transformar em um polígono convexo
    Point convexPolygon[numPoints];
    int numHullPoints;
    makeConvexPolygon(points, numPoints, convexPolygon, numHullPoints);

    // Printar o número de lados
    cout << numHullPoints << " lados" << endl;

    return 0;
}
