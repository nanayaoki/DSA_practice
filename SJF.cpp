#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int completed = 0, currentTime = 0;
    bool done[n] = {false};
    float totalWT = 0, totalTAT = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time and Burst Time for P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    // Scheduling loop
    while (completed < n) {
        int idx = -1;
        int minBT = 1e9; // large value

        // Select process with smallest burst time among arrived ones
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= currentTime) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        // CPU Idle
        if (idx == -1) {
            currentTime++;
        } else {
            // Execute selected process
            ct[idx] = currentTime + bt[idx]; // Completion Time
            currentTime = ct[idx];
            done[idx] = true;
            completed++;
        }
    }

    // Calculate Turnaround and Waiting times
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        totalWT += wt[i];
        totalTAT += tat[i];
    }

    // Display results
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t" << at[i] << "\t" << bt[i]
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    cout << "\nAverage Turnaround Time = " << totalTAT / n;
    cout << "\nAverage Waiting Time = " << totalWT / n << endl;

    return 0;
}
