//Hansen Chen minesweeper game
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;

struct Tile{
    bool bomb = false, visible = false;
    int count = 0;
};

struct Row{
    vector<Tile> row;
    void generate_tiles(){
        for (int i = 0; i < 10; i++){
            Tile tile;
            row.push_back(tile);
        }
    }
};

class Minesweeper {
public:
    Minesweeper() {generate_board(board);}

    void display(bool condition){
        if (condition == true){
            for (int i = 1; i < 9; i++){
                for (int j = 1; j < 9; j++){
                    if (board[i].row[j].bomb == false){
                        cout << board[i].row[j].count << ' ';
                        //cout << "F ";
                    }
                    else{
                        cout<< "B ";
                    }
                }
                cout << endl;
            }
        }
    }

    bool done(){
        if (hidden == bombs){
            completion = true;
        }
        return completion;
    }

    bool validRow(int input_row){
        if (input_row >= 1 && input_row <= 8){
            return true;
            }
        else{
            return false;
        }
    }

    bool validCol(int input_col){
        if (input_col >= 1 && input_col <= 8){
            return true;
        }
        else{
            return false;
        }
    }

    bool isVisible(int input_row, int input_col){
        return board[input_row].row[input_col].visible;
    }

    bool play(int input_row, int input_col){
        if (board[input_row].row[input_col].bomb == true){
            completion = true;
            return false;
        }
        else{
            board[input_row].row[input_col].visible = true;
            hidden--;
            if (board[input_row].row[input_col].count == 0){
                for (int i = -1; i < 2; i++){
                    for (int j = -1; j < 2; j++){
                        if (i != 0 || j != 0){
                            board[input_row + i].row[input_col + j].visible = true;
                            hidden--;
                        }
                    }
                }
            }
            for (int i = 1; i < 9; i++){
                for (int j = 1; j < 9; j++){
                    if (board[i].row[j].visible == true){
                        cout << board[i].row[j].count << ' ';
                    }
                    else{
                        cout<< "# ";
                    }
                }
                cout << endl;
            }
            return true;
        }
    }

private:
    vector<Row> board;
    bool completion = false;
    int hidden = 64;
    int bombs = 10;
    void assign_bombs(vector<Row>& rows){
        for (int i = 0; i < bombs; i++){
            int rand_num = rand() % 64;
            div_t divresult = div(rand_num, 8);
            int row = divresult.quot + 1;
            int column = divresult.rem + 1;
            rows[row].row[column].bomb = true;
        }
    }

    void assign_num(vector<Row>& rows){
        for (int row = 1; row <= 8; row++){
            for (int col = 1; col <= 8; col++){
                if (rows[row].row[col].bomb == false){
                    for (int i = -1; i < 2; i++){
                        for (int j = -1; j < 2; j++){
                            if (i != 0 || j != 0){
                                if (rows[row + i].row[col + j].bomb == true){
                                    rows[row].row[col].count++;
                                }
                            }
                        }
                    }
                }
                //cout << rows[row].row[col].count;
            }
            //cout << endl;
        }
    }

    void generate_board(vector<Row>& rows){
        for (int i = 0; i < 10; i++){
            Row row;
            row.generate_tiles();
            rows.push_back(row);
        }
        assign_bombs(rows);
        assign_num(rows);
    }

};

int main() {
    Minesweeper sweeper;
    // Continue until the only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display the board without bombs

        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r,c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        // Set selected square to be visible. May effect other cells.
        if (!sweeper.play(row_sel,col_sel)) {
            cout << "BOOM!!!\n";
            sweeper.display(true);
            // We're done! Should consider ending more "cleanly",
            // eg. Ask user to play another game.
            exit(0);
        }
    }
    // Ah! All invisible cells are bombs, so you won!
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown
}




