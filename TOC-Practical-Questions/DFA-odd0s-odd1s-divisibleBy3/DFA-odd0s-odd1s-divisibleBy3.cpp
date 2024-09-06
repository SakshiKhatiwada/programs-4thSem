#include<iostream>
using namespace std;

class DFA
{
    string input;
    char currentState, finalState;

    public:

    void takeInput(){
        cout<<"---------DFA to accept the string that contains odd no. of 1s, odd no. of 0s and is divisible by 3---------------\n";
        cout<<"Enter the string: ";
        cin>>input;

        isAccepted();
    }

    void isAccepted()
    {
        //Total states = 2*2*3 = 12 (o/e,o/e,rem 1/2/3)
        currentState = 'a';
        finalState = 'd';

        for (int i=0; i<input.length(); i++)
        {
            switch (currentState)
        {
            case 'a':
            if(input[i]=='0')
            currentState = 'c';
            else
            currentState= 'f';
            break;
            
            case 'b':
            if(input[i]=='0')
            currentState = 'h';
            else
            currentState= 'i';
            break;
        
            case 'c':
            if(input[i]=='0')
            currentState = 'a';
            else
            currentState= 'h';
            break;


            case 'd':
            if(input[i]=='0')
            currentState = 'b';
            else
            currentState= 'g';
            break;
            
            case 'e':
            if(input[i]=='0')
            currentState = 'k';
            else
            currentState= 'b';
            break;
            
            case 'f':
            if(input[i]=='0')
            currentState = 'l';
            else
            currentState= 'a';
            break;

        case 'g':
            if(input[i]=='0')
            currentState = 'i';
            else
            currentState= 'd';
            break;

        case 'h':
            if(input[i]=='0')
            currentState = 'j';
            else
            currentState= 'c';
            break;

        case 'i':
            if(input[i]=='0')
            currentState = 'g';
            else
            currentState= 'j';
            break;

            
        case 'j':
            if(input[i]=='0')
            currentState = 'h';
            else
            currentState= 'i';
            break;

            
        case 'k':
            if(input[i]=='0')
            currentState = 'e';
            else
            currentState= 'l';
            break;


        case 'l':
            if(input[i]=='0')
            currentState = 'f';
            else
            currentState= 'k';

        }
        }

        cout<<currentState<<"\n";
        if(currentState == finalState)
        {
            cout<<"String is accepted!\n";
        }
        else
        cout<<"String is not accepted.\n";
    }

};

int main(){
    DFA obj1;
    obj1.takeInput();
}