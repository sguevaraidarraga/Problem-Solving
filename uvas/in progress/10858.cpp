/*
    Santiago Guevara Idarraga
    Problem: 10858 Unique Factorization
*/

#include <iostream>
#include <vector>

#define matrix vector<vector<int>>

using namespace std;

void factorization(matrix &m, vector<int> &v, int x) {
    vector<int> tmp;
    for(int i = 0; i < x; i++) {
        for(int j = 2; j < x; j++) {
            if(x%j == 0) {
                tmp.push_back(x/j);
            }
        }
    }
}
int main() {
    int n;
    while(cin >> n && n != 0) {
        
    }
    return 0;
}