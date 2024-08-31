// implementing DFA i.e. Deterministic Finite Automata
// 1) To accept a string ending with 3 consecutive 0s we need 3 states

#include <iostream>
using namespace std;
// #define maxLetters 10
#define maxStates 4

int main()
{
    string inputLetters;
    char states[maxStates] = {'a', 'b', 'c', 'd'}, currentState, initialState = 'a', finalState = 'd';

    // taking inputs
    cout<<"----------------------------------------------\n";
    cout<<"DFA to check if the given string ends with 3 consecutive 0s or not: \n";
    cout<<"----------------------------------------------\n";
    cout << "Enter the input letters(0 or 1): ";
    cin >> inputLetters;

    currentState = initialState;

    // cout<<inputLetters.length(); ->it works
    for (int i = 0; i < inputLetters.length(); i++)
    {
        // for state 1
        if (currentState == states[0])
        {
            if (inputLetters[i] == '0')
            {
                currentState = 'b';
            }
            else
            {
                currentState = 'a';
            }
            // else it will stay as it is
        }

        // for state 2
        if (currentState == states[1])
        {
            if (inputLetters[i] == '0')
            {
                currentState = 'c';
            }
            else
            {
                currentState = 'a';
            }
        }

        // for state 3
        if (currentState == states[2])
        {
            if (inputLetters[i] == '0')
            {
                currentState = 'd';
            }
            else
            {
                currentState = 'a';
            }
        }

        // for state 4
        if (currentState == states[3])
        {
            if (inputLetters[i] == '1')
            {
                currentState = 'a';
            }
            // for 0, it stays there
        }
    }

    // printing the output
    cout << "Currently in state: " << currentState << "\n";
    if (currentState == finalState)
    {
        cout << "The string is accepted.\n";
    }
    else
    {
        cout << "The string is not accepted.\n";
    }

    return 0;
}