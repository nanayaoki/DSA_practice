#include<iostream>
using namespace std;


int selection_sort(int arr[],int n){
    for(int i = 0 ;i < n-1 ; i++){
        int min = i;
        for(int j= i+1;j<n;j++) {
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
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

    selection_sort(arr,n);

    cout << "Sorted array is: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}