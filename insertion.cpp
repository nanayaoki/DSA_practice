#include<iostream>
#include<string>
using namespace std;

int main()
{
    int pos, element;
    int arr[10] = {1, 2, 3, 4, 5};
    cout << "Enter the position to insert thee element : ";
    cin >> pos;
    cout << "Enter the element to be inserted : ";
    cin >> element;
    for(int i=5;i>pos;--i)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    cout << "The new array is : ";
    for(int i=0;i<6;i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}