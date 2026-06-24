

#include <iostream>
#include <array>
#include <string>
#include <limits>

using namespace std;

// Create a 3x3 board, positions labeled 1-9 as placeholders
array<string, 9> createBoard()
{
    array<string, 9> board;
    for (int i = 0; i < 9; i++)
    {
        board[i] = to_string(i + 1);
    }
    return board;
}

// Display the current state of the board
void displayBoard(const array<string, 9> &board)
{
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---+---+---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n";
    cout << "\n";
}

// Prompt the current player for a valid move and return the index (0-8)
int getMove(const string &player, const array<string, 9> &board)
{
    int position;

    while (true)
    {
        cout << "Player " << player << ", enter your move (1-9): ";

        if (!(cin >> position))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }

        if (position < 1 || position > 9)
        {
            cout << "Invalid move. Choose a number between 1 and 9.\n";
            continue;
        }

        int index = position - 1;
        if (board[index] == "X" || board[index] == "O")
        {
            cout << "That cell is already taken. Choose another one.\n";
            continue;
        }

        return index;
    }
}

// Place the player's symbol on the board
void updateBoard(array<string, 9> &board, int index, const string &player)
{
    board[index] = player;
}

// Check if the given player has won
bool checkWin(const array<string, 9> &board, const string &player)
{
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // columns
        {0, 4, 8},
        {2, 4, 6} // diagonals
    };

    for (auto &combo : winCombos)
    {
        if (board[combo[0]] == player &&
            board[combo[1]] == player &&
            board[combo[2]] == player)
        {
            return true;
        }
    }
    return false;
}

// Check if the board is full (draw)
bool checkDraw(const array<string, 9> &board)
{
    for (const auto &cell : board)
    {
        if (cell != "X" && cell != "O")
        {
            return false;
        }
    }
    return true;
}

// Play a single round of Tic-Tac-Toe
void playGame()
{
    array<string, 9> board = createBoard();
    string currentPlayer = "X";

    displayBoard(board);

    while (true)
    {
        int index = getMove(currentPlayer, board);
        updateBoard(board, index, currentPlayer);
        displayBoard(board);

        if (checkWin(board, currentPlayer))
        {
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            break;
        }

        if (checkDraw(board))
        {
            cout << "It's a draw! Good game.\n";
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == "X") ? "O" : "X";
    }
}

int main()
{
    cout << "========================================\n";
    cout << "       WELCOME TO TIC-TAC-TOE\n";
    cout << "========================================\n";
    cout << "Players take turns entering a number (1-9)\n";
    cout << "corresponding to the board position below:\n\n";
    cout << " 1 | 2 | 3 \n";
    cout << "---+---+---\n";
    cout << " 4 | 5 | 6 \n";
    cout << "---+---+---\n";
    cout << " 7 | 8 | 9 \n";

    while (true)
    {
        playGame();

        cout << "\nPlay again? (y/n): ";
        string again;
        cin >> again;

        if (again != "y" && again != "Y")
        {
            cout << "Thanks for playing! Goodbye.\n";
            break;
        }
    }

    return 0;
}