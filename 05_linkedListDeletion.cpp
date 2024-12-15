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
            cout << temp->data << endl << endl;
        }
        temp = temp->next;
    }
}

Node* deleteHeadOfLL(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* deleteTailOfLL(Node* head){
    if(head == NULL || head->next == NULL) return nullptr;

    Node* mover = head;
    while(mover->next->next){
        mover = mover->next;
    }
    delete mover->next;
    mover->next = nullptr;

    return head;
}


Node* deleteKthNodeUsingPrev(Node* head, int k) {
    if (head == NULL || k <= 0) {
        return head; 
    }

    if (k == 1) { 
        Node* temp = head;
        head = head->next;
        cout << "Deleted Positon " << k << " from the LL." << endl;
        delete temp;
        return head;
    }

    Node* mover = head;
    Node* previous = NULL;
    int current = 1;

    while (mover != NULL) {
        if (current == k) {
            previous->next = mover->next;
            cout << "Deleted Positon " << k << " from the LL." << endl;
            delete mover;
            return head; 
        }
        previous = mover;
        mover = mover->next;
        current++;
    }

    cout << "Position " << k << " is out of bounds.\n";
    return head;
}

Node* deleteValueFromLL(Node* head, int val){
    if(head == NULL) return head;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << val << " from the LL." << endl;
        delete temp;
        return head;
    }

    Node* mover = head;
    Node* previous = nullptr;
    
    while(mover){
        if(mover->data == val){
            previous->next = previous->next->next;
            cout << "Deleted " << val << " from the LL." << endl;
            delete mover;
            return head;
        }
        previous = mover;
        mover = mover->next;
    }

    cout << val << " is not present in the LL." << endl;
    return head;
}

int main(){
    vector<int> arr = {5, 3, 69, 22, 9, 0, 66};
    Node* head = convertArr2LL(arr);
    traversal(head);

    head = deleteHeadOfLL(head);
    cout << "Deleted Head of LL." << endl;
    traversal(head);

    head = deleteTailOfLL(head);
    cout << "Deleted Tail of LL." << endl;
    traversal(head);

    int k = 2;
    head = deleteKthNodeUsingPrev(head, k);
    traversal(head);

    k = 3;
    head = deleteKthNodeUsingPrev(head, k);
    traversal(head);

    int val = 22;
    head = deleteValueFromLL(head, val);
    traversal(head);

    val = 3;
    head = deleteValueFromLL(head, val);
    traversal(head);

    val = 4;
    head = deleteValueFromLL(head, val);
    traversal(head);

    val = 0;
    head = deleteValueFromLL(head, val);
    traversal(head);
}

// Node* deleteKthNode(Node* head, int k) {
//     if (head == NULL || k <= 0) return head; // Handle empty list or invalid k

//     if (k == 1) { // Delete the head node
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return head;
//     }

//     Node* mover = head;
//     int currentPos = 1;

//     // Traverse to the (k-1)th node
//     while (mover != NULL && currentPos < k - 1) {
//         mover = mover->next;
//         currentPos++;
//     }

//     // Check if the (k-1)th node and the kth node exist
//     if (mover == NULL || mover->next == NULL) {
//         cout << "Position " << k << " is out of bounds.\n";
//         return head;
//     }

//     // Delete the kth node
//     Node* temp = mover->next;
//     mover->next = mover->next->next;
//     delete temp;

//     return head;
// }


// Node* deleteAllOccuranceOfValueFromLL(Node* head, int val) {
//     if (head == NULL) return head;

//     // Handle deletion of nodes at the head
//     while (head != NULL && head->data == val) {
//         Node* temp = head;
//         head = head->next;
//         cout << "Deleted " << val << " from the LL." << endl;
//         delete temp;
//     }

//     // Use two pointers to traverse the list
//     Node* mover = head;
//     Node* previous = nullptr;

//     while (mover != NULL) {
//         if (mover->data == val) {
//             // Delete the current node and update the previous pointer
//             previous->next = mover->next;
//             cout << "Deleted " << val << " from the LL." << endl;
//             delete mover;
//             mover = previous->next; // Update the mover pointer to the next node
//         } else {
//             // Move both pointers forward
//             previous = mover;
//             mover = mover->next;
//         }
//     }

//     cout << "All occurrences of " << val << " are deleted from the LL." << endl;
//     return head;
// }


// traversal(head);
// head = deleteTailOfLL(head);
// traversal(head);
// head = deleteTailOfLL(head);
// traversal(head);
// head = deleteTailOfLL(head);
// traversal(head);
// head = deleteTailOfLL(head);
// traversal(head);
// head = deleteTailOfLL(head);
// traversal(head);