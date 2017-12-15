#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

struct Node{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

class Polynomial{
friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
public:
    Polynomial();
    ~Polynomial();
    Polynomial(const Polynomial& rhs);
    Polynomial& operator=(const Polynomial& rhs);
    Polynomial(std::vector<int> numbers);
    Node* findTail();
    void addTail(int num);
    Node* get_expression() const;
    int get_degree() const;
    bool operator!=(const Polynomial& rhs);
    Polynomial& operator+=(const Polynomial& rhs);
    int evaluate(int num);
private:
    Node* expression = new Node(0);
    int degree = 0;

};
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);





#endif // POLYNOMIAL_H_INCLUDED
