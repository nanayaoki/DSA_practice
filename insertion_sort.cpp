#include<iostream>
using namespace std;


int insertion_sort(int arr[],int n){
    for(int i = 0 ;i < n-1 ; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return 0;
}

int main(){

    int n;  
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: "; 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insertion_sort(arr,n);

    cout << "Sorted array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}