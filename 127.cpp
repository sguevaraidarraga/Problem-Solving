/*
    Santiago Guevara Idarraga
    Problem: 127 - Accordian
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool match(stack<string> &a, stack<string> &b) {
    return a.top()[0] == b.top()[0] || a.top()[1] == b.top()[1];
}
int main() {
    int i;
    string c;
    while(cin >> c && c != "#") {
        vector<stack<string>> v(52);
        v[0].push(c);
        for(int i = 1; i < 52; i++) {
            cin >> c;
            v[i].push(c);
        }
        i = 1;
        while(i < v.size()) {
            if(i >= 3 && match(v[i-3], v[i])) {
                v[i-3].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) {
                    v.erase(v.begin()+i);
                }
                i -= 3;
            }
            else if(i >= 1 && match(v[i-1], v[i])) {
                v[i-1].push(v[i].top());
                v[i].pop();
                if(v[i].empty()) {
                    v.erase(v.begin()+i);
                }
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
        cout << endl;
    }
    return 0;
}
