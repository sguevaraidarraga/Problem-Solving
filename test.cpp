/*
    Santiago Guevara Idarraga
    Problem: 466 Mirror, Mirror
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Matrix = vector<string>;

void printMat(Matrix &m) {
    int n = m.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
void rotate90(Matrix &m) {
    int n = m.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
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
    bool a = true;
    int n = x.size();
    for(int i = 0; i < n && a; i++) {
        for(int j = 0; j < n && a; j++) {
            if(x[i][j] != y[i][j]) {
                a = false;
            }
        }
    }
    return a;
}
int rotate(Matrix &x, Matrix &y, bool &v, bool &r) {
    int a = 0;
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
    return a*90;
}
void output(Matrix &x, Matrix &y) {
    bool v = false, r = false;
    int d = rotate(x, y, v, r);
    if(d == 0 && r) {
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
    while(cin >> n) {
        Matrix x(n), y(n);
        p = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> x[i][j];
            }
            for(int j = 0; j < n; j++) {
                cin >> y[i][j];
                if(x[i][j] != y[i][j]) {
                    p = false;
                }
            }
        }
        cout << "Pattern " << k << " was ";
        if(p) {
            cout << "preserved." << endl;
        }
        else {
            output(x, y);
        }
        k++;
    }
    return 0;
}