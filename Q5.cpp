#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int in = 0; in < temp.size(); in++) {
        arr[st + in] = temp[in];
    }
}

void mergesort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the scores of each student:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    cout << "\nSorted scores: ";
    for (int val : arr) {
        cout << val << " ";
    }

    cout << "\nHighest score: " << arr[n - 1];
    cout << "\nLowest score: " << arr[0];

    return 0;
}
