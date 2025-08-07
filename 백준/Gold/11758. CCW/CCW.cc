#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
struct p{
    int x, y;
};
int CCW(p a, p b, p c){
    ll ret = (b.x-a.x)*(c.y- a.y) - (c.x-a.x)*(b.y-a.y);
    return !ret ? 0 : (ret < 0? -1 : 1);
}
int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    p a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    cout << CCW(a,b,c) <<'\n';
    return 0;
}