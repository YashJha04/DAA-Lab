#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};

// Compare activities based on finish time
bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;

    Activity activities[n];

    cout << "Enter start and finish time of each activity:\n";

    for (int i = 0; i < n; i++) {
        cin >> activities[i].start >> activities[i].finish;
    }

    // Sort activities according to finish time
    sort(activities, activities + n, compare);

    cout << "\nSelected Activities:\n";

    // Select the first activity
    int lastFinish = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {

        // Select activity if it does not overlap
        if (activities[i].start >= lastFinish) {
            cout << "(" << activities[i].start
                 << ", " << activities[i].finish << ")" << endl;

            lastFinish = activities[i].finish;
            count++;
        }
    }

    cout << "\nMaximum number of activities = " << count << endl;

    return 0;
}