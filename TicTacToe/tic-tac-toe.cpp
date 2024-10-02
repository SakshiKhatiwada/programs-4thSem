// Tic Tac Toe implementation using Cpp

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#define size 3
using namespace std;

class TicTacToe
{
    char Board[size][size], playerA, playerB, turn = 'X';
    int x, y;

public:
    TicTacToe()
    {
        // Empty Board initialization
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                Board[i][j] = '-';
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
        while(true)
        {
            cout << "Specify the position:\nx: ";
            cin >> x;
            cout << "y: ";
            cin >> y;


            if (x <= size && x > 0 && y <= size && y > 0)
            {
                if (turn == 'X')
                {
                    Board[x - 1][y - 1] = 'O';
                    print();
                    if (whoWon(turn))
                    {
                         cout<<turn;
                        printf("X won!");
                        exit(0);
                    }
                    turn = 'Y';
                }
                else
                {
                    Board[x - 1][y - 1] = 'X';
                    print();
                    if (whoWon(turn))
                    {
                         cout<<turn;
                        printf("X won!");
                        exit(0);
                    }
                    turn = 'X';
                }
            }
            else
            {
                cout << "Invalid input, try again!\n";
            }
            // cout<<"game over or not "<<gameOver<<endl;
        } 

    //     if (turn == 'X')
    //     {
          
    //         cout << "Y won!";
    //     }
    //     else
    //        cout<<turn;
    //         cout << "X won!";
    }

    bool whoWon(char turn)
    {
        // int case1 = 0, case2 = 0, case3 = 0;
        // cout << "checking who wins\n";

        for (int i = 0; i < size; i++)
        {

            if (Board[i][0] == turn && Board[i][1] == turn && Board[i][2] == turn)
                return true;
            if (Board[0][i] == turn && Board[1][i] == turn && Board[2][i] == turn)
                return true;
        }

        // for diagonal
        if (Board[0][0] == turn && Board[1][1] == turn && Board[2][2] == turn)
            return true;
        if (Board[0][2] == turn && Board[1][1] == turn && Board[2][0] == turn)
            return true;


return false;
        //---Previous Logic I tried, didn't work!

        // for (int j = 0; j < size; j++)
        // {
        //     if (Board[i][j] != ' ')
        //     {
        //         if (Board[i][j] == Board[i][i])
        //         {
        //             case1++;
        //         }

        //         if (Board[j][i] == Board[i][i])
        //            {
        //             case2++;
        //         }

        //         if (Board[i][i] == Board[j][j])
        //            {
        //             case3++;
        //         }
        //     }

        // if (case1 == 3 | case2 == 3 | case3 == 3)
        //     {
        //         // cout << "if someone won";
        //         gameOver = true;
        //         return;
        //     }
        //     else
        //     {
        //         // cout << "if no one won";
        //         case1 = case2 = case3 = 0;
        //     }
    }
};

int main()
{
    cout << "--------------Welcome to Tic Tac Toe--------------\n";
    cout << "Player A: X and player B: 0\nSpecify your position as the position of the box as x:1/2/3 y:1/2/3\n";
    cout << "-----------------------------------------------------\n";
    TicTacToe obj;
    obj.input();
    return 0;
}