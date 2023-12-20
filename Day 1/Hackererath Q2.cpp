// Hackerearth Q2
/*
Maximum borders

Input  - 
10
2 15
.....####......
.....#.........
7 9
...###...
...###...
..#......
.####....
..#......
...#####.
.........
18 11
.#########.
########...
.........#.
####.......
.....#####.
.....##....
....#####..
.....####..
..###......
......#....
....#####..
...####....
##.........
#####......
....#####..
....##.....
.#######...
.#.........
1 15
.....######....
5 11
..#####....
.#######...
......#....
....#####..
...#####...
8 13
.....######..
......##.....
########.....
...#.........
.............
#######......
..######.....
####.........
7 5
.....
..##.
###..
..##.
.....
..#..
.#...
14 2
..
#.
..
#.
..
#.
..
..
#.
..
..
..
#.
..
7 15
.###########...
##############.
...####........
...##########..
.......#.......
.....#########.
.#######.......
12 6
#####.
###...
#.....
##....
###...
......
.##...
..##..
...#..
..#...
#####.
####..

Output-
4
5
9
6
7
8
3
1
14
5



Approach 

Read the Number of Test Cases (test):

Read an integer test to determine the number of test cases.
Iterate Through Each Test Case:

Start a loop that iterates test times, representing each test case.
Read Matrix Size (n and m):

Read two integers n and m representing the dimensions of the matrix.
Read Matrix Elements:

Create a 2D array matrix of size n x m to store the matrix elements.
Use nested loops to read each element of the matrix.
Calculate Maximum Black Cells in a Row:

Initialize ma to -1 (to keep track of the maximum number of black cells in a row).
Iterate through each row of the matrix.
Count the number of black cells ('#') in each row.
Update ma if the count of black cells in the current row is greater than the current ma.
Print the Result for Each Test Case:

Print the value of ma for each test case (the maximum number of black cells in a row).
End of Program:

End the program.

*/

#include <iostream>
using namespace std;

int main() {
    int test;
    int ma = -1;
    cin >> test;

    while (test--) {
        int n, m;
        cin >> n;
        cin >> m;

        char matrix[n][m];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }

        ma = 0;

        for (int i = 0; i < n; ++i) {
            int black = 0;

            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '#') {
                    black++;
                    // cout << "check";
                }
            }

            if (black > ma) {
                ma = black;
            }
        }

        cout << ma << endl;
    }

    return 0;
}
