#include<iostream>
using namespace std;

int main() {
    
    int compact1[3][6] = {
        {0, 0, 1, 1, 3, 3},
        {2, 4, 2, 3, 1, 2},
        {3, 4, 5, 7, 2, 6}
    };
    int size1 = 6;

    
    int compact2[3][4] = {
        {0, 1, 3, 3},
        {4, 2, 0, 2},
        {5, 2, 1, 4}
    };
    int size2 = 4;

    int result[3][size1 + size2]; 
    int i = 0, j = 0, k = 0;

   
    while (i < size1 && j < size2) {
        int r1 = compact1[0][i];
        int c1 = compact1[1][i];
        int r2 = compact2[0][j];
        int c2 = compact2[1][j];

        if (r1 < r2 || (r1 == r2 && c1 < c2)) {
           
            result[0][k] = r1;
            result[1][k] = c1;
            result[2][k] = compact1[2][i];
            i++;
            k++;
        }
        else if (r2 < r1 || (r1 == r2 && c2 < c1)) {
           
            result[0][k] = r2;
            result[1][k] = c2;
            result[2][k] = compact2[2][j];
            j++;
            k++;
        }
        else {
            
            int sum = compact1[2][i] + compact2[2][j];
            if (sum != 0) {
                result[0][k] = r1;
                result[1][k] = c1;
                result[2][k] = sum;
                k++;
            }
            i++;
            j++;
        }
    }

   
    while (i < size1) {
        result[0][k] = compact1[0][i];
        result[1][k] = compact1[1][i];
        result[2][k] = compact1[2][i];
        i++;
        k++;
    }


    while (j < size2) {
        result[0][k] = compact2[0][j];
        result[1][k] = compact2[1][j];
        result[2][k] = compact2[2][j];
        j++;
        k++;
    }

   
    cout << "Row\tCol\tValue\n";
    for (int m = 0; m < k; m++) {
        cout << result[0][m] << "\t"
             << result[1][m] << "\t"
             << result[2][m] << "\n";
    }

    return 0;
}
