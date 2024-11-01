/*
    Santiago Guevara Idarraga
    Problem: 10194 Football
*/

#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Team {
    public:
        string name;
        int rank, points, games, wins, ties, losses, scored, against;
        Team(string n) {
            name = n;
            rank = points = games = wins = ties = losses = scored = against = 0;
        }
        int difference() {
            return scored - against;
        }
        bool operator<(const Team &b) const {
            bool ans = false;
            if(points != b.points) {
                ans = points > b.points;
            }
            else if(wins != b.wins) {
                ans = wins > b.wins;
            }
            else if(difference() != b.difference()) {
                ans = difference() > b.difference();
            }
            else if(scored != b.scored) {
               ans = scored > b.scored; 
            }
            else if(games != b.games) {
                ans = games < b.games;
            }
            else if(name != b.name) {
                ans = name > b.name;
            }
            return ans;
        }
};
int main() {
    int n, t, g;
    map<string, Team> teams;
    vector<Team> ans;
    while(cin >> n) {
        cin.ignore();
        while(n--) {
            getline(cin, tournament);
            cin >> t;
            cin.ignore();
            while(t--) {
                getline(cin, team);
                teams[team] = Team(team);
            }
            cin >> g;
            cin.ignore();
            while(g--) {
                scanf("%30[^#]#%d@%d#%30[^\n]", team1, &s1, &s2, team2);
                //printf("%30s %d - %d %30s", team1, s1, s2, team2);
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
            int i = 0;
            for(auto it = teams.begin(); it != teams.end(); it++) {
                t1 = it->second;
                printf("%d) %30s %dp, %dg (%d-%d-%d), %dgd (%d-%d)", i++, t1->name.c_str(), t1->points, t1->games, t1->wins, t1->ties, t1->losses, t1->difference(), t1->scored, t1->against);
            }
            teams.clear();
            ans.clear();
        }
    }
    return 0;
}
