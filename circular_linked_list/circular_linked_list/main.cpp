//
//  main.cpp
//  circular_linked_list
//
//  Created by helloKaviraj MBP on 27/04/21.
//

#include <iostream>
using namespace std;

//######################## Section - 1 #################################
// Circular singly linked list creating 4 node
/*struct Node {
    // our node is same as singly linked list no chage, also same you can do with doubly linked list
    int data;
    Node *next;//self referencing pointer
    Node(int d) {
        data = d;
        next = NULL;
    }
};

int main() {
    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);
    // Till now all process is same as signly linked list but here last node points to head node
    head -> next -> next -> next -> next = head;
    return 0;
}*/

//######################## End of Section - 1 #################################





//######################## Section - 2 #################################
// Traversal of a circular linked list
/*struct Node {
    // our node is same as singly linked list no chage, also same you can do with doubly linked list
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};


// Traversal function method 1
void traversalCircular(Node *head) {
    if (head == NULL) {
        return;
    }
    cout << head -> data << " ";
    // imp to print first node and start from second
    for (Node *p = head -> next; p != head; p = p -> next) {
        cout << p -> data;
    }
}


// Traversal function method 2 do while loop
void traversalCircular2(Node *head) {
    if (head == NULL) {
        return;
    }
    Node *p = head;// we are using another pointer later to check that is head or not
    do {
        cout << p -> data << " ";
        p = p -> next;
    } while (p != head);
}


int main() {
    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);
    // Till now all process is same as signly linked list but here last node points to head node
    head -> next -> next -> next -> next = head;
    //traversalCircular(head);
    traversalCircular2(head);
    return 0;
}*/
//######################## End of Section - 2 #################################





//######################## Section - 3 #################################
// insert at begin circular linkd list
/*struct Node {
    // our node is same as singly linked list no chage, also same you can do with doubly linked list
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Insert at begin of a circular linked list naive approach line 123 you can see eff approach
//Node* insertBegin(Node *head, int d) {
//    Node *temp = new Node(d);
//    if (head == NULL) {
//        temp -> next = temp;
//    } else {
//        Node *curr = head;
//        while (curr -> next != head) {
//            curr = curr -> next;
//        }
//        curr -> next = temp;
//        temp -> next = head;
//    }
//    return temp;
//}

//Node* insertBeginStandard(Node *head, int x) {
//    Node *temp = new Node(x);
//    if (head == NULL) {
//        temp -> next = temp;
//        return temp;
//    } else {
//        // added new node between first node and second and linked
//        temp -> next = head -> next;
//        head -> next = temp;
//        // now swapping the first 2 nodes value
//        int t = head -> data;
//        head -> data = temp -> data;
//        temp -> data = t;
//        return head;
//    }
//}

int main() {
    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);
    head -> next -> next -> next -> next = head;
    //call as per your choice either naive or standard approach?
    return 0;
}*/
//######################## Section - 3 #################################







//######################## Section - 4 #################################
// Insert at the end of circular linked list naive approach
/*Node *insertEnd(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        temp -> next = temp;
        return temp;
    } else {
        Node *curr = head;
        while (curr -> next != head) {
            curr = curr -> next;
        }
        curr -> next = temp;
        temp -> next = head;
        return head;
    }
}
*/

// Insert at the end standard approach time complexity is order of (constant)
/*Node *insertEndStandard(Node *head, int x) {
    Node *temp = new Node(x);
    if (head == NULL) {
        temp -> next = temp;
        return head;
    } else {
        temp -> next = head -> next;
        head -> next = temp;
        // swapping
        int t = temp -> data;
        temp -> data = head -> data;
        head -> data = t;
        return temp;
    }
}*/
//######################## End of Section - 4 #################################





//######################## Section - 5 #################################
// Delete head of a circular linked list naive
/*Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head -> next == head) {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr -> next != head) {
        curr = curr -> next;
    }
    // first link the node
    curr -> next = head -> next;
    delete head;
    return curr -> next;  // new head
}*/
// time complexity is O(n)

// Delete head efficient approach
//Node* delHeadEff(Node *head) {
//    if (head == NULL) {
//        return NULL;
//    }
//    // sigle node
//    if (head -> next == head) {
//        delete head;
//        return NULL;
//    }
//    // copying second node data to head node
//    head -> data = head -> next -> data;
//    // line 235 and 236 storing head next in temp cause to be deleted and first node linking to third node
//    Node *temp = head -> next;
//    head -> next = head -> next -> next;
//    delete temp;
//    return head;
//}
// This eff approach deletes a node in O(1) time complexity
//######################## End of Section - 5 #################################






//######################## Section - 6 #################################
// This is an interesting prob of the circular linked list
// delete nth node of a circular linked list
/*struct Node {
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};


// delete kth node a linked list
 // k is the number which one you want to delete
Node* delKthNode(Node *head, int k) {
    if (head == NULL) {
        return head;
    }
    // when k value is 1 means only one node and delete it
    if (k == 1) {
        return deleteHead(head);// another function to del first node
    }
 
    // when k value is 2 or greater
    // you will traverse the node till your deleting node predecessor (for example- 1,2,3,4,5) is an arrray and you want to delete 4 so you will traverse till 3
    Node *curr = head;
    for (int i = 0; i < k - 2; i++) {
        curr = curr -> next;
    }
    //temp you are assigning which node you want to delete
    Node *temp = curr -> next;
    // curr next is the node which you want to delete so link it's successor node
    curr -> next = curr -> next -> next;
    // delete node
    delete temp;
    return head;
}

int main() {
    Node *head = new Node(10);
    head -> next = new Node(5);
    head -> next -> next = new Node(20);
    head -> next -> next -> next = new Node(15);
    // Till now all process is same as signly linked list but here last node points to head node
    head -> next -> next -> next -> next = head;
    // suppose I want to delete 3 node
    int k = 3;
    return 0;
}
*/
//######################## End of Section - 6 #################################
