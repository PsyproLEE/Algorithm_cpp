#include <iostream>
#include <deque>

using namespace std;

int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;

    cin >> n;
    string s;
    int tmp;
    while(n--){
        cin >> s;

        if(s=="push_front"){
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if(s == "push_back"){
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if(s == "pop_front"){
            if(!dq.empty()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
                cout << -1 << '\n';
        }
        else if(s == "pop_back"){
            if(!dq.empty()){
                cout << dq.back() << '\n';
                dq.pop_back();    
            }
            else
                cout << -1 <<'\n';
        }
        else if(s == "size"){
            cout << dq.size() << '\n'; 
        }
        else if(s =="empty"){
            if(!dq.empty()) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
        else if(s == "front"){
            if(!dq.empty())
                cout << dq.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if(s == "back"){
            if(!dq.empty())
                cout << dq.back() << '\n';
            else
                cout << -1 << '\n';

        }
    }
    return 0;
}