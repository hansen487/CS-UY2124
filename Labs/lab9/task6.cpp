#include <iostream>
using namespace std;

class PrintedMaterial {
public:
    void displayNumPages() const { cout << numberOfPages; }
protected:
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
protected:
private:
};

class Book : public PrintedMaterial {
public:
protected:
private:
};

class TextBook : public Book {
public:
protected:
private:
};

class Novel : public Book {
public:
protected:
private:
};

// tester/modeler code
int main()
{
	TextBook t;
	Novel n;
	Magazine m;

	t.displayNumPages();
	n.displayNumPages();
}
