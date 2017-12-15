#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Molecule{
    string name;
    int carbon;
    int hydrogen;
};

vector<Molecule> create_vector(ifstream& file) {
    vector<Molecule> file_lines;
    string name;
    char letter;
    int number;
    Molecule hydrocarbon;
    while(file >> name){
        hydrocarbon.name = name;
        file >> letter;
        file >> number;
        hydrocarbon.carbon = number;
        file >> letter;
        file >> number;
        hydrocarbon.hydrogen = number;
        cout << hydrocarbon.name << hydrocarbon.carbon << hydrocarbon.hydrogen << endl;
        file_lines.push_back(hydrocarbon);
        }
    return file_lines;
}

int main()
{
    string file_name;
    cout << "What is the file name?" << endl;
    cin >> file_name;
    ifstream ifs(file_name);
    if (!ifs){
        cerr << "Can't read file";
        exit(1);
    }
    vector<Molecule> formulas = create_vector(ifs);
    ifs.close();

}
