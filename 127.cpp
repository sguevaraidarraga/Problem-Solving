/*
    Santiago Guevara Idarraga
    Problem: 127 - Accordian
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool check(string &a, string &b) {
    return a[0] == b[0] || a[1] == b[1];
}
int main() {
    string c;
    vector<stack<string>> v(52);
    while(cin >> c && c != "#") {
        for(int i = 0; i < v.size(); i++) {
            v[i].push(c);
            cin >> c;
        }
        for(int i = 1; i < v.size(); i++) {
            if(i >= 3 && check(v[i-3].top(), v[i].top())) {
                v[i-3].push(v[i].top());
                v[i].pop();
                i -= 4;
            }
            else if(i >= 1 && check(v[i-1].top(), v[i].top())) {
                v[i-1].push(v[i].top());
                v[i].pop();
                i -= 2;
            }
            if(v[i].empty()) {
                v.erase(v.begin()+i);
            }
        }
        cout << v.size() << " pile" << ((v.size() != 1) ? "s " : " ") << "remaining:";
        for(int i = 0; i < v.size(); i++) {
            cout << ' ' << v[i].size();
        }
    }
    return 0;
}
