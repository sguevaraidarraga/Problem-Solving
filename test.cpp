/*
    Santiago Guevara Idarraga
    Problem: 10698 Football Sort
*/

#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    char name[16];
    int points, games, scored, suffered;
    Team(char n[16]) {
        strcpy(name, n);
        points = games = scored = suffered = 0;
    }
};
int goalDifference(Team* t) {
    return t->scored - t->suffered;
}
float percentage(Team* t) {
    return (100.0f * t->points) / (3.0f * t->games);
}
bool operation(Team* a, Team* b) {
    bool ans = false;
    if(a->points != b->points) {
        ans = a->points < b->points;
    }
    else if(goalDifference(a) != goalDifference(b)) {
        ans = goalDifference(a) < goalDifference(b);
    }
    else if(a->scored != b->scored) {
        ans = a->scored < b->scored;
    }
    else if(a->name != b->name) {
        ans = a->name < b->name;
    }
    return ans;
}
bool equal(Team* a, Team* b) {
    bool ans = false;
    if(a->points == b->points && goalDifference(a) == goalDifference(b) && a->scored == b->scored) {
        ans = true;
    }
    return ans;
}
int main() {
    int t, g, s1, s2;
    char n[16], home[16], away[16];
    Team *t1, *t2;
    map<string, Team*> teams;
    while(scanf("%d %d", &t, &g) && t != 0 && g != 0) {
        vector<Team*> ans;
        while(t--) {
            scanf("%s", n);
            teams[n] = new Team(n);
        }
        while(g--) {
            scanf("%s %d - %d %s", home, &s1, &s2, away);
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
        for(map<string, Team*>::iterator it = teams.begin(); it != teams.end(); it++) {
            ans.push_back(it->second);
        }
        sort(ans.begin(), ans.end(), operation);
        for(int i = 0; i < ans.size(); i++) {
            if(i == 0 || !equal(ans[i], ans[i-1])) {
                printf(" %d. %16s %3d %3d %3d %3d %3d    ", i+1, ans[i]->name, ans[i]->points, ans[i]->games, ans[i]->scored, ans[i]->suffered, goalDifference(ans[i]));
            }
            else {
                printf(" %19s %3d %3d %3d %3d %3d    ", ans[i]->name, ans[i]->points, ans[i]->games, ans[i]->scored, ans[i]->suffered, goalDifference(ans[i]));
            }
            if(ans[i]->games == 0) {
                printf("N/A\n");
            }
            else {
                printf("%.2f\n", percentage(ans[i]));
            }
        }
    }
    return 0;
}
