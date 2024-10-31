/*
    Santiago Guevara Idarraga
    Problem: 10194 Football
*/

#include <string>
#include <iostream>

using namespace std;

struct Team {
    string name;
    int rank, points, games, wins, ties, losses, scored, against;
    Team(string n) {
        name = n;
        rank = points = games = wins = ties = losses = scored = against = 0;
    }
};
int main() {
    int n, t, g, score1, score2;
    string tournament, team;
    char team1[30], team2[30];
    while(cin >> n) {
        while(n--) {
            getline(cin, tournament);
            cin >> t;
            while(t--) {
                getline(cin, team);
            }
            cin >> g;
            while(g--) {
                scanf("%30[^#]#%d@%d#%30[^\n]", team1, &score1, &score2, team2);
            }
        }
    }
    return 0;
}