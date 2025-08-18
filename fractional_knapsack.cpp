/*
You are given N items, each with a specific value and weight. You are also given a knapsack with a maximum capacity (in terms of weight). Your task is to maximize the total value of items in the knapsack.

Unlike the 0/1 knapsack problem, you are allowed to take fractions of items. For example, you can take half of an item, which contributes half its weight and half its value.
*/

#include <bits/stdc++.h>
using namespace std;


double maxValue(vector<vector<int>> items, int capacity) {
    map < double, vector<int>, greater<double>> valueWeight;
    for (const auto& pair : items) {
        if (pair[1] != 0) {
            double ratio = (double) pair[0] / pair[1];
            valueWeight.insert(make_pair(ratio, pair));
        }
        
    }
    double value = 0;
    for (const auto& pair : valueWeight) {
        if (capacity > pair.second[1]) {
            value += pair.second[0];
            capacity -= pair.second[1];
        } else {
            value += ((double) capacity / pair.second[1]) * pair.second[0];
            break;
        } 

    }
    return value;
}


int main() {
    vector<vector<int>> items = {{2, 4}, {3, 5}, {4, 7}};

    int capacity = 10;

    double max_value = maxValue(items, capacity);

    cout << max_value;

    return 0;
}
