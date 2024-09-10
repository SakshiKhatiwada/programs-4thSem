// Tic Tac Toe implementation using Cpp

#include <iostream>
#include <iomanip>
#define size 3
using namespace std;

class TicTacToe
{
    char Board[size][size], playerA, playerB, turn = 'a';
    bool gameOver = false;
    int x, y, played = 0;

public:
    TicTacToe()
    {
        // Empty Board initialization
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                Board[i][j] = ' ';
        }
        // print();
    }

    void print()
    {
        cout << "\n---------------------" << endl;
        cout << "|" << setw(2) << Board[0][0] << setw(5) << "|" << Board[0][1] << setw(5) << "|" << Board[0][2] << setw(5) << "|" << endl;
        cout << "|" << setw(2) << Board[1][0] << setw(5) << "|" << Board[1][1] << setw(5) << "|" << Board[1][2] << setw(5) << "|" << endl;
        cout << "|" << setw(2) << Board[2][0] << setw(5) << "|" << Board[2][1] << setw(5) << "|" << Board[2][2] << setw(5) << "|" << endl;
        cout << "---------------------" << endl;
    }

    void input()
    {
        do
        {
            cout << "Specify the position:\nx: ";
            cin >> x;
            cout << "y: ";
            cin >> y;

            if (x <= size && x > 0 && y <= size && y > 0)
            {
                if (turn == 'a')
                {
                    Board[x - 1][y - 1] = 'O';
                    if (++played > 2)
                        whoWon();
                    turn = 'b';
                }
                else
                {
                    Board[x - 1][y - 1] = 'X';
                    if (++played > size-1)
                        whoWon();
                    turn = 'a';
                }
            }
            else
            {
                cout << "Invalid input, try again!\n";
            }
            print();
            // cout<<"game over or not "<<gameOver<<endl;
        } while (gameOver == false);

        if (turn == 'a')
        {
            cout << "B won!";
        }
        else
            cout << "A won!";
    }

    void whoWon()
    {
        int case1 = 0, case2 = 0, case3 = 0;
        cout << "checking who wins\n";

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (Board[i][j] != ' ')
                {
                    if (Board[i][j] == Board[i][i])
                    {
                        case1++;
                    }

                    if (Board[j][i] == Board[i][i])
                       {
                        case2++;
                    }

                    if (Board[i][i] == Board[j][j])
                       {
                        case3++;
                    }
                }
            
            if (case1 == 3 | case2 == 3 | case3 == 3)
                {
                    // cout << "if someone won";
                    gameOver = true;
                    return;
                }
                else
                {
                    // cout << "if no one won";
                    case1 = case2 = case3 = 0;
                }

            }
          }
            }
    };

    int main()
    {
        cout << "--------------Welcome to Tic Tac Toe--------------\n";
        cout << "Player A: O and player B: X\nSpecify your position as the position of the box as x:1/2/3 y:1/2/3\n";
        cout << "-----------------------------------------------------\n";
        TicTacToe obj;
        obj.input();
        return 0;
    }