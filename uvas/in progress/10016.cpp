/*
    Santiago Guevara Idarraga
    Problem: 10016 Flip-Flop the Squarelotron
*/

#include <iostream>
#include <vector>

#define matrix vector<vector<int>>

using namespace std;

void upsideDownFlip(int r, matrix &m) {
    int n = m.size(), rBeg = r-1, rEnd = n-r, row = 0;
    for(int i = rBeg; i < n/2; i++) {
        for(int j = rBeg; j <= rEnd; j++) {
            if(i == rBeg || j == rBeg || j == rEnd) {
                swap(m[i][j], m[rEnd-row][j]);
            }
        }
        row++;
    }
}
void leftRightFlip(int r, matrix &m) {
    int n = m.size(), rBeg = r-1, rEnd = n-r, col;
    for(int i = rBeg; i <= rEnd; i++) {
        col = 0;
        for(int j = rBeg; j < n/2; j++) {
            if(i == rBeg || i == rEnd || j == rBeg) {
                swap(m[i][j], m[i][rEnd-col]);
            }
            col++;
        }
    }
}
void mainInverseDiagonalFlip(int r, matrix &m) {
    int n = m.size(), rBeg = r-1, rEnd = n-r;
    for(int i = rBeg; i <= rEnd; i++) {
        for(int j = rBeg; j <= rEnd-i; j++) {
            if(i == rBeg || i == rEnd || j == rBeg || j == rEnd) {
                swap(m[i][j], m[n-1-j][n-1-i]);
            }
        }
    }
}
void mainDiagonalFlip(int r, matrix &m) {
    int n = m.size(), rBeg = r-1, rEnd = n-r;
    for(int i = rBeg; i <= rEnd; i++) {
        for(int j = rBeg; j <= i; j++) {
            if(i == rBeg || i == rEnd || j == rBeg || j == rEnd) {
                swap(m[i][j], m[j][i]);
            }
        }
    }
}
void printMat(matrix &m) {
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m.size(); j++) {
            cout << m[i][j];
            if(j != m.size()-1) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
int main() {
    int cases, n, rings, t, c;
    cin >> cases;
    while(cases--) {
        cin >> n;
        matrix m(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        rings = (n%2 == 0) ? n/2 : n/2 + 1;
        for(int r = 1; r <= rings; r++) {
            cin >> t;
            while(t--) {
                cin >> c;
                switch(c) {
                    case 1:
                        upsideDownFlip(r, m);
                        break;
                    case 2:
                        leftRightFlip(r, m);
                        break;
                    case 3:
                        mainDiagonalFlip(r, m);
                        break;
                    case 4:
                        mainInverseDiagonalFlip(r, m);
                        break;
                }
            }
        }
        printMat(m);
    }
    return 0;
}