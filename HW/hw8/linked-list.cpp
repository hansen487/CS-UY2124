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

Node* listCopyV2(Node* hp) {
    if (hp == nullptr) return nullptr;
    return new Node(hp->data, listCopyv2(hp->next));
}

void listClear(Node*& hp) {
    if (hp == nullptr) return;
    while (hp->next != nullptr) {
        listRemoveAfter(hp);
    }
    delete hp;
    hp = nullptr;
}



int main() {
    Node* myList = nullptr;

    myList = new Node(17);
    //*myList.next = new Node(28);
    //(*myList).next = new Node(28);
    myList->next = new Node(28);
    listDisplay(myList);

    Node* anotherList = nullptr;
    //anotherList = listAddTail(anotherList, 28);
    listAddTail(anotherList, 28);

    Node* myOtherList = listCopy(myList);
}
