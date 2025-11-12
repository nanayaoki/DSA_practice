def round_robin(processes, tq):
    n = len(processes)
    at = [p[1] for p in processes]
    bt = [p[2] for p in processes]
    rt = bt[:]
    ct = [0] * n
    tat = [0] * n
    wt = [0] * n

    curr = 0
    completed = 0
    q = []
    in_queue = [False] * n
    gantt = []

    # Start from earliest arrival
    curr = min(at)

    while completed < n:
        # Add all processes that have arrived till now
        for i in range(n):
            if not in_queue[i] and at[i] <= curr and rt[i] > 0:
                q.append(i)
                in_queue[i] = True

        # If no process is ready, jump to next arrival
        if not q:
            next_arrival = min([at[i] for i in range(n) if rt[i] > 0], default=None)
            if next_arrival is None:
                break  # all done
            curr = max(curr + 1, next_arrival)
            continue

        # Pick first from queue
        i = q.pop(0)
        in_queue[i] = False

        exec_time = min(tq, rt[i])
        start = curr
        curr += exec_time
        rt[i] -= exec_time
        gantt.append((processes[i][0], start, curr))

        # Add new arrivals during execution
        for j in range(n):
            if not in_queue[j] and at[j] <= curr and rt[j] > 0:
                q.append(j)
                in_queue[j] = True

        # If process finished
        if rt[i] == 0:
            ct[i] = curr
            completed += 1
        else:
            q.append(i)
            in_queue[i] = True

    # Calculate TAT & WT
    for i in range(n):
        tat[i] = ct[i] - at[i]
        wt[i] = tat[i] - bt[i]

    # Gantt chart
    print("\nGantt Chart:")
    for g in gantt:
        print(f"| {g[0]} ", end="")
    print("|")
    print("0", end="")
    for g in gantt:
        print(f"   {g[2]}", end="")
    print("\n")

    # Table
    print("Process\tAT\tBT\tCT\tTAT\tWT")
    for i in range(n):
        print(f"{processes[i][0]}\t{at[i]}\t{bt[i]}\t{ct[i]}\t{tat[i]}\t{wt[i]}")

    avg_tat = sum(tat) / n
    avg_wt = sum(wt) / n
    print(f"\nAverage Turnaround Time = {avg_tat:.2f}")
    print(f"Average Waiting Time = {avg_wt:.2f}")


# ---------------- MAIN ----------------
if __name__ == "__main__":
    n = int(input("Enter number of processes: "))
    processes = []
    for i in range(n):
        pid = "P" + str(i + 1)
        at = int(input(f"Enter Arrival Time for {pid}: "))
        bt = int(input(f"Enter Burst Time for {pid}: "))
        processes.append((pid, at, bt))

    tq = int(input("Enter Time Quantum: "))
    round_robin(processes, tq)
