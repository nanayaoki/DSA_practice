#include <iostream>
#include <queue>
using namespace std;

class Process {
public:
    int pid, arrival, burst, remaining, waiting, tat, completion, finish;
};

int main() {
    int n, quantum;
    cout << "*** RR Scheduling (Preemptive) ***\n";

    cout << "Enter number of processes: ";  
    cin >> n;

    Process p[n];

    int sumBurst = 0;
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter arrival time for P" << p[i].pid << ": ";
        cin >> p[i].arrival;
        cout << "Enter burst time for P" << p[i].pid << ": ";
        cin >> p[i].burst;

        p[i].remaining = p[i].burst;
        p[i].finish = 0;
        sumBurst += p[i].burst;
        cout << endl;
    }

    cout << "\nEnter time quantum: ";
    cin >> quantum;

    // Sort by arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    queue<int> q;
    int time = p[0].arrival;
    q.push(0);

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        if(p[i].remaining <= quantum) {
            time += p[i].remaining;
            p[i].remaining = 0;
            p[i].finish = 1;
            p[i].completion = time;
            p[i].tat = p[i].completion - p[i].arrival;
            p[i].waiting = p[i].tat - p[i].burst;
        }
        else {
            time += quantum;
            p[i].remaining -= quantum;
        }

        for(int j = 0; j < n; j++) {
            if(p[j].arrival <= time && p[j].finish == 0) {
                bool already = false;
                queue<int> temp = q;
                while(!temp.empty()) {
                    if(temp.front() == j) already = true;
                    temp.pop();
                }
                if(!already && j != i)
                    q.push(j);
            }
        }

        if(p[i].finish == 0)
            q.push(i);
    }

    cout << "\nProcessor\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    cout << "-------------------------------------------------------------\n";

    double avgTAT = 0, avgWT = 0;

    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t\t" << p[i].arrival << "\t" << p[i].burst 
             << "\t" << p[i].completion << "\t\t" << p[i].tat 
             << "\t" << p[i].waiting << endl;

        avgTAT += p[i].tat;
        avgWT += p[i].waiting;
    }

    cout << "\nAverage Turn Around Time: " << avgTAT / n;
    cout << "\nAverage Waiting Time: " << avgWT / n << endl;

    return 0;
}
