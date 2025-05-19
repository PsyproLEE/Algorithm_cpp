#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x[3];
int y[3];
double length[3];

bool isEqual(double a, double b) {
    return abs(a - b) < 1e-6;
}

bool isColinear() {
    int dx1 = x[1] - x[0], dy1 = y[1] - y[0];
    int dx2 = x[2] - x[0], dy2 = y[2] - y[0];
    return dx1 * dy2 - dx2 * dy1 == 0;
}

int isangle(){
    double a = length[0], b = length[1], c = length[2];
    if (isEqual(c, a + b)) return 0;     // 직각
    else if (c > a + b) return 1;        // 둔각
    else return 2;                       // 예각
}

string triangle(){
    if (isColinear()) return "X";

    if (isEqual(length[0], length[1]) && isEqual(length[1], length[2])) {
        return "JungTriangle";
    }

    else if (isEqual(length[0], length[1]) || isEqual(length[1], length[2]) 
        || isEqual(length[0], length[2])){
            
        if(isangle() == 0) return "Jikkak2Triangle";
        else if (isangle() == 1) return "Dunkak2Triangle";
        else return "Yeahkak2Triangle";
    }
    
    else {
        if(isangle() == 0) return "JikkakTriangle";
        else if (isangle() == 1) return "DunkakTriangle";
        else return "YeahkakTriangle";
    }
}  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }

    length[0] = pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2);
    length[1] = pow(x[2] - x[1], 2) + pow(y[2] - y[1], 2);
    length[2] = pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2);
    sort(length, length + 3);

    cout << triangle();
    return 0;
}
