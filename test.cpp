/*
    Santiago Guevara Idarraga
    Problem: 10698 Football Sort
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    string name;
    int points, games, scored, suffered;
    Team(string n) {
        name = n;
        points = games = scored = suffered = 0;
    }
};
float goalDifference(Team* t) {
    return t->scored - t->suffered;
}
bool operation(Team* a, Team* b) {
    bool ans = false;
    if(a->points != b->points) {
        ans = a->points > b->points;
    }
    else if(goalDifference(a) != goalDifference(b)) {
        ans = goalDifference(a) > goalDifference(b);
    }
    else if(a->scored != b->scored) {
        ans = a->scored > b->scored;
    }
    else if(a->name != b->name) {
        ans = a->name > b->name;
    }
    return ans;
}
int main() {
    int t, g, s1, s2;
    string n, home, away;
    char c;
    Team *t1, *t2;
    map<string, Team*> teams;
    while(scanf("%d %d", &t, &g) && t != 0 && g != 0) {
        vector<Team*> ans;
        while(t--) {
            cin >> n;
            teams[n] = new Team(n);
        }
        while(g--) {
            cin >> home >> s1 >> c >> s2 >> away;
            t1 = teams[home];
            t2 = teams[away];
            if(s1 == s2) {
                t1->points++;
                t2->points++;
            }
            else if(s1 > s2) {
                t1->points += 3;
            }
            else if(s1 < s2) {
                t2->points += 3;
            }
            t1->scored += s1;
            t2->scored += s2;
            t1->suffered += s2;
            t2->suffered += s1;
            t1->games++;
            t2->games++;
        }
        for(auto it = teams.begin(); it != teams.end(); it++) {
            ans.push_back(it->second);
        }
        sort(ans.begin(), ans.end(), operation);
        for(int i = 0; i < ans.size(); i++) {
            cout << i+1
                << ans[i]->name << ans[i]->points << ans[i]->games
                << ans[i]->scored << ans[i]->suffered << goalDifference(ans[i])
                << ((ans[i]->games == 0) ? "N/A" : to_string(100 * ans[i]->points/3 * ans[i]->games))
                << endl;
        }
    }
    return 0;
}
