#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }

    Node(int value, Node* next1){
        data = value;
        next = next1;
    }    
};

int main(){
    vector<int> arr = {5, 3, 69, 22, 66};

    // This is NOT the ideal way to create a new node
    // Here n0 is the variable
    Node n0 = Node(arr[0]);
    // cout << n0 << endl; This is not possible
    cout << "n0 data = " << n0.data << endl;
    Node* add = &n0;
    cout << "n0 address = " << add << endl;

    // This is the ideal way to create new node
    // Here n1 is not the variable it is the pointer
    Node *n1 = new Node(arr[0]);
    cout << "n1: " << n1 << endl;
    cout << "n1 data = " << n1->data << endl << endl;

    n1->next = add;
    cout << "n1: " << n1 << endl;
    cout << "Data: " << n1->data << "   Next: " << n1->next << endl;
    cout << "n0: " << add << endl;
    cout << "Data: " << n0.data << "   Next: " << n0.next << endl;
}
