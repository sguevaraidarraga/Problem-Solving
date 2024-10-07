/*
    Santiago Guevara Idarraga
    Problem: 127 - Accordian
*/

#include <iostream>
#include <stack>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string c;
    vector<stack<string>> v(52);
    stack<string> s;
    bool hash = false;
    while(cin >> c && !hash) {
        if(c == "#") {
            hash = true;
        }
        if(!hash) {
            for(int i = 1; i < v.size(); i++) {
                cin >> c;
                s.push(c);
                v[i] = c;
            }
        }
    }
    return 0;
}