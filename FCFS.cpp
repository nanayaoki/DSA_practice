#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time of Process " << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    // Sorting by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // Calculating completion time
    ct[0] = at[0] + bt[0];
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])      // CPU idle until process arrives
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // Calculating TAT and WT
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" 
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    return 0;
}
