// Program to implement a DFA to accept the string having 3-consecutive 1's as a substring:

#include <iostream>
using namespace std;

class DFA
{
    string input="";
    char currentState,finalState;

    public:

    void takeInput()
    {
        cout<<"-------------DFA to accept strings with 3 consecutive 1's as a substring---------------\n";
        cout<<"Enter the string you want to check: ";
        cin>>input;
    }

    void consecutive1s(){
        //for this, we need 4 states (let a,b,c,d)
        currentState='a';   //initial state
        finalState='d';

        for(int i=0; i<input.length(); i++)
        {
            switch(currentState){

                case 'a':
                if(input[i] == '1')
                currentState = 'b';
                break;
                
                case 'b':
                if(input[i] == '0')
                currentState = 'a';
                else
                currentState='c';
                break;

                case 'c':
                if(input[i]=='0')
                currentState = 'a';
                else
                currentState = 'd';
                break;
        
                //for d, it will stay in that current state

            }
        }

        if(currentState == finalState){
            cout<<"The string is accepted!\n";
        }
        else
        cout<<"The string is not accepted.\n";

    }
};

int main()
{

    DFA obj1,obj2;
    obj1.takeInput();
    obj1.consecutive1s();   

    obj2.takeInput();
    obj2.consecutive1s();
  

    return 0;
}