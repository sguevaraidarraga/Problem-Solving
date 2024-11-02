/*
    Santiago Guevara Idarraga
    Problem: 10194 Football
*/

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Team {
    public:
        string name;
        int points, games, wins, ties, losses, scored, against;
        Team() = default;
        Team(string n) {
            name = n;
            points = games = wins = ties = losses = scored = against = 0;
        }
        int difference() {
            return scored - against;
        }
        bool operator<(Team &b) {
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
    int n, t, g, s1, s2;
    string tournament, tName;
    char n1[31], n2[31];
    Team *tm, *t1, *t2;
    while(cin >> n) {
        cout << "n: " << n << endl;
        while(n--) {
            getline(cin, tournament);
            cin >> t;
            cout << "tournament name: " << tournament << endl;
            cout << "t: " << t << endl;
            map<string, Team> teams;
            vector<Team> ans;
            while(t--) {
                getline(cin, tName);
                teams[tName] = Team(tName);
            }
            cin >> g;
            cout << "g: " << g << endl;
            while(g--) {
                scanf("%30[^#]#%d@%d#%30[^\n]", n1, &s1, &s2, n2);
                //printf("%s %d - %d %s\n", n1, s1, s2, n2);
                t1 = &teams[n1];
                t2 = &teams[n2];
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
            for(map<string, Team>::iterator it = teams.begin(); it != teams.end(); it++) {
                ans.push_back(it->second);
            }
            sort(ans.begin(), ans.end());
            cout << tournament << endl;
            for(int i = 0; i < ans.size(); i++) {
                tm = &ans[i];
                printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, tm->name.c_str(), tm->points, tm->games, tm->wins, tm->ties, tm->losses, tm->difference(), tm->scored, tm->against);
            }
            cout << endl;
        }
    }
    return 0;
}
