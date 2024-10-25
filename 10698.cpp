/*
    Santiago Guevara Idarraga
    Problem: 10698 Football Sort
*/

#include <string.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Team {
    public:
        char name[16];
        int points, gamesPlayed, scoredGoals, sufferedGoals;
        Team(char n[16]) {
            strcpy(name, n);
            points = 0;
            gamesPlayed = 0;
            scoredGoals = 0;
            sufferedGoals = 0;
        }
        int goalDifference() {
            return scoredGoals - sufferedGoals;
        }
        float porcentage() {
            return points/(gamesPlayed*3) * 100;
        }
        bool operator<(Team* b) {
            bool ans = false;
            if(points != b->points) {
                ans = points > b->points;
            }
            else if(goalDifference() != b->goalDifference()) {
                ans = goalDifference() > b->goalDifference();
            }
            else if(scoredGoals != b->scoredGoals) {
                ans = scoredGoals > b->scoredGoals;
            }
            else if(name != b->name) {
                ans = name > b->name;
            }
            return ans;
        }
        bool operator==(Team* b) {
            bool ans = false;
            if(points == b->points && goalDifference() == b->goalDifference() && scoredGoals == b->scoredGoals) {
                ans = true;
            }
            return ans;
        }
};
int main() {
    int t, g, s, s2;
    char n[16], n2[16];
    Team *team, *team2;
    map<string, Team*> teams;
    vector<Team*> classification;
    while(scanf("%d %d", &t, &g) && t != 0 && g != 0) {
        while(t--) {
            scanf("%s", n);
            team = new Team(n);
            teams[n] = team;
        }
        while(g--) {
            scanf("%s %d - %d %s", n, &s, &s2, n2);
            team = teams[n];
            team2 = teams[n2];
            if(s != s2) {
                if(s > s2) {
                    team->points+=3;
                }
                else if(s < s2) {
                    team2->points+=3;
                }
            }
            else {
                team->points+=1;
                team2->points+=1;
            }
            team->scoredGoals+=s;
            team2->scoredGoals+=s2;
            team->sufferedGoals+=s2;
            team2->sufferedGoals+=s;
            team->gamesPlayed++;
            team2->gamesPlayed++;
        }
        map<string, Team*>::iterator it;
        for(it = teams.begin(); it != teams.end(); it++) {
            classification.push_back(it->second);
        }
        sort(classification.begin(), classification.end());
        for(int i = 0; i < t; i++) {
            team = classification[i];
            team2 = classification[i-1];
            if(team == team2) {
                printf("%15s %3d %3d %3d %3d %3d     %.2f\n", team->name, team->points, team->gamesPlayed, team->scoredGoals, team->sufferedGoals, team->goalDifference(), team->porcentage());
            }
            else {
                printf(" %d. %15s %3d %3d %3d %3d %3d     %.2f\n", i+1, team->name, team->points, team->gamesPlayed, team->scoredGoals, team->sufferedGoals, team->goalDifference(), team->porcentage());
            }
        }
        teams.clear();
        classification.clear();
    }
    return 0;
}
