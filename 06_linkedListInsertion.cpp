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

Node* insetAtBeginingOfLL(Node* head, int value){
    Node* newNode = new Node(value, head);
    cout << value << " is inserted successfully at the start." << endl;
    return newNode;
}

Node* insertAtEndOfLL(Node* head, int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        cout << value << " is inserted successfully at the end." << endl;
        return newNode;
    }

    Node* mover = head;
    while(mover->next != NULL){
        mover = mover->next;
    }

    mover->next = newNode;
    cout << value << " is inserted successfully at the end." << endl;
    
    return head;
}

Node* insertAtKthPositonOfLL(Node* head, int value, int position){
    Node* newNode = new Node(value);
    if(position == 1){
        newNode->next = head;
        cout << value << " is inserted successfully at position " << position << "." << endl;
        return newNode;
    }

    Node* mover = head;
    int current = 1;

    while(mover != NULL){
        if(current == position - 1){
            newNode->next = mover->next;
            mover->next = newNode;
            cout << value << " is inserted successfully at position " << position << "." << endl;
            return head;
        }
        mover = mover->next;
        current++;
    }

    cout << value << " can't be inserted as " << position << " is out of bound." << endl;
    return head;
}

Node* insertBeforeValueInLL(Node* head, int value, int before){
    Node* newNode = new Node(value);
    if(head->data == before){
        newNode->next = head;
        cout << value << " is inserted successfully at before " << before << "." << endl;
        return newNode;
    }

    Node* mover = head;

    while(mover->next != NULL){
        if(mover->next->data == before){
            newNode->next = mover->next;
            mover->next = newNode;
            cout << value << " is inserted successfully at before " << before << "." << endl;
            return head;
        }
        mover = mover->next;
    }

    cout << value << " can't be inserted as " << before << " is not present in the LL." << endl;
    return head;
}

int main(){
    vector<int> arr = {5, 3, 69, 22, 9, 0, 66};
    vector<int> emptArr;

    Node* head = convertArr2LL(arr);
    traversal(head);

    head = insetAtBeginingOfLL(head, 45);
    traversal(head);

    head = insertAtEndOfLL(head, 100);
    traversal(head);

    head = insertAtKthPositonOfLL(head, -1, 4);
    traversal(head);

    head = insertAtKthPositonOfLL(head, -11, 1);
    traversal(head);

    head = insertAtKthPositonOfLL(head, -18, 12);
    traversal(head);

    head = insertAtKthPositonOfLL(head, -100, 14);
    traversal(head);

    head = insertBeforeValueInLL(head, 21, 22);
    traversal(head);
}