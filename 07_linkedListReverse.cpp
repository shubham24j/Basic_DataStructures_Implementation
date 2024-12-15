#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* convertArr2LL(vector<int> arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node * mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

void traversal(Node* head){
    cout << "Linked List: ";
    Node* temp = head;

    while(temp){
        if(temp->next){
            cout << temp->data << " -> ";
        } else{
            cout << temp->data;
        }
        temp = temp->next;
    }

    cout << endl << endl;
}

Node* reverseTheLL(Node* head){
    if(head == NULL) return head;

    Node* mover = head;
    Node* previous = nullptr;

    while(mover != NULL){
        Node* front = mover->next;
        mover->next = previous;
        previous = mover;
        mover = front;
    }

    return previous;
}

int main(){
    vector<int> arr = {5, 3, 69, 22, 9, 0, 66};
    vector<int> emptArr;

    Node* head = convertArr2LL(arr);
    traversal(head);

    head = reverseTheLL(head);
    traversal(head);
}