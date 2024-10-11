/*
    Santiago Guevara Idarraga
    Problem: 466 Mirror, Mirror
*/

#include <iostream>
#include <string>

using namespace std;

void rotate90(vector<vector<char>> p) {
    for(int i = 0; i < p.size(); i++) {
        for(int j = 0; j < p.size(); j++) {
            swap(p[i][j], p[j][i]);
            swap(p[i][j], [i][p.size()-(j+1)]);
        }
    }
}
void rotate180(vector<vector<char>> p) {
    
}
void rotate270(vector<vector<char>> p{
    
}
void reflect(vector<vector<char>> p) {
    
}
bool verifyPattern(vector<vector<char>> p, vector<vector<char>> r) {
    bool ans = true;
    for(int i = 0; i < p.size() && ans; i++) {
        for(int j = 0; i < p.size() && ans; j++) {
            if(p[i][j] != r[i][j]) {
                ans = false;
            }
        }
    }
    return ans;
}
int main() {
    int n, k = 1;
    bool preserved;
    string line;
    while(cin >> n) {
        vector<vector<char>> p (n , vector<char> (n)), r (n , vector<char> (n));
        preserved = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> p[i][j];
            }
            for(int j = 0; j < n; j++) {
                cin >> r[i][j];
                if(p[i][j] != r[i][j]) {
                    preserved = false;
                }
            }
        }
        cout << "Pattern " << k << " was ";
        if(!preserved) {
            
        }
        else {
            cout << "preserved." << endl;
        }
        k++;
    }
    return 0;
}