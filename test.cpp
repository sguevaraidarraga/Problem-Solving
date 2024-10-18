/*
    Santiago Guevara Idarraga
    Problem: ?
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Matrix = vector<string>;

void rotate90(Matrix &m) {
    int n = m.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            swap(m[i][j], m[j][i]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n/2; j++) {
            swap(m[i][j], m[i][n-(j+1)]);
        }
    }
}
void reflect(Matrix &m) {
    int n = m.size();
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n; j++) {
            swap(m[i][j], m[n-(i+1)][j]);
        }
    }
}
bool isEqual(Matrix &x, Matrix &y) {
    return x == y;
}
int rotate(Matrix &x, Matrix &y, bool &v, bool &r) {
    int a;
    bool f = false;
    for(int i = 0; i < 3 && !f; i++) {
        v = isEqual(x, y);
        if(!v) {
            reflect(x);
            r = isEqual(x, y);
            if(!r) {
                reflect(x);
                rotate90(x);
            }
        }
        if(v || r) {
            f = true;
            a = i;
        }
    }
    return a;
}
void output(Matrix &x, Matrix &y) {
    bool v = false, r = false;
    int d = rotate(x, y, v, r);
    if(deg == 0 && r) {
         cout << "reflected vertically." << endl;
    }
    else {
        if(v) {
            cout << "rotated " << d << " degrees." << endl;
        }
        else if(r) {
            cout << "reflected vertically and rotated " << d << " degrees." << endl;
        }
    }
}
int main() {
    int n, k = 1;
    bool p;
    Matrix x, y;
    while(cin >> n) {
        b = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> x[i][j];
            }
            for(int j = 0; j < n; j++) {
                cin >> y[i][j];
                if(x[i][j] != y[i][j]) {
                    b = false;
                }
            }
        }
        if(!b) {
            output(x, y);
        }
    }
    return 0;
}