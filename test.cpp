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
