/*
    Santiago Guevara Idarraga
    Problem: 10194 Football
*/

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Team {
    string name;
    int rank, points, games, wins, ties, losses, scored, against;
    Team(string n) {
        name = n;
        rank = points = games = wins = ties = losses = scored = against = 0;
    }
};
int difference(Team* t) {
    return t->scored - t->against;
}
bool operation() {
    bool ans;
    return ans;
}
int main() {
    int n, t, g, s1, s2;
    string tournament, team;
    char team1[31], team2[31];
    Team *t1, *t2;
    map<string, Team*> teams;
    vector<Team*> ans;
    while(cin >> n) {
        while(n--) {
            getline(cin, tournament);
            cin >> t;
            while(t--) {
                getline(cin, team);
                teams[team] = new Team(team);
            }
            cin >> g;
            while(g--) {
                scanf("%30[^#]#%d@%d#%30[^\n]", team1, &s1, &s2, team2);
                t1 = teams[team1];
                t2 = teams[team2];
                if(s1 == s2) {
                    t1->points++;
                    t2->points++;
                    t1->ties++;
                    t2->ties++;
                }
                else if(s1 > s2) {
                    t1->points += 3;
                    t1->wins++;
                    t2->losses++;
                }
                else if(s1 < s2) {
                    t2->points += 3;
                    t2->wins++;
                    t1->losses++;
                }
                t1->scored += s1;
                t2->scored += s2;
                t1->against += s2;
                t2->against += s1;
                t1->games++;
                t2->games++;
            }
            teams.clear();
            ans.clear();
        }
    }
    return 0;
}