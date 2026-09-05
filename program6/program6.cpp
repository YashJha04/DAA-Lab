#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

// Compare items based on value/weight ratio
bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort items according to value/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    // Select items greedily
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the complete item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            // Take the fraction of the item
            totalValue += (double)items[i].value / items[i].weight * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}