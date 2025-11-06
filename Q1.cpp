/*1. You have been given an array of positive integers 
A1,A2,...,An with length N and you have to print an array
 of same length(N) where the values in the new array are 
 the sum of every number in the array, except the number 
 at that index. Write program in Python Language. Write a C++ Program */
#include<iostream>
using namespace std;

int add_array(int arr[],int n){
    int sum =0;
    for(int i=0;i<n; i++){
        sum = sum + arr[i];
    } 
    return sum;
}

int display(int arr[],int addition,int n){
    for(int i=0;i<n;i++){
        cout << addition - arr[i] << " ";
    }
    return 0;
}
int main(){

    int n;
    cout << "Enter the number of elements = ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int addition;
    addition = add_array(arr,n);
    
    display(arr,addition,n);

    return 0;
}