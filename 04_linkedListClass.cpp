#include<bits/stdc++.h>
using namespace std;

class Node{
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

Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node * mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        mover->next = newNode;
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
            cout << temp->data << endl;
        }

        temp = temp->next;
    }
}

int lengthOfLL(Node* head){
    int length = 0;
    Node* temp = head;

    while(temp){
        length++;
        temp = temp->next;
    }

    return length;
}

bool checkInLL(Node* head, int ele){
    Node* mover = head;

    while(mover){
        if(mover->data == ele){
            return true;
        }
        mover = mover->next;
    }

    return false;
}




int main(){
    vector<int> arr = {5, 3, 69, 22, 9, 0, 66};
    Node* head = convertArr2LL(arr);
    traversal(head);
    int length = lengthOfLL(head);
    cout << "Length of the LL is: " << length << endl;
    cout << "Is 99 present in the LL: " << checkInLL(head, 99) << endl;
    cout << "Is 66 present in the LL: " << checkInLL(head, 66) << endl;
}
