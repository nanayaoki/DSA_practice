#include<iostream>
#include<string>
using namespace std;

int main()
{
    int i,pos;
    int arr[6] = {1, 2, 3, 4, 5};
    cout << "Enter the position to delete the element : ";
    cin >> pos;
    for(i=pos;i<5;i++)
    {
        arr[i] = arr[i+1];
    }
    cout << "The new array is : ";
    for(int i=0;i<41;i++)
    {
        cout << arr[i] << " ";
    }   


    return 0;
}