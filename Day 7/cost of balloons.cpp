//  Hackerearth - cost of balloons

/*

1. Input:
Read the number of test cases (test_case).
For each test case:
Read costs of green (cost_g) and purple (cost_p) balloons.
Read the number of participants (participants).

2. Process Participants:
Initialize counters (sum1 and sum2) for green and purple balloons to zero.
For each participant:
Read the quantity of green (q1) and purple (q2) balloons.
Update counts based on participant preferences.

3. Calculate Costs:
Determine the maximum (max) and minimum (min) counts of green and purple balloons.
Determine the maximum (max_cost) and minimum (min_cost) costs of green and purple balloons.

4. Calculate Total Cost:
Calculate the total cost for each test case using the formula: max * min_cost + min * max_cost.

5. Output:
Print the total cost for each test case.

*/

//Solution

#include <iostream>
using namespace std;

int main() {
    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {
        int cost_g, cost_p;
        cin >> cost_g >> cost_p;

        int participants;
        cin >> participants;

        int sum1 = 0, sum2 = 0, max, min, max_cost, min_cost;

        for (int i = 0; i < participants; i++) {
            int q1, q2;
            cin >> q1 >> q2;

            if (q1 == 1) {
                sum1 += 1;
            }

            if (q2 == 1) {
                sum2 += 1;
            }
        }

        if (sum1 > sum2) {
            max = sum1;
            min = sum2;
        } else {
            max = sum2;
            min = sum1;
        }

        if (cost_g > cost_p) {
            max_cost = cost_g;
            min_cost = cost_p;
        } else {
            max_cost = cost_p;
            min_cost = cost_g;
        }

        cout << max * min_cost + min * max_cost << endl;
    }

    return 0;
}
