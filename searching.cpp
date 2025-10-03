#include<iostream>
#include<string>
using namespace std;   
int main(){
    int arr[10];
    int element,size;\
    cout<<"Enter the size of the array : ";
    cin>>size;
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched : ";
    cin>>element;
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            cout<<"Element found at index "<<i<<endl;
            return 0;
        }
    }
    cout<<"Element not found"<<endl;
    return 0;
}