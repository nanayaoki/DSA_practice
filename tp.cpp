#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node* next ;

    node(int val){
        data = val;
        next = NULL;
    }
};

class linkedlist{

    public :
    node* head;
    linkedlist(){
        head = NULL;
    }

    void insert(int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    }

    void display(){
        node* temp = head;
        while(temp != NULL){
            cout << temp->data << "-> ";
            temp = temp->next;  
        }
        cout << "NULL" << endl;
        
    }
};

int main(){
    int n,value;
    linkedlist list;
     cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                

    list.display();
    return 0;
}