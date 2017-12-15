#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

Polynomial::Polynomial() {}

Polynomial::Polynomial(vector<int> numbers){
    reverse(numbers.begin(), numbers.end());
    for (int num: numbers){
        if (degree == 0){
            expression -> data = num;
        }
        else{
            addTail(num);
        }
        degree++;
    }
}

Polynomial::~Polynomial(){
    while (expression != nullptr){
        Node* next = expression -> next;
        delete expression;
        expression = next;
    }
    expression = new Node(0);
}


Polynomial::Polynomial(const Polynomial& rhs){
    Node* right = rhs.expression;
    degree = rhs.degree;
    expression = nullptr;
    while (right != nullptr){
        if (expression == nullptr){
            expression = new Node(right -> data);
        }
        else{
            addTail(right -> data);
        }
        right = right -> next;
    }
}

Polynomial& Polynomial::operator=(const Polynomial& rhs){
    if (*this != rhs){
        while (expression != nullptr){
            Node* next = expression -> next;
            delete expression;
            expression = next;
        }
        Node* right = rhs.expression;
        while (right != nullptr){
            if (expression == nullptr){
                expression = new Node(right -> data);
                degree++;
            }
            else{
                addTail(right -> data);
            }
            right = right -> next;
        }
    }
    return *this;
}

Node* Polynomial::findTail(){
    //cout << "finding tail" << endl;
    Node* p = expression;
    while (p->next != nullptr){
        p = p -> next;
    }
    return p;
}

void Polynomial::addTail(int num){
    Node* tail = findTail();
    //cout << "adding tail" << endl;
    if (tail -> data == 0 && degree == 0){
        tail -> data = num;
    }
    else{
        tail -> next = new Node(num);
    }
    degree++;
    //cout << "degree is now " << degree<<endl;
}

Node* Polynomial::get_expression() const{
    return expression;
}

ostream& operator<<(ostream& os, const Polynomial& rhs){
    Node* p = rhs.expression;
    int deg = 0;
    while (p != nullptr){
        if (deg != 0){
            os << " + " << p -> data << "x^" << deg;
        }
        else{
           os << p -> data;
        }
        p = p->next;
        deg++;
    }
    return os;
}

int Polynomial::get_degree() const{
    return degree;
}

bool Polynomial::operator!=(const Polynomial& rhs){
    if (degree != rhs.degree){
        return true;
    }
    else{
        Node* left = expression;
        Node* right = rhs.expression;
        while (left != nullptr && right != nullptr){
            if (left -> data != right -> data){
                return true;
            }
            left = left -> next;
            right = right -> next;
        }
        return false;
    }
}

Polynomial& Polynomial::operator+=(const Polynomial& rhs){
    Node* p = expression;
    Node* right = rhs.expression;
    while (right != nullptr){
        p -> data = p -> data + right -> data;
        p = p -> next;
        right = right -> next;
    }
    return *this;
}

bool operator==(const Polynomial& lhs, const Polynomial& rhs){
    if (lhs.degree != rhs.degree){
//        cout << "Degrees are " << lhs.degree << rhs.degree << endl;
        return false;
    }
    else{
        Node* left = lhs.expression;
        Node* right = rhs.expression;
        while (left != nullptr && right != nullptr){
            if (left -> data != right -> data){
                return false;
            }
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
}

int Polynomial::evaluate(int num){
    Node* p = expression;
    int sum = 0;
    int deg = 0;
    int term = 0;
    while (p != nullptr){
        sum += lround(pow(num, deg)) * p -> data;
        deg++;
        p = p -> next;
    }
    return sum;
}

Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs){
    Node* larger = nullptr;
    Node* smaller = nullptr;
    if (lhs.get_degree() >= rhs.get_degree()){
        larger = lhs.get_expression();
        smaller = rhs.get_expression();
    }
    else{
        larger = rhs.get_expression();
        smaller = lhs.get_expression();
    }
    Polynomial sum;
    while (smaller != nullptr){
        //cout << smaller -> data + larger -> data << endl;
        sum.addTail(smaller -> data + larger -> data);
        smaller = smaller -> next;
        larger = larger -> next;
    }
//    while (larger != nullptr){
//        sum.addTail(larger -> data);
//        larger = larger -> next;
//    }
    return sum;
}

