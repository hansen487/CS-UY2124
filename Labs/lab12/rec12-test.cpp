// Doubly linked list
//  Test code

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class List {
class Node;
friend ostream& operator<<(ostream& os, const List& rhs){
    if (rhs.list_size != 0){
        Node* node = rhs.head -> next;
        while (node != rhs.tail){
            os << node -> data << ' ';
            node = node -> next;
        }
        return os;
    }
    else{cout << "EMPTY";}
}
public:
    class iterator{
    friend List;
    friend bool operator==(const iterator& lhs, const iterator& rhs) {
        return (lhs.position == rhs.position);
    }
    friend bool operator!=(const iterator& lhs, const iterator& rhs){
        return !(lhs == rhs);
    }
    public:
        iterator(Node* p = nullptr) : position(p) {}
        iterator& operator++(){
            if (position -> next != nullptr){
                position = position -> next;
                //return position;
            };
            return *this;
        }
        iterator& operator--(){
            if (position -> previous != nullptr){
                position = position -> previous;
//return position -> previous;
            }
            return *this;
        }
//        bool operator==(const Node* rhs){
//            return &position == &rhs;
//        }
//
//        bool operator!=( const Node* rhs){
//            return &position != &rhs;
//        }
        int operator*() const{return position -> data;}
    private:
        Node* position;
    };

    List()  {head -> next = tail;}
    void push_back(int number){
        if (list_size == 0){
            Node* first = new Node(number, head, tail);
            head->next = first;
            tail->previous = first;
        }
        else{
            Node* second_to_last = tail->previous;
            Node* last = new Node(number, second_to_last, tail);
            second_to_last->next = last;
            tail->previous = last;
        }
        list_size++;
    }

    void pop_back(){
        if (list_size != 0){
            Node* last = tail->previous->previous;
            delete tail->previous;
            tail->previous = last;
            last->next = tail;
        }
        list_size--;
    }

    void push_front(int number){
        Node* second = head -> next;
        Node* first = new Node(number, head, second);
        head -> next = first;
        second -> previous = first;
        list_size++;
    }

    void pop_front(){
        if (list_size != 0){
            Node* second = head -> next -> next;
            delete head -> next;
            second -> previous = head;
            head -> next = second;
            list_size--;
        }
    }

    void clear(){
        if (list_size > 0){
            Node* node = head -> next;
            for (int i = 0; i < list_size; i++){
                Node* node_next = node -> next;
                delete node;
                head -> next = node_next;
                node = head -> next;
            }
            list_size = 0;
            head -> next = tail;
            tail -> previous = head;
        }
    }

    int &operator[](int index){
        if (index >= 0 && index < list_size){
            Node* node = head -> next;
            for (int i = 0; i < index; i++){
                node = node -> next;
            }
            return node -> data;
        }
    }

//    Node* begin(){
//        return head -> next;
//    }

//    Node* end(){
//        return tail -> previous;
//    }

    int front(){
        return head->next->data;
    }

    int back(){
        return tail->previous->data;
    }

    int size(){
        return list_size;
    }

    iterator begin() const{ return iterator(head -> next);}
    iterator end() const{return iterator(tail);}

    iterator insert(const iterator& pos, int num){

    }

private:
    struct Node{
        Node(int data, Node* previous, Node* next): data(data), previous(previous), next(next) {}
        int data;
        Node* previous;
        Node* next;
    };
    Node* head = new Node(0, nullptr, nullptr);
    Node* tail = new Node(0, head, nullptr);
    int list_size = 0;
};

void printListInfo(List& myList) {
        cout << "size: " << myList.size()
             << ", front: " << myList.front()
             << ", back(): " << myList.back()
             << ", list: " << myList << endl;
}

//// Task 8
//void doNothing(List aList) {
//    cout << "In doNothing\n";
//    printListInfo(aList);
//    cout << endl;
//    cout << "Leaving doNothing\n";
//}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;

    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

//    // Task 7
//    cout << "\n------Task Seven------\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    cout << "Erasing the elements in the list, starting from the beginning\n";
//    while (myList.size()) {
//        printListInfo(myList);
//        myList.erase(myList.begin());
//    }
//    // ***Need test for erase other than begin/end***
//    cout << "===================\n";
//
//    // Task 8
//    cout << "\n------Task Eight------\n";
//    cout << "Copy control\n";
//    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
//    myList.clear();
//    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
//    printListInfo(myList);
//    cout << "Calling doNothing(myList)\n";
//    doNothing(myList);
//    cout << "Back from doNothing(myList)\n";
//    printListInfo(myList);
//
//    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
//    List listTwo;
//    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
//    printListInfo(listTwo);
//    cout << "listTwo = myList\n";
//    listTwo = myList;
//    cout << "myList: ";
//    printListInfo(myList);
//    cout << "listTwo: ";
//    printListInfo(listTwo);
//    cout << "===================\n";
}
