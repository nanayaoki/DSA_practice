#include<iostream>
using namespace std;


int bubble_sort(int arr[], int n ){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }

        }
    }
    cout << "Sorted array is: "; 
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
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

    bubble_sort(arr, n);

    return 0;
}