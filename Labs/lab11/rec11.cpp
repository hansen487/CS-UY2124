//Hansen Chen Lab 11 linked list
#include <iostream>
using namespace std;

//class Node {
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

void listDisplay(Node* hp) {
    Node* p = hp;
    while (p != nullptr) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

Node* listFindTail(Node* hp) {
    if (hp == nullptr) return nullptr;
    Node* p = hp;
    //while (p != nullptr && p->next != nullptr) {
    while (p->next != nullptr) {
        p = p->next;
    }
    return p;
}


void listAddTail(Node*& hp, int data) {
    //Node* nodeToAdd = new Node(data);
    Node* tail = listFindTail(hp);
    if (tail == nullptr) {
        hp = new Node(data);
    } else {
      tail->next = new Node(data);
    }
}

void listAddHead(Node*& hp, int data) {
    // // create a node for the data
    // Node* p = new Node(data);
    // // make our new node "point" to what was the first node
    // p->next = hp;

    // Node* p = new Node(data, hp);
    // // set our head pointer to the new node
    // hp = p;

    hp = new Node(data, hp);
}

void listInsertAfter(Node* prior, int data) {
    // create node
    // set new node to point to the node after prior
    // new Node(data, prior->next);
    // make prior node point to the new node
    prior->next = new Node(data, prior->next);
}

void listRemoveAfter(Node* prior) {
    Node* target = prior->next;
    // make prior node point to the one after the target
    prior->next = prior->next->next;
    // get rid of the target
    delete target;
}

Node* listCopy(Node* hp) {
    if (hp == nullptr) return nullptr;
    // Initialization code
    Node* result = new Node(hp->data);
    Node* lastAdded = result;
    Node* p = hp->next;

    while (p != nullptr) {
        lastAdded->next = new Node(p->data);
        lastAdded = lastAdded->next;
        p = p->next;
    }
    return result;
}

//Node* listCopyV2(Node* hp) {
//    if (hp == nullptr) return nullptr;
//    return new Node(hp->data, listCopyv2(hp->next));
//}

void listClear(Node*& hp) {
    if (hp == nullptr) return;
    while (hp->next != nullptr) {
        listRemoveAfter(hp);
    }
    delete hp;
    hp = nullptr;
}

void listSplice(Node*& l1, Node*& l2, int data){
    listFindTail(l2) -> next = l1 -> next;
    l1 -> next = l2;
}

Node* compare(Node*& ll, Node*& sublist){
    Node* p = ll;
    Node* origin = p;
    Node* q = sublist;
    while (q != nullptr && p != nullptr && p -> data == q -> data){
        if (q -> next == nullptr){
            return origin;
        }
        q = q -> next;
        p = p -> next;

    }
    return nullptr;
}

Node* findorigin(Node*& ll, Node*& sublist){
    Node* p = ll;
    while (p != nullptr && p -> data != sublist -> data){
        p = p -> next;
    }
    return p;
}

void isSubList(Node*& ll, Node*& sublist){
    cout << "Attempt match: ";
    listDisplay(sublist);
    Node* p = ll;
    Node* output = nullptr;
    while (p != nullptr && output == nullptr){
        p = findorigin(p, sublist);
        output = compare(p, sublist);
        if (p != nullptr){
            p = p -> next;
        }
    }
//    while (p != nullptr){
//        while (p -> data != sublist -> data){
//            p = p -> next;
//        }
//        if (p != nullptr){
//            Node* origin = p;
//            while (sublist != nullptr && p != nullptr && p -> data == sublist -> data){
//                if (sublist -> next == nullptr){
//                    output = origin;
//                }
//                sublist = sublist -> next;
//                p = p -> next;
//            }
//        }
//    }

    if (output == nullptr){
        cout << "Failed to match\n" << endl;
    }
    else{
        listDisplay(output);
        cout << endl;
    }
}



int main() {
    cout << "Part One:\n" << endl;

    Node* l1 = nullptr;
    Node* l2 = nullptr;

    l1 = new Node(5);
    listAddTail(l1, 7);
    listAddTail(l1, 9);
    listAddTail(l1, 1);

    cout << "L1: ";
    listDisplay(l1);

    l2 = new Node(6);
    listAddTail(l2, 3);
    listAddTail(l2, 2);

    cout << "L2: ";
    listDisplay(l2);

    cout << "Splicing L2 at target in L1" << endl;
    listSplice(l1, l2, 7);
    cout << "L1: ";
    listDisplay(l1);
    cout << "L2: ";
    listDisplay(l2);
    cout << "=================================\n" << endl;
    cout << "Part two:\n" << endl;
    Node* pt2 = new Node(1);
    listAddTail(pt2, 2);
    listAddTail(pt2, 3);
    listAddTail(pt2, 2);
    listAddTail(pt2, 3);
    listAddTail(pt2, 2);
    listAddTail(pt2, 4);
    listAddTail(pt2, 5);
    listAddTail(pt2, 6);
    cout << "Target:" << endl;
    listDisplay(pt2);

    Node* pt2_1 = new Node(1);

    isSubList(pt2, pt2_1);

    Node* pt2_2 = new Node(3);
    listAddTail(pt2_2, 9);
    isSubList(pt2, pt2_2);

    Node* pt2_3 = new Node(2);
    listAddTail(pt2_3, 3);
    isSubList(pt2, pt2_3);

    Node* pt2_4 = new Node(2);
    listAddTail(pt2_4, 4);
    listAddTail(pt2_4, 5);
    listAddTail(pt2_4, 6);
    isSubList(pt2, pt2_4);

    Node* pt2_5 = new Node(2);
    listAddTail(pt2_5, 3);
    listAddTail(pt2_5, 2);
    listAddTail(pt2_5, 4);
    isSubList(pt2, pt2_5);

    Node* pt2_6 = new Node(5);
    listAddTail(pt2_6, 6);
    listAddTail(pt2_6, 7);
    isSubList(pt2, pt2_6);
//
//    Node* anotherList = nullptr;
//    //anotherList = listAddTail(anotherList, 28);
//    listAddTail(anotherList, 28);
//
//    Node* myOtherList = listCopy(myList);
}
