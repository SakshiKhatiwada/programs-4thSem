//NFA to check if the string is divisible by 3 or not (It's closely similar to dfa, so without epsilon-transition, it is a DFA) 

#include<iostream>
using namespace std;

class NFA {
    string input;
    char currentState,finalState;

    public:

    void takeInput(){
        cout<<"-----------------NFA to accept the string is divisible by 3-----------------\n";
        cout<<"Enter the string: ";
        cin>>input;
    }

    void isAccepted(){
        //we need 3 states to check
        currentState = 'a'; //initial state
        finalState = 'a';

        for (int i=0; i<input.length(); i++)
        {
            switch(currentState)
        {
            case 'a':
            if(input[i] == '1'){
                currentState = 'b';
            }//for 0, it's the same state
            break;

            case 'b':
            if (input[i] == '0')
            {
                currentState='c';
            }
            else
            {
                currentState='a';
            }
            break;

            case 'c':
            if(input[i] == '0')
            {
                currentState='b';
            }
        }
        }

        if(currentState == finalState)
        {
            cout<<"String is accepted!";
        }
        else
        cout<<"String is not accepted.";
    }

};

int main()
{
    NFA obj1;
    obj1.takeInput();
    obj1.isAccepted();
}