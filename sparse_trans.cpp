#include <iostream>
using namespace std;

int main() {
    // Original sparse matrix in triplet form
    int compact[3][6] = {
        {0, 0, 1, 1, 3, 3},  // Row indices
        {2, 4, 2, 3, 1, 2},  // Column indices
        {3, 4, 5, 7, 2, 6}   // Values
    };

    int size = 6;

    // Transpose: swap row and column
    int transpose[3][size];

    for (int i = 0; i < size; i++) {
        transpose[0][i] = compact[1][i];  // new row = old col
        transpose[1][i] = compact[0][i];  // new col = old row
        transpose[2][i] = compact[2][i];  // value stays the same
    }

    // Sort the transposed matrix by row and then by column
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // Compare rows first, then columns
            if (transpose[0][i] > transpose[0][j] || 
               (transpose[0][i] == transpose[0][j] && transpose[1][i] > transpose[1][j])) {

                // Swap row
                int temp = transpose[0][i];
                transpose[0][i] = transpose[0][j];
                transpose[0][j] = temp;

                // Swap col
                temp = transpose[1][i];
                transpose[1][i] = transpose[1][j];
                transpose[1][j] = temp;

                // Swap value
                temp = transpose[2][i];
                transpose[2][i] = transpose[2][j];
                transpose[2][j] = temp;
            }
        }
    }

    // Output the transposed sparse matrix in triplet form
    cout << "Row\tCol\tValue\n";
    for (int i = 0; i < size; i++) {
        cout << transpose[0][i] << "\t" 
             << transpose[1][i] << "\t" 
             << transpose[2][i] << "\n";
    }

    return 0;
}
