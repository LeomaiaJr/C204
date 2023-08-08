#include <iostream>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

// A global point needed for sorting points with reference
// to the first point Used in compare function of qsort()
Point p0;

// A utility function to find next to top in a stack
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

// A utility function to swap two points
void swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

// A utility function to return square of distance
// between p1 and p2
double calculateDistance(Point p1, Point p2) //funcao distSq do algoritmo de Graham Scan alterada para calcular a distância entre dois pontos
{
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclockwise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (calculateDistance(p0, *p2) >= calculateDistance(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

// Prints convex hull of a set of n points.
double grahan_scan(vector<Point>& points, int n) //alterada para receber um vetor de pontos e retornar a quantidade mínima de material necessário para cercar a reserva
{
    // Find the bottommost point
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;

        // Pick the bottom-most or choose the left
        // most point in case of tie
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    // Place the bottom-most point at the first position
    swap(points[0], points[min]);

    // Sort n-1 points with respect to the first point.
    // A point p1 comes before p2 in sorted output if p2
    // has a larger polar angle (in counterclockwise
    // direction) than p1
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(Point), compare);

    // If two or more points make the same angle with p0,
    // remove all but the one that is farthest from p0.
    // Remember that, in the above sorting, our criteria was
    // to keep the farthest point at the end when more than
    // one points have the same angle.
    int m = 1; // Initialize the size of the modified array
    for (int i = 1; i < n; i++)
    {
        // Keep removing i while the angle of i and i+1 is the same
        // with respect to p0
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++; // Update the size of the modified array
    }

    // If the modified array of points has less than 3 points,
    // the convex hull is not possible
    if (m < 3)
        return 0.0;

    // Create an empty stack and push the first three points to it.
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    // Process the remaining n-3 points
    for (int i = 3; i < m; i++)
    {
        // Keep removing the top while the angle formed by
        // the points next-to-top, top, and points[i] makes
        // a non-left turn
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Now the stack has the output points, calculate the sum of side lengths
    Point prev = S.top();
    S.pop();
    while (!S.empty())
    {
        Point curr = S.top();
        S.pop();
        prev = curr;
    }

    double material = calculateDistance(points[n - 1], points[0]);

    // Calcular a quantidade mínima de material necessário para cercar a reserva
    for (int i = 1; i < n; i++) {
        material += calculateDistance(points[i - 1], points[i]);
    }

    return material;
}

// Driver program to test above functions
int main()
{
    int numReservas;
    double materialTotal = 0.0;

    cout << "Digite o número de reservas florestais: ";
    cin >> numReservas;

    for (int i = 0; i < numReservas; i++) {
        int numTrees;
        cout << "Reserva #" << i + 1 << endl;
        cout << "Digite o número de árvores: ";
        cin >> numTrees;

        vector<Point> points(numTrees);

        for (int j = 0; j < numTrees; j++) {
            cout << "Digite as coordenadas da árvore #" << j + 1 << " (x y): ";
            cin >> points[j].x >> points[j].y;
        }

        double minimumMaterial = grahan_scan(points, numTrees);
        materialTotal += minimumMaterial;
    }
        cout << "Quantidade mínima de material necessária para cercar a reserva: " << materialTotal << endl;

    return 0;
}
