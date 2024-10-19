/*
    Santiago Guevara Idarraga
    Problem: 466 Mirror, Mirror
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Matrix = vector<string>;

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
int rotate(Matrix &x, Matrix &y, bool &v) {
    int a = 0;
    for(int i = 0; i < 4 && !v; i++) {
        v = isEqual(x, y);
        if(!v) {
            rotate90(x);
        }
        a = i;
    }
    return a*90;
}
void output(Matrix &x, Matrix &y) {
    bool v = false;
    int d = rotate(x, y, v);
    if(v) {
        cout << "rotated " << d << " degrees." << endl;
    }
    else {
        reflect(x);
        d = rotate(x, y, v);
        if(v) {
            if(d == 0) {
                cout << "reflected vertically." << endl;
            }
            else {
                cout << "reflected vertically and rotated " << d << " degrees." << endl;
            }
        }
        else {
            cout << "improperly transformed." << endl;
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