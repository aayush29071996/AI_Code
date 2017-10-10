//
// Created by Saswat Das on 10/10/17.
//

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    pair<int, int> state;
    int rule; // This will store the rule to be applied
};

pair<int, int> target;
list<pair<int, int>> visited;

bool Visited(Node node) {
    list<pair<int, int>>::iterator it;
    for (it = visited.begin(); it != visited.end(); ++it) {
        if (node.state.first == it->first && node.state.second == it->second) return true;
    }
    visited.push_back(node.state);
    return false;
}

list<int> ruleFitter(Node node) {
    list<int> rules;
    if (node.state.first < 4) rules.push_back(1);
    if (node.state.second < 3) rules.push_back(2);

    if (node.state.first > 0) rules.push_back(3);
    if (node.state.second > 0) rules.push_back(4);

    int combined = node.state.first + node.state.second;
    if (combined > 0 && combined >= 4 && node.state.second > 0) rules.push_back(5);
    if (combined > 0 && combined >= 3 && node.state.first > 0) rules.push_back(6);
    if (combined > 0 && combined >= 4 && node.state.second >= 0) rules.push_back(7);
    if (combined > 0 && combined >= 3 && node.state.first >= 0) rules.push_back(8);
    if (combined > 0 && combined < 4 && node.state.second > 0) rules.push_back(9);
    return rules;
}

void nodeGenerator(Node &prev, list<int> rules, list<Node> &q) {
    list<int>::iterator i;
    for (i = rules.begin(); i != rules.end(); ++i) {
        Node node;
        int intent = *i;
        node.rule = intent;
        if (intent == 1) node.state = make_pair(4, prev.state.second);
        else if (intent == 2) node.state = make_pair(prev.state.first, 3);
        else if (intent == 3) node.state = make_pair(0, prev.state.second);
        else if (intent == 4) node.state = make_pair(prev.state.first, 0);
        else if (intent == 5) node.state = make_pair(4, prev.state.second - (4 - prev.state.first));
        else if (intent == 6) node.state = make_pair(prev.state.first - (3 - prev.state.second), 3);
        else if (intent == 7) node.state = make_pair(min(prev.state.first + prev.state.second, 4), 0);
        else if (intent == 8) node.state = make_pair(0, min(prev.state.first + prev.state.second, 3));
        else if (intent == 9) node.state = make_pair(prev.state.first + prev.state.second, 0);
        if (!Visited(node)) q.push_back(node);
    }
}

void BFS(Node &start) {
    list<Node> q;
    list<int> rules = ruleFitter(start);
    nodeGenerator(start, rules, q);
    while (!q.empty()) {
        Node node = q.front();
        q.pop_front();
        cout << "(" << node.state.first << "," << node.state.second << ") -> ";
        if (node.state.first == 4 && node.state.second == 3) {
            cout << "(not found)\n";
        } else if (node.state.first == target.first && node.state.second == target.second) {
            cout << "(found)";
            break;
        } else {
            list<int> rules = ruleFitter(node);
            nodeGenerator(node, rules, q);
        }
    }
}

void DFS(Node &start) {
    list<Node> q;
    list<int> rules = ruleFitter(start);
    nodeGenerator(start, rules, q);
    while (!q.empty()) {
        Node node = q.back();
        q.pop_back();
        cout << "(" << node.state.first << "," << node.state.second << ") -> ";
        cout << "(" << node.state.first << "," << node.state.second << ") -> ";
        if (node.state.first == 4 && node.state.second == 3) {
            cout << "(not found)\n";
        } else if (node.state.first == target.first && node.state.second == target.second) {
            cout << "(found)";
            break;
        } else {
            list<int> rules = ruleFitter(node);
            nodeGenerator(node, rules, q);
        }
    }
}


int main() {
    int a, b;
    cout << "Enter the desired target";
    cin >> a >> b;
    target = make_pair(a, b);
    Node start;
    start.state = make_pair(0, 0);
    BFS(start);
    return 0;
}