#include<iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the number of elements = ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements in araay ";

    for (int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    cout << "The entered array is : ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    int k;
    cout << "Enter the size of subarray = ";
    cin >> k;

    cout << "The minimum element in each subarray of size " << k << " is " ;

    for (int i=0;i<=n-k;i++){
        int min = arr[i];
        for (int j=i;j<i+k;j++){
            if(arr[j]<min){
                min = arr[j];
            }
        }
        cout << min << " ";
    }
    return 0;
}