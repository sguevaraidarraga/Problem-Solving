/*
    Santiago Guevara Idarraga
    Problem: 127 - Accordian
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool match(string &a, string &b) {
    return a[0] == b[0] || a[1] == b[1];
}
void moveStack(stack<string> &from, stack<string> &to) {
    while(!from.empty()) {
        to.push(from.top());
        from.pop();
    }
}
int main() {
    int i;
    string c;
    while(cin >> c && c != "#") {
        vector<stack<string>> v(52);
        for(int i = 0; i < v.size(); i++) {
            v[i].push(c);
            cin >> c;
        }
        i = 1;
        while(i < v.size()) {
            if(i >= 3 && match(v[i-3].top(), v[i].top())) {
                moveStack(v[i], v[i-3]);
                v.erase(v.begin()+i);
                i -= 3;
            }
            else if(i >= 1 && match(v[i-1].top(), v[i].top())) {
                moveStack(v[i], v[i-1]);
                v.erase(v.begin()+i);
                i -= 1;
            }
            else {
                i++;
            }
        }
        cout << v.size() << " pile"; if(v.size() != 1){cout << "s";} cout << " remaining:";
        for(int i = 0; i < v.size(); i++) {
            cout << ' ' << v[i].size();
        }
    }
    return 0;
}
