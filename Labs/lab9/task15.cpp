#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
	PrintedMaterial( unsigned numPages )
		: numOfPages(numPages)
	{}
	virtual void displayNumPages()const = 0;
protected:
private:
	unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}
class Magazine : public PrintedMaterial {
public:
	Magazine( unsigned numPages )
		: PrintedMaterial(numPages)
	{}
    void displayNumPages() const{
        PrintedMaterial::displayNumPages();
	}
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book( unsigned numPages )
		: PrintedMaterial(numPages)
	{}
protected:
private:
};

class TextBook : public Book {
public:
	TextBook( unsigned numPages, unsigned numIndxPgs  )
		: Book(numPages),
		  numOfIndexPages(numIndxPgs)
	{}
	void displayNumPages() const
	{
		cout << "Pages: ";
		PrintedMaterial::displayNumPages();
		cout << "Index pages: ";
		cout << numOfIndexPages << endl;
	}
protected:
private:
	unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel( unsigned numPages )
		: Book(numPages)
	{}
	void displayNumPages() const{
        PrintedMaterial::displayNumPages();
	}

protected:
private:
};

void displayNumberOfPages(const PrintedMaterial& p){
    p.displayNumPages();
}

// tester/modeler code
int main()
{
	TextBook t(5430, 234);
	Novel n(213);
	Magazine m(6);

	t.displayNumPages();
	n.displayNumPages();
	m.displayNumPages();

    cout << "Testing pointer: " << endl;
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    pmPtr->displayNumPages();

    cout << endl;
    cout << "Creating vector." << endl;
    vector<PrintedMaterial*> readingthings;
    readingthings.push_back(&t);
    readingthings.push_back(&m);
    readingthings.push_back(&n);
    for (PrintedMaterial* thing: readingthings){
        thing -> displayNumPages();
    }
    	// print some stuff by calling a generic function

}

