#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout.precision(1);
    
    string x;
    double y;
    cin >> x;
    if (x[0] == 'A'){
        y = 4.0;
    }
    else if (x[0] == 'B'){
        y = 3.0;
    }
    else if (x[0] == 'C'){
        y = 2.0;
    }
    else if (x[0] == 'D'){
        y = 1.0;
    }
    else if (x[0] == 'F'){
        y = 0.0;
    }
    
    if (x[1] == '+'){
        y+= 0.3;
    }
    else if (x[1] == '-'){
        y-= 0.3;
    }

    cout << y;
}