#Hansen Chen
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool alive_or_dead(vector<string> current, int a, int b){
    int alive_neighbors = 0;
    if (current[a-1][b-1] == '*'){
        alive_neighbors++;
    }
    if (current[a-1][b] == '*'){
        alive_neighbors++;
    }
    if (current[a-1][b+1] == '*'){
        alive_neighbors++;
    }
    if (current[a][b-1] == '*'){
        alive_neighbors++;
    }
    if (current[a][b+1] == '*'){
        alive_neighbors++;
    }
    if (current[a+1][b-1] == '*'){
        alive_neighbors++;
    }
    if (current[a+1][b] == '*'){
        alive_neighbors++;
    }
    if (current[a+1][b+1] == '*'){
        alive_neighbors++;
    }
    if (current[a][b] == '*'){
        if (alive_neighbors == 2 || alive_neighbors == 3){
            return true;
        }
        else if (alive_neighbors < 2 || alive_neighbors > 3){
            return false;
        }
    }
    else{
        if (alive_neighbors == 3){
            return true;
        }
    }
}




vector<string> next_generation(vector<string> current, string& format){
    vector<string> next;
    next.push_back(format);
    string newline;
    bool status;
    for (int i = 1; i <= 8; i++){
        newline = "";
        for (int j = 1; j <= 20; j++){
            status = alive_or_dead(current, i, j);
            if (status == true){
                newline += '*';
            }
            else{
                newline += '-';
            }
            }
        next.push_back('-'+newline+'-');
        }
    next.push_back(format);
    return next;
    }

int main(){
    string row;
    ifstream life("life.txt");
    vector<string> game;
    string format;
    life >> row;
    for (int i = 0; i < row.size(); i++){
        format += '-';
    }
    game.push_back(format);
    game.push_back("-" + row + "-");
    while (life >> row){
        game.push_back("-" + row + "-");
    }
    game.push_back(format);
    cout << "Initial world" << endl;
    for (int i = 1; i < game.size() - 1; i++){
        for (int j = 1; j < game[i].size() - 1; j++){
            if (game[i][j] == '-'){
                cout << ' ';
            }
            else{
            cout << game[i][j];
            }
        }
        cout << endl;
    }
    cout << "=============================================="<<endl;
    vector<string> new_generation;
    int generation = 1;
    for (int generation = 1; generation <= 10; generation++){
        new_generation = next_generation(game, format);
        cout << "Generation: "<< generation <<endl;
        for (int i = 1; i < new_generation.size() - 1; i++){
            for (int j = 1; j < new_generation[i].size() - 1; j++){
                if (new_generation[i][j] == '-'){
                    cout << ' ';
                }
                else{
                cout << new_generation[i][j];
                }
            }
        cout<<endl;
        }
    cout << "=============================================="<<endl;
    game = new_generation;
    }
}

