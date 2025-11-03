#include<iostream>
using namespace std;


int binary_Search(int arr[], int n , int key){
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;

}
int main(){

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

    int result = binary_Search(arr, n, key);

    if (result == -1){
        cout << "Element not found in the array";
    }
    else{
        cout << "Element found at index " << result;
    }
     
    return 0;
}