#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Molecule{
    string name;
    int carbon;
    int hydrogen;
};

vector<Molecule> prase_file(ifstream& file);
void print_sorted(vector<Molecule>& molecules_vector);

int main()
{
    string file_name;
    cout << "What is the file name?" << endl;
    cin >> file_name;
    ifstream ifs (file_name);
    if (!ifs){
        cerr << "Can't read file";
        exit(1);
    }
    vector<Molecule> formulas = create_vector(ifs);
    ifs.close();
    print_sorted(formulas);
}

vector<Molecule> parse_file(ifstream& file) {
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
        //cout << hydrocarbon.name << hydrocarbon.carbon << hydrocarbon.hydrogen << endl;
        file_lines.push_back(hydrocarbon);
        }
    return file_lines;
}

void print_sorted(vector<Molecule>& molecules_vector){
    int carbon_min = 0;
    int hydrogen = 0;
    int previous_min = 0;
    while (molecules_vector.size() > 0){
        for (Molecule molecule : molecules_vector){
            if (carbon_min == 0){
                carbon_min = molecule.carbon;
                hydrogen = molecule.hydrogen;
            }
            else if (molecule.carbon <= carbon_min){
                carbon_min = molecule.carbon;
                hydrogen = molecule.hydrogen;
                }
            }
        cout << 'C' << carbon_min << 'H' << hydrogen<< ' ';
        int count = 0;
        vector<int> indexes;
        for (Molecule molecule : molecules_vector){
            if (molecule.carbon == carbon_min && molecule.hydrogen == hydrogen){
                cout << molecule.name << ' ';
                indexes.push_back(count);
            }
            count++;
        }
        for (int i = indexes.size() - 1; i >= 0; i--){
            int num = indexes[i];
//            cout << num;
//            cout << "deleting " << molecules_vector[num].name<<endl;
            molecules_vector.erase(molecules_vector.begin() + num);
        }
        cout << endl;
        hydrogen = 0;
        carbon_min = 0;
        }
}
