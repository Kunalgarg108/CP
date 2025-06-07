#include<bits/stdc++.h>
using namespace std;


struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    int currentWeight = 0;

    for (auto& item : items) {
        if (currentWeight + item.weight <= W) {
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            int remain = W - currentWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int value, weight;
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }
    double maxValue = fractionalKnapsack(W, items);
    cout << maxValue << endl;
    return 0;
}
