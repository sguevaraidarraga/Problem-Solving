/*
    Santiago Guevara Idarraga
    Problem: 466 Mirror, Mirror
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printMat(vector<string> &m) {
    int n = m.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
void rotate90(vector<string> &m) {
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
bool verifyPattern(vector<string> &original, vector<string> &newPattern) {
    bool ans = true;
    int n = original.size();
    for(int i = 0; i < n && ans; i++) {
        for(int j = 0; j < n && ans; j++) {
            if(original[i][j] != newPattern[i][j]) {
                ans = false;
            }
        }
    }
    return ans;
}
void reflect(vector<string> &original) {
    int n = original.size();
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n; j++) {
            swap(original[i][j], original[n-(i+1)][j]);
        }
    }
}
int rotations(bool &verified, bool &reflected, vector<string> &original, vector<string> &newPattern) {
    int deg = 0;
    verified = verifyPattern(original, newPattern);
    while(deg != 360 && !verified && ! reflected) {
        rotate90(original);
        verified = verifyPattern(original, newPattern);
        if(!verified) {
            reflect(original);
            reflected = verifyPattern(original, newPattern);
            reflect(original);
        }
        deg += 90;
    }
    return deg;
}
int main() {
    int n, deg, k = 1;
    bool verified, reflected;
    vector<string> original, newPattern;
    while(cin >> n) {
        vector<string> original(n), newPattern(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> original[i][j];
            }
            for(int j = 0; j < n; j++) {
                cin >> newPattern[i][j];
            }
        }
        verified = false, reflected = false;
        deg = rotations(verified, reflected, original, newPattern);
        cout << deg << endl;
        cout << "Pattern " << k << " was ";
        if(deg == 0) {
            cout << "preserved." << endl;
        }
        else if(deg != 360) {
            if(verified) {
                cout << "rotated " << deg << " degrees." << endl;
            }
            else if(reflected) {
                cout << "reflected vertically and rotated " << deg << " degrees." << endl;
            }
        }
        else {
            reflect(original);
            if(verifyPattern(original, newPattern)) {
                cout << "reflected vertically." << endl;
            }
            else {
                cout << "improperly transformed." << endl;
            }
        }
        original.clear();
        newPattern.clear();
        k++;
    }
    return 0;
}