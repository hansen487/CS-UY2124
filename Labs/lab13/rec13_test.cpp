// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

void print_list_iter(const list<int>& List) {
    for (list<int>::const_iterator Liter = List.begin(); Liter != List.end(); Liter++){cout<< *Liter << ' ';}
    cout << endl;
}

void print_list_rfor(const list<int>& List){
    for (int n: List){cout << n << ' ';}
    cout << endl;
}

void print_list_auto(const list<int>& List){
    for (auto it = List.begin(); it != List.end(); ++++it){cout << *it << ' ';}
    cout << endl;
}

list<int>::const_iterator list_search(const list<int>& List, int num){
    for (list<int>::const_iterator Liter = List.begin(); Liter!= List.end(); Liter++){
        if (num == *Liter){return Liter;}
    }
    return List.end();
}

list<int>::const_iterator list_search_auto(const list<int>& List, int num){
    for (auto Liter = List.begin(); Liter!= List.end(); Liter++){
        if (num == *Liter){return Liter;}
    }
    return List.end();
}

bool even(int num){
    if (num%2==0) {return true;}
    else{return false;}
}

class find_even{
public:
    bool operator()(int num) const{
        if (num%2==0){return true;}
        else{return false;}
    }
};

template <typename T>
T ourFind(T begin, T end, int num){
    cout << "in template" << endl;
    for (T it = begin; it != end; it++){
        if (num == *it) {
            cout <<"found" << endl;
            return it;
        }
    }
    return end;
}



int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(234);
    vec1.push_back(6);
    vec1.push_back(512);
    for (int n: vec1){
        cout << n << ' ';
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> l1(vec1.begin(), vec1.end());
    for (int n: l1){
        cout << n << ' ';
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(vec1.begin(), vec1.end());
    for (int n: vec1){cout << n << ' ';}
    cout << endl;
    for (int n: l1){cout << n << ' ';}
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (int i = 0; i < vec1.size(); i++){
        if (i%2 == 0){cout << vec1[i] << ' ';}
    }
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
//    try{
//        for (int i = 0; i < l1.size(); i++){
//            if (i%2 == 0){cout << l1[i] << ' ';}
//        }
//    }
//    else{cout<<"failed";}
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    vector<int>::iterator veciter;
    for (veciter = vec1.begin(); veciter != vec1.end(); veciter++){
        cout << *veciter << ' ';
        veciter++;
    }

    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.

    cout << "Task 7:\n";
    list<int>::iterator liter;
    for (liter = l1.begin(); liter != l1.end(); liter++){
        cout << *liter << ' ';
        liter++;
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    l1.sort();
    for (int n: l1){cout << n << ' ';}

    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";

    print_list_iter(l1);
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    print_list_rfor(l1);
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    print_list_auto(l1);
    cout << "=======\n";


    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    cout << *list_search(l1, 512) << endl;
    list<int>::const_iterator p2 = list_search(l1, 2);
    if (p2 == l1.end()){cout << "Didn't find." << endl;}
    else{cout << *p2 << endl;}
    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    cout << *list_search(l1, 234) << endl;
    auto p3 = list_search(l1, 2);
    if (p2 == l1.end()){cout << "Didn't find." << endl;}
    else{cout << *p2 << endl;}
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    cout << *ourFind(l1.begin(), l1.end(), 1) << endl;
    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    auto it = find_if(l1.begin(), l1.end(), even);
    if (it != l1.end()){cout << *it << endl;}
    else{cout << "Not found." << endl;}
    cout << "=======\n";

    // 16a. Functor
    cout << "Task 16a:\n";
    find_even num;
    cout << boolalpha;
    cout << num(2) << endl;
    cout << "=======\n";

    // 16b. Lambda
    cout << "Task 16b:\n";
    bool is_even = [](int num) -> bool{num&2==0;} (6634234);
    cout << is_even << endl;
    cout << "=======\n";

    // 17. Generic algorithms: copy to an array
    cout << "Task 17:\n";
    int arr[4];
    copy(vec1.begin(), vec1.end(), arr);
    for (int n: arr){
        cout << n << ' ';
    }
    cout << endl;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 18. Implement find as a function for lists
    cout << "Task 18:\n";
    cout <<*ourFind(vec1.begin(), vec1.end(), 234) << endl;
    cout << "=======\n";

    // 19. Implement find as a templated function
    cout << "Task 19:\n";
    cout <<*ourFind(vec1.begin(), vec1.end(), 234) << endl;
    cout << "=======\n";

    //
    // Associative collections
    //

    // 20. Using a vector of strings, print a line showing
    cout << "Task 20:\n";
    ifstream ifs("pooh-nopunc.txt");
    string word;
    vector<string> words;
    while (ifs>>word){
        if (find(words.begin(), words.end(), word) == words.end()){
            words.push_back(word);
        }
    }
    cout << "The size of the vector is: " << words.size() << endl;
    cout << "The words are:" << endl;
    for (string word: words){
        cout << word << ' ';
    }
    ifs.close();
    cout << "\n=======\n";

    // 21. Repeating previous step, but using the set
    cout << "Task 21:\n";
    set<string> words_set;
    ifstream ifs_2("pooh-nopunc.txt");
    while (ifs_2>>word){
        words_set.insert(word);
    }
    cout << "The size of the vector is: " << words_set.size() << endl;
    cout << "The words are:" << endl;
    for (string word: words_set){
        cout << word << ' ';
    }
    ifs_2.close();
    cout << "=======\n";

    // 22. Word co-occurence using map
    cout << "Task 22:\n";
    map<string, vector<int>> wordmap;
    ifstream mapfile("pooh-nopunc.txt");
    int count = 0;
    while (mapfile>>word){
        wordmap[word].push_back(count);
        count++;
    }
    for (auto const& word: wordmap){
        cout << word.first << ": ";
        for (auto thing: word.second){
            cout << thing << ' ';
        }
        cout << endl;
    }
    cout << "=======\n";
}
