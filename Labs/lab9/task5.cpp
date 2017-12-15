#include <iostream>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numofpages) : numberOfPages(numofpages) {}
protected:
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned pages) : PrintedMaterial(pages) {}
protected:
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned pages) : PrintedMaterial(pages) {}
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned pages) : Book(pages) {}
protected:
private:
};

class Novel : public Book {
public:
    Novel(unsigned pages) : Book(pages) {}
protected:
private:
};

// tester/modeler code
int main()
{
	TextBook t(500);
	Novel n(300);
	Magazine m(10);
}
