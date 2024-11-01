#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void displayBoard() {
    cout << "  1   2   3\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << " ---+---+---\n";
    }
    cout << endl;
}

bool makeMove(int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false;
    }
    board[row][col] = player;
    return true;
}

bool win(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

pair<int, int> botMove(char botPlayer, char opponentPlayer){
	if(board[1][1] == ' '){
		a = 1;
		b = 1;
	}
	int a = rand() % 3 +1;
	int b = rand() % 3 +1;
	return {a, b};
}

int main() {
    char currentPlayer = 'X';
    char lastPlayer = 'O';
    int row, col;
	srand(static_cast<unsigned int>(time(0)));
    int moves = 0;
    
    while (true) {
        displayBoard();
        if(currentPlayer == 'X'){
        	cout << "Podaj nr. wierszu i nr. kolumny, gdzie chcesz postawic " << currentPlayer << ": ";
        	cin >> row >> col;
		} else {
			pair<int, int> move = botMove(currentPlayer);
			row = move.first;
			col = move.second;
		}
        
        if (makeMove(row - 1, col - 1, currentPlayer)) {
            if (win(currentPlayer)) {
                displayBoard();
                cout << "Gracz " << currentPlayer << " wygral!" << endl;
                break;
            }
            
            if(!win(currentPlayer) && moves==8){
            	displayBoard();
            	cout << "Remis!" << endl;
            	break;
			}
			moves++;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Niepoprawny ruch! Sprobuj ponownie." << endl;
        }
    }
    return 0;
}
