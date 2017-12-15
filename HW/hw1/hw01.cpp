//hw1, Hansen Chen, Caeser Cypher
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//decrypts an individual character literal, letter is the encrypted character and key is the steps needed to rotate
char decrypt_character(char letter, int& key){
    //only runs if it's lowercase
    if (islower(letter)){
        //if char is too close to the beginning, add 26 - key instead
        if (isalpha(letter - key)){
            letter -= key;
        }
        else{
            letter += 26 - key;
        }
    }
    return letter;
}

//uses decrypt function to decrypt an entire string, file is the encrypted string and key is the steps needed to rotate
void decrypt_string(string& file, int& key){
    char decrypted_letter;
    //runs decrypt function on every character in the string
    for (int i = 0; i < file.size(); i++){
        decrypted_letter = decrypt_character(file[i], key);
        file[i] = decrypted_letter;
    }
}


int main()
{
    ifstream encrypted("encrypted.txt");
    int key;
    encrypted >> key;
    string line;
    vector<string> file_line;
    //adds each line of the file into a vector
    while(getline(encrypted, line)){
        file_line.push_back(line);
    }

    string file;
    //reverses the contents of the vector into a string
    for (int i = file_line.size() - 1; i >= 1; i--){
        file += file_line[i] + "\n";
    }
    decrypt_string(file, key);
    cout << file << endl;
}
