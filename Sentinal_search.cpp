#include <iostream>
using namespace std;

int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;  

    int i = 0;
    while (arr[i] != key)
        i++;

    arr[n - 1] = last; 
    if (i < n - 1 || arr[n - 1] == key)
        return i;
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements";
    cin >> n;

    int arr[n];
    cout << "Enter the elements";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to be searched";
    cin >> key;

    int res = sentinelSearch(arr, n, key);
    if(res == -1) cout << "Not found";
    else cout << "Found at index: " << res;
}
