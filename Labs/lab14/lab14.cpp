#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <climits>

using namespace std;

struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};


bool task1(int num, int num_ones = 0){
    int ones = num_ones;
    if (num%2 != 0){
        ones++;
        num--;
    }
    if (num != 0){
        task1(num/2, ones);
    }
    else{
        return (ones%2 == 0);
    }
}

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

Node* task2(Node* l1, Node* l2, Node* sum = nullptr){
    if (sum == nullptr){
        //Node* sum = l3;
        sum = new Node(l1 -> data + l2 -> data);
    }
    else{
        listAddTail(sum, l1 -> data + l2 -> data);
    }
    if (l1 -> next != nullptr){
        task2(l1 -> next, l2 -> next, sum);
    }
    return sum;
}

struct TNode {
  TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
  int data;
  TNode *left, *right;
};

int max(TNode* root) {
  int maximum = INT_MIN;

  if (root -> left != nullptr){
    int left_max = max(root -> left);
    if (left_max > maximum){
        maximum = left_max;
    }
  }
  if (root -> right != nullptr){
    int right_max = max(root -> right);
    if (right_max > maximum){
        maximum = right_max;
    }
  }
  if (root -> data > maximum){
    maximum = root -> data;
  }
  return maximum;
}

bool task4(char arr[], int end, int start = 0){
    if (arr[start] != arr[end - 1]){
        return false;
    }
    else{
        if (start + 1 < end){
            return task4(arr, end - 1, start+1);
        }
    }
    return true;
}


int Hanoi(int m, char a, char b, char c, int moves = 0){
    moves++;
    if (m!=1){
        moves = Hanoi(m-1,a,c,b,moves);
        moves = Hanoi(m-1,b,a,c,moves);
    }
    return moves;
}


void f(int n) {
   if (n > 1) {
      cout << 'a';
      f(n/2);
      cout << 'b';
      f(n/2);
   }
   cout << 'c';
}

int main()
{
    cout << boolalpha;
//    cout <<task1(121) << endl;
//    cout <<task1(123123) << endl;
//    Node* l_one = new Node(231);
//    listAddTail(l_one, 8);
//    Node* l_two = new Node(7);
//    listAddTail(l_two, 3);
//    Node* l_three = task2(l_one, l_two);
//    listDisplay(l_three);
//    TNode a(56), b(54), c(44), d(8, &a, &b), e(23, &c), f(32, &d, &e);
//    cout << max(&f) << endl;
//    char s[] = "racecar";
//    cout << task4(s, 7) << endl;
//    char n[] = "noon";
//    cout << task4(n, 4);
//    cout << Hanoi(3, 'A', 'B', 'C');
    f(4);
}
